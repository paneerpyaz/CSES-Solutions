#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define int long long
 
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
 
const int MOD1 = 998244353;
const int MOD2 = 1e9+7;
 
#ifndef ONLINE_JUDGE
#define DEBUG
#endif
#define SFINAE(x, ...)          \
 template <class, class = void> \
 struct x : std::false_type {}; \
 template <class T>             \
 struct x<T, std::void_t<__VA_ARGS__>> : std::true_type {}
SFINAE(DefaultIO, decltype(std::cout << std::declval<T &>())); SFINAE(IsTuple, typename std::tuple_size<T>::type); SFINAE(Iterable, decltype(std::begin(std::declval<T>()))); template <class T> constexpr char Space(const T &) { return (Iterable<T>::value or IsTuple<T>::value) ? '\n' : ' '; } template <auto &os> struct Writer { template <class T> void Impl(T const &t) const { if constexpr (DefaultIO<T>::value) os << t; else if constexpr (Iterable<T>::value) { int i = 0; for (auto &&x : t) ((i++) ? (os << Space(x), Impl(x)) : Impl(x)); } else if constexpr (IsTuple<T>::value) std::apply( [this](auto const &... args) { int i = 0; (((i++) ? (os << ' ', Impl(args)) : Impl(args)), ...); }, t); else static_assert(IsTuple<T>::value, "No matching type for print"); } template <class F, class... Ts> auto &operator()(F const &f, Ts const &... ts) const { return Impl(f), ((os << ' ', Impl(ts)), ...), os << '\n', *this; } };
#ifdef DEBUG
#define debug(args...)                                          \
{                                                               \
  std::string _s = #args;                                       \
  std::replace(_s.begin(), _s.end(), ',', ' ');                 \
  std::stringstream _ss(_s);                                    \
  std::istream_iterator<std::string> _it(_ss);                  \
  std::cerr << "Line " << __LINE__ << "\n";                     \
  err(_it, args);                                               \
  std::cerr << "-------------------------------------------\n"; \
}
void err(std::istream_iterator<std::string> it) { std::ignore = it; } template <typename T, typename... Args> void err(std::istream_iterator<std::string> it, T a, Args... args) { std::cerr << *it << " = "; Writer<std::cerr>{}(a); err(++it, args...); }
#define ASSERT(...) \
 if (not(__VA_ARGS__)) throw runtime_error(#__VA_ARGS__)
#else
#define debug(...) 0
#define ASSERT(...) 0
#endif
 
void solve(){
  int n,m;
  cin>>n>>m;
  auto recc = [&](int i,int mask,vector<int>&ans,int new_mask,auto &&recc)->void{
    if(i>=n){
      ans.push_back(new_mask);
      return;
    }
    if(mask & (1<<i)){
      recc(i+1,mask,ans,new_mask,recc);
    }
    else{
      //1 x 2
      if(i+1<n && (!(mask & (1<<(i+1))))){
        recc(i+2,mask,ans,new_mask,recc);
      }
      //2 x 1
      recc(i+1,mask,ans,(new_mask|(1<<i)),recc);
    }
  };
  vector<vector<int>>cache(m+1,vector<int>(1<<n,-1));
  auto dp = [&](int j,int mask,auto &&dp)->int{
    if(j==m){
      return (mask==0 ? 1 : 0);
    }
    if(cache[j][mask]!=-1)return cache[j][mask];
    int ans=0;
    vector<int>hello;
    recc(0,mask,hello,0,recc);
    for(auto &msk : hello){
      ans += dp(j+1,msk,dp);
      ans %= 1000000007;
    }
    return cache[j][mask]= ans;
  };
  cout<<dp(0,0,dp);
} 
 
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt = 1;
  // cin>>tt;
  while(tt--){
    solve();
  }
  return 0;
}