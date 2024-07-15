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
 
struct disjointSet{
  vector<int>parent,size;
  disjointSet(int n){
    size.resize(n+1,1);
    parent.resize(n+1);
    for(int i=1;i<=n;++i) parent[i]=i;
  }
  int FIND(int v){
    if(parent[v]==v) return v;
    return parent[v] = FIND(parent[v]);
  }
  void UNION(int u,int v,int &largest,int &num){
    u = FIND(u); v = FIND(v);
    if(u==v) return;
    --num;
    if(size[u] < size[v]) swap(u,v);
    parent[v] = u;
    size[u] += size[v];
    largest = max(largest,size[u]);
  }
};
void solve(){
  int n,m;
  cin>>n>>m;
  disjointSet dsu(n);
  int num = n,largest = 1;
  while(m--){
    int u,v;
    cin>>u>>v;
    dsu.UNION(u,v,largest,num);
    cout<<num<<" "<<largest<<endl;
  }
} 
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt = 1;
  while(tt--){
    solve();
  }
  return 0;
}
