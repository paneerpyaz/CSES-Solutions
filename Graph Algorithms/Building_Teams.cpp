#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
#define int long long
#define vpll vector<pair<int,int>>
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
 
int n;
vvll adj;
vector<bool>vis;
vll color;
 
bool bipap(int v){
  queue<int>q;
  q.push(v);
  vis[v] = true;
  color[v] = 0;
  while(!q.empty()){
    int v = q.front();
    q.pop();
    for(auto u : adj[v]){
      vis[u] = true;
      if(color[u] == -1){
        color[u] = (1^color[v]);
        q.push(u);
      }
      else if(color[u] == color[v]){
        return false;
      }
    }
  }
  return true;
}
 
void samadhaan(){
  int n,m;
  cin >> n >> m;
  adj.resize(n+1);
  color.resize(n+1,-1);
  vis.resize(n+1,false);
 
  rep(i,0,m){
    int u,v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  rep(i,1,n+1){
    if(!vis[i]){
      if(!bipap(i)){
        cout << "IMPOSSIBLE" << endl;
        return;
      }
    }
  }
  rep(i,1,n+1){
    cout << color[i]+1 << " ";
  }
  cout << endl;
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
