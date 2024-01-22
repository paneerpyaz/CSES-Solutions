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
#define forn(i,k,n) for(int i = k ; i < n ; i++)
#define see(v) for(auto &it:v){cout<<it<<" ";}cout<<endl;
#define pr(v) for(auto &it:v){cout<<it.F<<" "<<it.S<<endl;}
#define CEIL(x,y)  (int)ceil(1.0 * x/y)
 
const int MOD1 = 998244353;
const int MOD2 = 1e9+7;
 
int n;
vll a;
int dp[5005][5005];
 
int rec(int i , int j){//say the current state is at i from beginning and j from ending
//this function will return the value of x-y at this state
//it actually means i+n-1-j chances are completed
//if this is even, taro ki chance hai, else jiro ki
//if taro ki chance, x-y must be maxi else mini
    int chance = i+n-1-j;
    if(j == i){
        if(chance%2){
            return -a[i];
        }
        else{
            return a[i];
        }
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int ans;
    if(chance%2){
        //jiro chalega, minimize the score x-y
        ans = rec(i+1,j)-a[i];
        ans = min(ans,rec(i,j-1)-a[j]);
    }
    else{
        //taro chalega, maximize the score x-y
        ans = rec(i+1,j)+a[i];
        ans = max(ans,rec(i,j-1)+a[j]);
    }
    return dp[i][j] = ans;
}
 
void samadhaan(){
    cin >> n;
    a.resize(n);
    memset(dp,-1,sizeof(dp));
    inp(a);
    cout << (accumulate(all(a),0LL)+rec(0,n-1))/2 << endl;
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
 
 
 