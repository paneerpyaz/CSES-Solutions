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

void solve(){
  int n,m;
  cin>>n>>m;
  vector<vector<int>>g(n+1);
  vector<vector<int>>revg(n+1);
  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    g[u].push_back(v);
    revg[v].push_back(u);
  }
  vector<int>entry;
  vector<bool>vis(n+1,false);
  function<void(int)>dfs=[&](int v){
    vis[v]=true;
    for(auto &u:g[v]){
      if(!vis[u]){
        dfs(u);
      }
    }
    entry.push_back(v);
  };
  dfs(1);
  reverse(all(entry));
  vis.assign(n+1,false);
  
  auto SCC=[&](int v,auto &&SCC)->void{
    vis[v]=true;
    for(auto &u:revg[v]){
      if(!vis[u]){
        SCC(u,SCC);
      }
    }
  };
  
  int scc=0;
  int paneer,pyaz;
  bool f=true;
  for(int i=0;i<n;i++){
    int node=entry[i];
    if(!vis[node]){
      scc++;
      SCC(node,SCC);
      if(f) pyaz=node;
      else {paneer=node;break;}
      f=!f;
    }
  }
  if(scc==1){
    cout<<"YES\n";
  }
  else{
    cout<<"NO\n";
    cout<<paneer<<" "<<pyaz;
  }
} 

signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int tt = 1;
  while(tt--){
    solve();
  }
  return 0;
}
