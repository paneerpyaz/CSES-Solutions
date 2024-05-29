#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
#define int long long
#define vpll vector<pair<int,int>>
#define pll pair<int,int>
#define vb vector<bool>
#define vll vector<int>
#define vvll vector<vector<int>>
#define ld long double
#define F first
#define S second
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define inp(v) for(auto &it:v)cin>>it;
#define rep(i,k,n) for(int i = k ; i < n ; i++)
#define see(v) for(auto &it:v){cout<<it<<" ";}cout<<endl;
#define pr(v) for(auto &it:v){cout<<it.F<<" "<<it.S<<endl;}
#define CEIL(x,y)  (int)ceil(1.0 * x/y)
 
const int MOD1 = 998244353;
const int MOD2 = 1e9+7;
 
//It is for DAG, gives a linear order where u appears before v if u point v
void dfs_topo(int v,stack<int>&stk,vvll &adj,vb &vis){
  vis[v] = true;
  for(auto u : adj[v]){
    if(!vis[u]){
      dfs_topo(u,stk,adj,vis);
    }
  }
  stk.push(v);
}
vll topo(int n,vb &vis,vvll &adj){
  stack<int>stk;
  rep(i,1,n+1){
    if(!vis[i]){
      dfs_topo(i,stk,adj,vis);
    }
  }
  vll ans;
  while(!stk.empty()){
    ans.pb(stk.top());
    stk.pop();
  }
  return ans;
}
 
void samadhaan(){
  int n,m;
  vpll conditions;
  cin >> n >> m;
  vvll g(n+1);
  rep(i,0,m){
    int u,v;
    cin >> u >> v;
    conditions.pb({u,v});
    g[u].pb(v);
  }
  vb vis(n+1,false);
  vll ans = topo(n,vis,g);
  vll pos(n+1);
  rep(i,0,n){
    pos[ans[i]] = i;
  }
  rep(i,0,m){
    if(pos[conditions[i].F] >pos[conditions[i].S]){
      cout << "IMPOSSIBLE" << endl;
      return;
    }
  }
  see(ans);
} 
 
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int lim = 1;
  // cin >> lim;
  while(lim-->0){
    samadhaan();
  }
  return 0;
}
 
