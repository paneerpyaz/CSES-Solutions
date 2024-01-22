#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
#define int long long
#define vpll vector<pair<int,int>>
#define pll pair<int,int>
#define vb vector<bool>
#define vll vector<int>
#define vvll vector<vector<int>>
#define ld long double
#define F first
#define S second
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define inp(v) for(auto &it:v)cin>>it;
#define it(i,k,n) for(int i = k;i<n ; i++)
#define see(v) for(auto &it:v){cout<<it<<" ";}cout<<endl;
#define pr(v) for(auto &it:v){cout<<it.F<<" "<<it.S<<endl;}
#define CEIL(x,y) (int)ceil(1.0 * x/y)
 
const int MOD1 = 998244353;
const int MOD2 = 1e9+7;
 
void samadhaan(){ 
  int n;
  cin >> n;
  vector<pair<pair<int,int>,int>>a(n);
  for(int i = 0 ; i < n ; i++){
    cin >> a[i].F.F >> a[i].F.S;
    a[i].S = i;
  }
  sort(all(a));
  priority_queue<pair<int,int>,vpll,greater<pll>>pq;
  vpll ans;
  pq.push({a[0].F.S,1});
  ans.pb({a[0].S,1});
  int rooms = 1;
  for(int i = 1 ; i < n ; i++){
    int lol = pq.top().S;
    if(a[i].F.F > pq.top().F){
      ans.pb({a[i].S,lol});
      pq.pop();
      pq.push({a[i].F.S,lol});
    }
    else{
      rooms++;
      pq.push({a[i].F.S,rooms});
      ans.pb({a[i].S,rooms});
    }
  }
  cout << rooms << endl;
  sort(all(ans));
  for(auto &i : ans){
    cout << i.S << " ";
  }
  cout << endl;
} 
 
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int lim = 1;
  // cin >> lim;
  while(lim-->0){
    samadhaan();
  }
  return 0;
}
