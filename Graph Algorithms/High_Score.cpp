#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <queue>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

#define int long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

const int MOD1 = 998244353;
const int MOD2 = 1e9+7;

class DisjointSet{
  vector<int>rank,parent,size;
  public:
    DisjointSet(int n){
      rank.resize(n+1,0);
      parent.resize(n+1,0);
      size.resize(n+1,1);
      for(int i=1;i<=n;i++){
        parent[i]=i;
      }
    }
    int find(int node){
      if(node == parent[node]){
        return node;
      }
      return parent[node]=find(parent[node]);
    }
    void unionByrank(int u,int v){
      u = find(u);
      v = find(v);
      if(u == v){
        return;
      }
      if(rank[u] < rank[v]){
        swap(u,v);
      }
      parent[v]=u;
      if(rank[u] == rank[v]){
        rank[u]++;
      }
    }
    void unionBysize(int u,int v){
      u = find(u);
      v = find(v);
      if(u == v){
        return;
      }
      if(size[u]>size[v]){
        swap(u,v);
      }
      size[v] += size[u];
      parent[u]=v;
    }
};
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
  vector<vector<pair<int,int>>>g(n+1);
  vector<vector<pair<int,int>>>revg(n+1);
  vector<vector<int>>edge;
  for(int i=0;i<m;i++){
    int u,v,w;
    cin>>u>>v>>w;
    w *= -1;
    edge.push_back({u,v,w});
    g[u].push_back({v,w});
    revg[v].push_back({u,w});
  }
  vector<int>dis(n+1,1e17);
  vector<int>p(n+1,-1);
  dis[1]=0;
  int x;
  for(int i=0;i<n;i++){
    x=-1;
    for(auto &i: edge){
      int u=i[0];
      int v=i[1];
      int w=i[2];
      if(dis[u]<1e17 && dis[v]>dis[u]+w){
        dis[v]=dis[u]+w;
        x=v;
      }
    }
  }
  if(x==-1){
    cout<<-dis[n];
  }
  else{
    debug(x);
    auto bfs =[&](int src,vector<vector<pair<int,int>>>g){
      queue<int>q;
      vector<int>vis(n+1,0);
      vector<int>dep(n+1,-1);
      dep[src]=0;
      q.push(src);
      vis[src]=1;
      while(!q.empty()){
        int v=q.front();
        q.pop();
        for(auto &u:g[v]){
          int child=u.first;
          if(!vis[child]){
            vis[child]=1;
            q.push(child);
            dep[child]=dep[v]+1;
          }
        }
      }
      return dep;
    };
    vector<int>d1=bfs(1,g);
    vector<int>d2=bfs(n,revg);
    for(int i=0;i<n;i++){
      for(auto &i: edge){
        int u=i[0];
        int v=i[1];
        int w=i[2];
        if(dis[u]<1e17 && dis[v]>dis[u]+w){
          dis[v]=dis[u]+w;
          if(d1[v] != -1 && d2[v] != -1){
            cout<<-1<<endl;;
            return;
          }
        }
      }
    }
    cout<<-dis[n]<<endl;
  }
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
