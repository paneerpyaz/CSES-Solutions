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
 
int dp[100005][105];
 
int recc(int curr_index,int last_element,vll &a,int n,int m){
  if(curr_index == n){
    return 1;
  }
  if(dp[curr_index][last_element] != -1){
    return dp[curr_index][last_element];
  }
  int ans = 0;
  if(a[curr_index] == 0){
    for(int diff = -1 ; diff <= 1 ; diff++){
      int new_last_element = last_element + diff;
      if(new_last_element >= 1 && new_last_element <= m){
        ans += recc(curr_index+1,new_last_element,a,n,m);
        ans %= MOD2;
      }
    }
  }
  else{
    if(abs(a[curr_index]-last_element) <= 1){
      ans += recc(curr_index+1,a[curr_index],a,n,m);
      ans %= MOD2;
    }
  }
  return dp[curr_index][last_element] = ans;
}
 
void samadhaan(){ 
  int n,m;
  cin >> n >> m;
  memset(dp,-1,sizeof(dp));
  vll a(n);
  for(auto &i : a){
    cin >> i;
  }
  int ans = 0;
  if(a[0] == 0){
    for(int i = 1 ; i <= m ; i++){
    ans +=  recc(1,i,a,n,m);
    ans %= MOD2;
    }
  }
  else{
    ans = recc(1,a[0],a,n,m);
  }
  
  cout << ans << endl;
 
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
