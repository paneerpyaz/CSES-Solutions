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
  vector<vector<int>>g(n+1);
  for(int i = 0 ; i < m ; i++){
    int u,v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int>vis(n+1,false);
  auto dfs = [&](int v,int p,vector<int>&ans,auto &&dfs)->bool{
    vis[v] = true;
    for(auto &u : g[v]){
      ans.push_back(u);
      if(!vis[u]){
        if(dfs(u,v,ans,dfs)) return true;
      }
      else if(u != p){
        return true;
      }
      ans.pop_back();
    }
    return false;
  };
  for(int i = 1 ; i <= n ; i++){
    vector<int>ans;
    vector<int>res;
    ans.push_back(i);
    if(!vis[i] && dfs(i,-1,ans,dfs)){
      int last = ans.back();
      reverse(all(ans));
      int z = ans.size();
      for(int i = 1 ; i < z ; i++){
        res.push_back(ans[i]);
        if(ans[i] == last) break;
      }
      cout << res.size()+1 << endl;
      cout<<last<<" ";
      for(auto &x : res){
        cout << x << " ";
      }
      cout << endl;
      return;
    }
  }
  cout << "IMPOSSIBLE\n";
} 

signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int tt = 1;
  while(tt--){
    solve();
  }
  return 0;
}