#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <queue>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
#define int long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
 
const int MOD1 = 998244353;
const int MOD2 = 1e9+7;
 
void solve(){
  int n,m;
  cin >> n >> m;
  vector<vector<pair<int,int>>>g(n+1);
  for(int i = 0 ; i < m ; i++){
    int u,v,w;
    cin >> u >> v >> w;
    g[u].push_back({v,w});
  }
  int src = 1;
  vector<bool>vis(n+1,false);
  set<pair<int,int>>s;
  s.insert({0,src});
  vector<int>dis(n+1,1e17);
  dis[src] = 0;
  while(!s.empty()){
    pair<int,int>p = *s.begin();
    int d = p.first;
    int v = p.second;
    s.erase(s.begin());
    if(vis[v]) continue;
    vis[v] = true;
    for(auto u : g[v]){
      int child = u.first;
      int wt = u.second;
      if(dis[child] > wt + d){
        dis[child] = wt + d;
        s.insert({wt+d,child});
      }
    }
  }
  for(int i = 1 ; i <= n ; i++){
    cout << dis[i] << " ";
  }
  cout << endl;
} 
 
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int tt = 1;
  // cin >> tt;
  while(tt--){
    solve();
  }
  return 0;
}