
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

#define int long long
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
{                                                              \
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
  vector<vector<int>>g(n+1);
  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    g[v].push_back(u);
  }
  vector<int>color(n+1,0);
  vector<int>ans;
  //0 white 1 grey 2 black
  std::function<bool(int,vector<int>&)>dfs=[&](int v,vector<int>&ans)->bool{
    color[v]=1;
    for(auto &u:g[v]){
      ans.push_back(u);
      if(color[u]==1){
        return true;
      }
      if(color[u]==0 && dfs(u,ans)){
        return true;
      }
      ans.pop_back();
    }
    color[v]=2;
    return false;
  };
  for(int i=1;i<=n;i++){
    vector<int>ans;
    vector<int>res;
    if(!color[i] && dfs(i,ans)){
      int last = ans.back();
      reverse(all(ans));
      if(ans.back()!=last) ans.push_back(last);
      debug(ans);
      debug(last);
      int z=ans.size();
      for(int i=1;i<z;i++){
        res.push_back(ans[i]);
        if(ans[i]==last) break;
      }
      cout<<res.size()+1<< endl;
      cout<<last<<" ";
      for(auto &x : res){
        cout<<x<<" ";
      }
      return;
    }
  }
  cout<<"IMPOSSIBLE\n";
} 

signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int tt = 1;
  while(tt--){
    solve();
  }
  return 0;
}


