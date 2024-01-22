#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
#define int long long
#define vpll vector<pair<int,int>>
#define vll vector<int>
#define vvll vector<vector<int>>
#define ld long double
#define F first
#define S second
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define inp(v) for(auto &it:v)cin>>it;
#define it(i,k,n) for(int i=k ; i<n ; i++)
#define rit(i,k,n) for(int i=n-1 ; i>=k ; i--)
#define see(v) for(auto &it:v){cout<<it<<" ";}cout<<endl;
#define pr(it,v) for(auto &it:v){cout<<it.F<<" "<<it.S<<endl;}
#define CEIL(x,y)  (int)ceil(1.0 * x/y)
 
const int MOD1 = 998244353;
const int MOD2 = 1e9+7;
string s,t;
int dp[6050][6050];
 
int recc(int i,int j,int n,int m){
    if(i >= n && j >= m){
        return 0;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    int ans3,ans2,ans1,ans;
    ans1 = recc(i+1,j,n,m)+1;
    ans2 = recc(i,j+1,n,m)+1;
    ans3 = recc(i+1,j+1,n,m) + (s[i] != t[j]);
    ans = min(ans1,min(ans3,ans2));
    return dp[i][j] = ans;
}
 
void samadhaan(){
    memset(dp,-1,sizeof(dp));
    cin >> s >> t;
    int n = s.length();
    int m = t.length();
    cout << recc(0,0,n,m);
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