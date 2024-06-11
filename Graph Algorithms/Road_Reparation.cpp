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

void solve(){
  int n,m; 
  cin>>n>>m;
  vector<vector<pair<int,int>>>g(n+1);
  for(int i=0;i<m;i++){
    int u,v,w;
    cin>>u>>v>>w;
    g[u].push_back({v,w});
    g[v].push_back({u,w});
  }
  vector<int>vis(n+1,0);
  int sum=0;
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
  pq.push({0,1});
  while(pq.size()){
    int node=pq.top().second;
    int wt=pq.top().first;
    pq.pop();
    if(vis[node])continue;
    vis[node]=1;
    sum += wt;
    for(auto &child : g[node]){
      if(!vis[child.first]){
        pq.push({child.second,child.first});
      }
    }
  }
  cout<<((accumulate(all(vis),0)==n) ? to_string(sum) : "IMPOSSIBLE");
} 

signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt = 1;
  while(tt--){
    solve();
  }
  return 0;
}
