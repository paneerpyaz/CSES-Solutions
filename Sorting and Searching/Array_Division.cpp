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
 
bool f(int sum,vll &a,int n,int k){
  int temp = 0;
  int sub = 0;
  for(int i = 0 ; i < n ; i++){
    temp += a[i];
    if(temp > sum){
      sub++;
      if(a[i] <= sum) temp = a[i];
      else return false;
    }
  }
  sub += (temp <= sum);
  return (sub <= k);
}
 
void samadhaan(){
  int n,k;
  cin >> n >> k;
  vll a(n);
  for(auto &i : a){
    cin >> i;
  }
  int low = 1;
  int high = accumulate(a.begin(),a.end(),0LL);
  int mid,ans;
  while(low <= high){
    mid = low + (high - low) / 2;
    std::cerr<<mid<<" "<<f(mid,a,n,k)<<endl;
    if(f(mid,a,n,k)){
      high = mid - 1;
      ans = mid;
    }
    else{
      low = mid + 1;
    }
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
