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
  vector<vector<int>>g;
  vector<int>par(n+1,0);
  for(int i = 0 ; i < m ; i++){
    int u,v,w;
    cin >> u >> v >> w;
    g.push_back({u,v,w});
  }
  vector<int>dis(n+1,1e17);
  dis[1] = 0;
  for(int i = 0 ; i < n-1 ; ++i){
    for(auto &it : g){
      int u = it[0];
      int v = it[1];
      int w = it[2];
      if(dis[v] > dis[u] + w){
        dis[v] = dis[u] + w;
        par[v] = u;
      }
    }
  }
  bool f = false;
  int node =-1;
  for(auto it : g) {
		int u = it[0];
		int v = it[1];
		int wt = it[2];
		if (dis[u] + wt < dis[v]) {
        node = u;
        par[v] = u;
			break;
		}
	}
  if(node==-1){
    cout<<"NO\n";
  }
  else{
    cout<<"YES\n";
    for(int i = 0; i < n; ++i) node = par[node];
    vector<int> cycle;
    for(int curr = node; ; curr = par[curr]) {
      cycle.push_back(curr);
      if(curr == node && cycle.size() > 1)break;
    }
    reverse(all(cycle));
    for(auto &x : cycle){
      cout << x << " ";
    }
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
