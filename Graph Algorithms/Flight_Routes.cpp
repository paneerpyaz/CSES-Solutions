//Solution 1

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

void solve(){
  int n,m,k;
  cin>>n>>m>>k;
  vector<vector<pair<int,int>>>g(n+1);
  for(int i=0;i<m;i++){
    int u,v,w;
    cin>>u>>v>>w;
    g[u].push_back({v,w});
  }
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
  pq.push({0,1});
  vector<vector<int>>dis(n+1);
  while(!pq.empty()){
    int node=pq.top().second;
    int dist=pq.top().first;
    pq.pop();
    if(dis[node].size()>=k)continue;
    dis[node].push_back(dist);
    for(auto &u:g[node]){
      pq.push({u.second+dist,u.first});
    }
  }
  for(int i=0;i<k;i++){
    cout<<dis[n][i]<<" ";
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


//Solution 2

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
  int n,m,k;
  cin>>n>>m>>k;
  vector<vector<pair<int,int>>>g(n+1);
  for(int i=0;i<m;i++){
    int u,v,w;
    cin>>u>>v>>w;
    g[u].push_back({v,w});
  }
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
  vector<priority_queue<int>>best(n+1);
  best[1].push(0);
  pq.push({0,1});
  while(!pq.empty()){
    int node = pq.top().second;
    int dist = pq.top().first;
    pq.pop();
    if(best[node].size() > k && dist > best[node].top()){
      continue;
    }
    for(auto &u : g[node]){
      int child = u.first;
      int wt = u.second;
      int new_dist = wt + dist;
      if(best[child].size()<k){
        best[child].push(new_dist);
        pq.push({new_dist, child});
      }
      else if(new_dist < best[child].top()){
        best[child].pop();
        best[child].push(new_dist);
        pq.push({new_dist,child});
      }
    }
  }
  vector<int> ans;
  while(!best[n].empty()){
    ans.push_back(best[n].top());
    best[n].pop();
  }
  sort(ans.begin(), ans.end());
  for(auto i:ans){
    cout<<i<<" ";
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

