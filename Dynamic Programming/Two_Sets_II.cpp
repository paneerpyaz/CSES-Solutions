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

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
vector<vector<int>> dp(501,vector<int>(125251,-1));
int recc(int state,int sum,int n){
  if(state==n+1){
    if(sum== (n*(n+1))/4){return 1;}
    else{
      return 0;
    }
  }
  if(dp[state][sum]!=-1) return dp[state][sum];
  int ans = 0;
  ans = recc(state+1,sum+state,n)%MOD2;
  ans = (ans + recc(state+1,sum,n))%MOD2;
  return dp[state][sum] = ans;
}
 
void samadhaan(){
  int n;
  cin>>n;
  if(((n*(n+1))/2)&1){
    cout<<0<<'\n';
    return;
  }
 
  int x = recc(1,0,n);
  cout<<(x*binpow(2,MOD2-2,MOD2))%MOD2<<endl;
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