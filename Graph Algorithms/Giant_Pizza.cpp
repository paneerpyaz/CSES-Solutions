//mfs made a 2-sat problem just to eat a pizza

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
  vector<vector<int>>g(2*m+10),revg(2*m+10);
  for(int i=1;i<=n;i++){
    char ch1,ch2;
    int x1,x2;
    cin>>ch1>>x1>>ch2>>x2;

    //simplify below urself i m noob kodar

    // ~x = x + n ko leleta
    if(ch1=='+' && ch2=='+'){ // ~x1 -> x2 ,~x2 -> x1
      g[x1+m].push_back(x2);
      g[x2+m].push_back(x1);
      revg[x2].push_back(x1+m);
      revg[x1].push_back(x2+m);
    }
    else if(ch1=='+' && ch2=='-'){ // ~x1 -> ~x2, x2 -> x1
      g[x1+m].push_back(x2+m);
      g[x2].push_back(x1);
      revg[x2+m].push_back(x1+m);
      revg[x1].push_back(x2);
    }
    else if(ch1=='-' && ch2=='+'){// x1->x2 , ~x2->~x1
      g[x1].push_back(x2);
      g[x2+m].push_back(x1+m);
      revg[x2].push_back(x1);
      revg[x1+m].push_back(x2+m);
    }
    else{ // x1 -> ~x2 , x2 -> ~x1
      g[x1].push_back(x2+m);
      g[x2].push_back(x1+m);
      revg[x2+m].push_back(x1);
      revg[x1+m].push_back(x2);
    }
  }
  vector<int>entry;
  vector<int>vis(2*m+10,0);
  auto dfs = [&](int v,auto &&dfs)->void{
    vis[v]=true;
    for(auto &u:g[v]){
      if(!vis[u]){
        dfs(u,dfs);
      }
    }
    entry.push_back(v);
  };
  for(int i=1;i<=2*m;i++){
    if(!vis[i]){
      dfs(i,dfs);
    }
  }
  vector<int>check;
  for(auto &x:s)check.push_back(x);
  reverse(all(entry));
  vis.assign(2*m+1,0);
  vector<int>comp(2*m+1);
  auto SCC=[&](int v,int scc,auto &&SCC)->void{
    vis[v]=true;
    comp[v]=scc;
    for(auto &u:revg[v]){
      if(!vis[u]){
        SCC(u,scc,SCC);
      }
    }
  };
  int scc=0;
  for(int i=0 ; i<entry.size();i++){
    int node=entry[i];
    if(!vis[node]){
      SCC(node,scc,SCC);
      scc++;
    }
  }
  vector<int>ans(m+1);
  for(int i=1;i<=m;i++){
    int node=i;
    // cout<<comp[node]<<" "<<comp[node+m]<<endl;
    if(comp[node] == comp[node+m]){
      // cout<<i<<" "<<i+m<<endl;
      cout<<"IMPOSSIBLE\n";
      return;
    }
    ans[i] = (comp[node] > comp[node+m]);
  }
  for(int i=1;i<=m;i++){
    cout<<(ans[i] ? '+' : '-') <<" ";
  }
} 

signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt = 1;
  // cin>>tt;
  while(tt--){
    solve();
  }
  return 0;
}
