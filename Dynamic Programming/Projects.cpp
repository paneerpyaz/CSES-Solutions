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
 
int dp[200005];
 
int recc(int project_number,vector<pair<int,pair<int,int>>>&a,int n){
  if(project_number == n+1){
    return 0;
  }
  
  if(dp[project_number] != -1){
    return dp[project_number];
  }
  int ans = recc(project_number+1,a,n);
  int low = project_number+1;
  int high = n;
  int new_project_number = n+1;
  int mid;
  while(low <= high){
    mid = (high + low) / 2;
    if(a[mid].F > a[project_number].S.F){
      new_project_number = mid;
      high = mid - 1;
    }
    else{
      low = mid + 1;
    }
  }
  int reward = a[project_number].S.S;
  ans = max(ans , recc(new_project_number,a,n)+reward);
 
  return dp[project_number] = ans;
}
 
void samadhaan(){
  int n;
  cin >> n;
  memset(dp,-1,sizeof(dp));
  vector<pair<int,pair<int,int>>>a(n+1);
  for(int i = 1 ; i <= n ; i++){
    cin >> a[i].F >> a[i].S.F >> a[i].S.S;
  }
  sort(all(a));
  cout << recc(1,a,n) << endl;
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
 
 
 
 
