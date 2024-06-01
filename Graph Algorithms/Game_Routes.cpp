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
  vector<vector<int>>g(n+1);
  for(int i=0;i<m;i++){
    int u,v;
    cin >> u >> v;
    g[u].push_back(v);
  }
  vector<int>dp(n+1,-1);
  auto DP = [&](int v,auto &&DP)->int{
    if(v == n) return 1;
    if(dp[v] != -1) return dp[v];
    int ans = 0;
    for(auto &u : g[v]){
      ans += (DP(u,DP));
      ans %= MOD2;
    }
    return dp[v] = ans;
  };
  cout<<DP(1,DP);
} 
 
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int tt = 1;
  while(tt--){
    solve();
  }
  return 0;
}
