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
 
void solve(){
  int n,m;
  cin >> n >> m;
  vector<vector<pair<int,int>>>g(n+1);
  for(int i=0;i<m;i++){
    int u,v,w;
    cin >> u >> v >> w;
    g[u].push_back({v,w});
  }
  set<vector<int>>s;
  vector<vector<int>>dp(n+1,vector<int>(2,1e16));
  dp[1][0] = 0;
  dp[1][1] = 1;
  s.insert({0,1,1});
  vector<int>par(n+1);
  vector<bool>vis(n+1,false);
  while(!s.empty()){
    vector<int>p = *s.begin();
    int d = p[0];
    int v = p[1];
    int c = p[2];
    s.erase(s.begin());
    if(dp[v][c] < d) continue;
    for(auto u : g[v]){
      int wt = u.second;
      int child = u.first;
      if(c){
        if(dp[child][1] > d + wt){
          dp[child][1] = d+wt;
          s.insert({dp[child][1],child,1});
        }
        if(dp[child][0] > d + wt/2){
          dp[child][0] = d+wt/2;
          s.insert({dp[child][0],child,0});
        }
      }
      else{
        if(dp[child][0] > d + wt){
          dp[child][0] = d+wt;
          s.insert({dp[child][0],child,0});
        }
      }
    }
  }
  cout<<min(dp[n][1],dp[n][0]);
} 
 
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int tt = 1;
  while(tt--){
    solve();
  }
  return 0;
}
