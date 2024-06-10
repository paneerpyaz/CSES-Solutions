#include <algorithm>
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
vector<int> segtree;
void build(vector<int> &a,int start,int end,int index){
  if(start == end){
    segtree[index] = a[start];
    return;
  }
  int mid = (start + end)/2;
  int left = 2*index;
  int right = 2*index + 1;
  build(a,start,mid,left);
  build(a,mid+1,end,right);
  segtree[index] = max(segtree[left],segtree[right]);
}
int query(int start,int end,int index,int l,int r){
  if(start >= l && r >= end){
    return segtree[index];
  }
  if(l > end || r < start){
    return -1e17;
  }
  int mid = (start + end) / 2;
  int leftans = query(start,mid,2*index,l,r);
  int rightans = query(mid+1,end,2*index+1,l,r);
  return max(leftans, rightans);
}

void solve(){
  int n,a,b;
  cin>>n>>a>>b;
  vector<int>c(n);
  for(int i=0;i<n;i++)cin>>c[i];
  segtree.resize(4*n);
  vector<int>pref(n+1,0);
  pref[0]=c[0];
  for(int i=1;i<n;i++){
    pref[i]=pref[i-1]+c[i];
  }
  build(pref,0,n-1,1);
  int window=0;
  for(int i=0;i<a;i++){
    window+=c[i];
  }
  int ans = window;
  for(int i=a;i<n;i++){
    ans=max(ans,pref[i]-pref[i-a]);
  }
  int extra = b-a;
  ans = max(ans,query(0,n-1,1,a,b-1));
  for(int i=a+1;i<n;i++){
    int num = query(0,n-1,1,i,min(n-1,i+extra))-pref[i-a];
    ans=max(ans,num);
  }
  cout<<ans;
} 

signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int tt = 1;
  while(tt--){
    solve();
  }
  return 0;
}
