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
  vector<vector<char>>g(n+1,vector<char>(m+1));
  vector<vector<bool>>vis(n+1,vector<bool>(m+1,false));
  vector<vector<int>>dis(n+1,vector<int>(m+1,1e9));
  vector<vector<int>>a(n+1,vector<int>(m+1,1e9));
  vector<int>dx = {-1,0,1,0};
  vector<int>dy = {0,-1,0,1};
  int ai,aj;
  queue<pair<int,int>>q;
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < m ; j++){
      cin >> g[i][j];
      if(g[i][j] == 'A'){
        ai = i;
        aj = j;
      }
      if(g[i][j] == 'M'){
        dis[i][j] = 0;
        q.push({i,j});
        vis[i][j] = true;
      }
      if(g[i][j] == '#') vis[i][j] = true;
    }
  }
  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for(int i = 0 ; i < 4 ; i++){
      if(x+dx[i]>=0 && x+dx[i]<n && y+dy[i]>=0 && y+dy[i]<m && !vis[x+dx[i]][y+dy[i]]){
        vis[x+dx[i]][y+dy[i]] = true;
        dis[x+dx[i]][y+dy[i]] = min(dis[x+dx[i]][y+dy[i]],dis[x][y]+1);
        q.push({x+dx[i],y+dy[i]});
      }
    }
  }
  int xx= -1,yy = -1;
  for(int i=0;i<n;i++)for(int j = 0 ; j < m ; j++)vis[i][j] = false;
  q.push({ai,aj});
  vis[ai][aj] = true;
  a[ai][aj] = 0;
  map<pair<int,int>,pair<int,int>>mp;
  mp[{ai,aj}] = {-1,-1};
  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for(int i = 0 ; i < 4 ; i++){
      if(x+dx[i]>=0 && x+dx[i]<n && y+dy[i]>=0 && y+dy[i]<m && !vis[x+dx[i]][y+dy[i]] && g[x+dx[i]][y+dy[i]] != '#'){
        vis[x+dx[i]][y+dy[i]] = true;
        a[x+dx[i]][y+dy[i]] = min(a[x+dx[i]][y+dy[i]],a[x][y]+1);
        q.push({x+dx[i],y+dy[i]});
        mp[{x+dx[i],y+dy[i]}] = {x,y};
      }
    }
  }
  bool f = false;
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < m ; j++){
      if((i == 0 || j == 0 || i == n-1 || j == m-1) && dis[i][j] > a[i][j] && g[i][j] == '.'){
        xx = i;
        yy = j;
        f = true;
        break;
      }
    }
    if(f) break;
  }
  if(ai == n-1 || aj == m-1 || ai == 0 || aj == 0){
    cout << "YES\n0\n";
    return;
  }
  if(!f){
    cout << "NO\n";
  }
  else{
    cout << "YES\n";
    vector<pair<int,int>>path;
    pair<int,int>p = {xx,yy};
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
  while(tt--){
    solve();
  }
  return 0;
}