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
 
void samadhaan(){
    int a , b;
    cin >> a >> b;
    vvll dp(a+1,vll(b+1,1e10));
 
    it(i,0,a+1){
        it(j,0,b+1){
            if(i == 0 || j == 0 || i == j){
                dp[i][j] = 0;
            }
        }
    }
    for(int lt = 1 ; lt <= a ; lt++){
        for(int wt = 1 ; wt <= b ; wt++){
            for(int j = 0 ; j <= lt ; j++){
                dp[lt][wt] = min(dp[lt][wt],dp[lt-j][wt]+dp[j][wt]+1);
            }
            for(int j = 0 ; j <= wt ; j++){
                dp[lt][wt] = min(dp[lt][wt],dp[lt][wt-j]+dp[lt][j]+1);
            }
        }
    }
    cout << dp[a][b] << endl;
 
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
