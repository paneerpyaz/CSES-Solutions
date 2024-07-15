#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define int long long
 
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
 
const int MOD1 = 998244353;
const int MOD2 = 1e9+7;
const int inf = 1e18;
 
class quad{
  public:
  int a,b,c,d;
};
 
void solve(){
  int n,m;
  cin>>n>>m;
  vector<vector<pair<int,int>>>g(n+1);
  for(int i=0;i<m;i++){
    int u,v,w;
    cin>>u>>v>>w;
    g[u].push_back({v,w});
  }
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
  vector<quad>ans(n+1,{inf,0LL,MOD2,0LL});
  ans[1].a = 0;
  ans[1].b = 1;
  ans[1].c = 0;
  pq.push({0,1});
  while(!pq.empty()){
    auto[d,v]=pq.top();
    pq.pop();
    for(auto &[u,w]:g[v]){
      if(ans[u].a > d+w){
        ans[u].a = d+w;
        ans[u].b = ans[v].b;
        ans[u].c = ans[v].c+1;
        ans[u].d = ans[v].d+1;
        pq.push({d+w,u});
      }
      else if(ans[u].a == d+w){
        ans[u].b += ans[v].b;
        ans[u].b %= MOD2;
        ans[u].c = min(ans[u].c,ans[v].c+1);
        ans[u].d = max(ans[u].d,ans[v].d+1);
      }
    }
  }
  cout<<ans[n].a<<" "<<ans[n].b<<" "<<ans[n].c<<" "<<ans[n].d;
} 
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt = 1;
  while(tt--){
    solve();
  }
  return 0;
}
