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

int dp[200002][31];

void solve(){
  int n,q;
  cin>>n>>q;
  vector<int>par(n+1);
  for(int i=1;i<=n;i++){
    int u;
    cin>>u;
    par[i]=u;
  }
  for(int i=1;i<=n;i++){
    dp[i][0]=par[i];
  }
  for(int j=1;j<31;j++){
    for(int i=1;i<=n;i++){
      dp[i][j]=dp[dp[i][j-1]][j-1];
    }
  }
  while(q--){
    int x,k;
    cin>>x>>k;
    for(int i=0;i<31;i++){
      if((1LL<<i)&k){
        x=dp[x][i];
      }
    }
    cout<<x<<'\n';
  }
} 

signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int tt = 1;
  memset(dp,0,sizeof(dp));
  while(tt--){
    solve();
  }
  return 0;
}
