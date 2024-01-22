#include<bits/stdc++.h>;
using namespace std;
 
#define int long long
#define ld long double
#define F first
#define S second
#define it(i,k,n) for(int i=k ; i<n ; i++)
#define rit(i,k,n) for(int i=n-1 ; i>=k ; i--)
#define all(v) v.begin(),v.end()
#define input(v) for(auto &it:v)cin>>it;
#define output(v) for(auto &it:v){cout<<it<<" ";}cout<<endl;
#define CEIL(x,y)  (int)ceil(1.0 * x/y)
const int MOD1 = 998244353;
const int MOD2 = 1e9+7;
 
 
void samadhaan(){ 
    int n;
    cin >> n;
 
    int x; cin >> x;
    vector<int>c(n);
    input(c);
    vector<int>dp(x+1,0);
    dp[0] = 1;
    it(i,0,x+1){
        it(j,0,n){
            if(i >= c[j]){
                dp[i] += dp[i-c[j]];
                dp[i] %= MOD2;
            }
        }
    }
    cout << dp[x] << endl;
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