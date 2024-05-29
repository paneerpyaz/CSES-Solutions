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
  vector<vector<char>>g(n+1,vector<char>(m+1));
  vector<vector<bool>>vis(n+1,vector<bool>(m+1,false));
  vector<vector<int>>dis(n+1,vector<int>(m+1,1e9));
  map<pair<int,int>,pair<int,int>>mp;
  int ai,aj,bi,bj;
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < m ; j++){
      cin >> g[i][j];
      if(g[i][j] == '#') vis[i][j] = true;
      if(g[i][j] == 'A'){
        ai = i; aj = j;
      }
      if(g[i][j] == 'B'){
        bi = i; bj = j;
      }
    }
  }
  queue<pair<int,int>>q;
  dis[ai][aj] = 0;
  q.push({ai,aj});
  mp[{ai,aj}] = {-1,-1};
  vis[ai][aj] = true;
  int dx[4] = {-1,0,1,0};
  int dy[4] = {0,1,0,-1};
  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for(int i = 0 ; i < 4 ; i++){
      int xx = x + dx[i];
      int yy = y + dy[i];
      if(xx>=0 && xx<n && yy>=0 && yy<m && !vis[xx][yy]){
        q.push({xx,yy});
        vis[xx][yy] = true;
        mp[{xx,yy}] = {x,y};
        dis[xx][yy] = min(dis[xx][yy],dis[x][y]+1);
      }
    }
  }
  if(dis[bi][bj] == 1e9){
    cout << "NO\n";
  }
  else{
    cout << "YES\n";
    vector<pair<int,int>>path;
    pair<int,int>p = {bi,bj};
    pair<int,int>neg = {-1,-1};
    while(mp[p] != neg){
      path.push_back(p);
      p = mp[p];
    }
    path.push_back({ai,aj});
    reverse(all(path));
    string ans = "";
    int z = path.size();
    for(int i = 0 ; i < z-1 ; i++){
      if(path[i+1].first-path[i].first == 1) ans += 'D';
      if(path[i+1].first-path[i].first == -1) ans += 'U';
      if(path[i+1].second-path[i].second == 1) ans += 'R';
      if(path[i+1].second-path[i].second == -1) ans += 'L';
    }
    cout << ans.size() << endl;
    cout << ans << endl;
  }
} 

signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int tt = 1;
  // cin >> tt;
  while(tt--){
    solve();
  }
  return 0;
}