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
  int n,m,q;
  cin >> n >> m >> q;
  vector<vector<int>>dp(n+1,vector<int>(n+1,1e17));
  for(int i = 0 ; i < m ; i++){
    int u,v,w;
    cin >> u >> v >> w;
    dp[u][v] = min(dp[u][v],w);
    dp[v][u] = min(dp[v][u],w);
  }
  for(int i = 1 ; i <= n ; i++) dp[i][i] = 0;
  for(int k = 1 ; k <= n ; k++){
    for(int i = 1 ; i <= n ; i++){
      for(int j = 1 ; j <= n ; j++){
        dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
      }
    }
  }
  while(q--){
    int a,b;
    cin >> a >> b;
    cout << (dp[a][b] == 1e17 ? -1 : dp[a][b]) << '\n';
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
