#include<bits/stdc++.h>;
using namespace std;
 
#define int long long
#define ld long double
#define F first
#define S second
#define it(i,k,n) for(int i=k ; i<n ; i++)
#define rit(i,k,n) for(int i=n-1 ; i>=k ; i--)
#define all(v) v.rbegin(),v.rend()
#define input(v) for(auto &it:v)cin>>it;
#define output(v) for(auto &it:v){cout<<it<<" ";}cout<<endl;
#define CEIL(x,y)  (int)ceil(1.0 * x/y)
const int MOD1 = 998244353;
const int MOD2 = 1e9+7;
 
void samadhaan(){
    int n;
    cin >> n;
    char a[n][n];
    it(i,0,n){
        it(j,0,n){
            cin >> a[i][j];
        }
    }
    vector<vector<int>>dp(n,vector<int>(n,0));
    if(a[0][0] == '*' || a[n-1][n-1] == '*'){
        cout << 0 << endl;
        return;
    }
    dp[0][0]=1;
    it(i,0,n){
        it(j,0,n){
            if(a[i][j] != '*'){
                if(a[i-1][j] != '*' && i>=1){
                    dp[i][j] += dp[i-1][j];
                    dp[i][j]%=MOD2;
                }
                if(a[i][j-1] != '*' && j>=1){
                    dp[i][j] += dp[i][j-1];
                    dp[i][j]%=MOD2;
                }
            }
        }
    }
    cout << dp[n-1][n-1] << endl;
 
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
