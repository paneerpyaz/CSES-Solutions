#include<bits/stdc++.h>;
using namespace std;
 
#define int long long
#define ld long double
#define F first
#define S second
#define it(i,k,n) for(int i=k ; i<n ; i++)
#define rit(i,k,n) for(int i=n-1 ; i>=k ; i--)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define input(v) for(auto &it:v)cin>>it;
#define output(v) for(auto &it:v){cout<<it<<" ";}cout<<endl;
#define CEIL(x,y)  (int)ceil(1.0 * x/y)
const int MOD1 = 998244353;
const int MOD2 = 1e9+7;
 
 
int knap(int idx , int wtleft,vector<vector<int>>&dp,vector<int>&wt,vector<int>&val,int n){
    if(idx < 0 )return 0;
    if(wtleft == 0)return 0;
    if(dp[idx][wtleft]!=-1) return dp[idx][wtleft];
    int ans = knap(idx-1,wtleft,dp,wt,val,n);
    if(wtleft-wt[idx]>=0){
        ans = max(ans,knap(idx-1,wtleft-wt[idx],dp,wt,val,n)+val[idx]);
    }
    return dp[idx][wtleft]=ans;
}
void samadhaan(){
    vector<int>wt(1005),val(1005);
vector<vector<int>>dp(1005,vector<int>(100005,-1));
    int n , w;
    cin >> n >> w;
    it(i,0,n) cin >> wt[i];
    it(i,0,n) cin >> val[i];
    cout << knap(n-1,w,dp,wt,val,n) << endl;
}   
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int tt = 1;
// cin >> tt;
while(tt-->0){
    samadhaan();
    }
    return 0;
}