#include<bits/stdc++.h>;
using namespace std;
 
#define int long long
#define ld long double
#define it(i,k,n) for(int i=k ; i<n ; i++)
#define rit(i,k,n) for(int i=n-1 ; i>=k ; i--)
#define all(v) v.begin(),v.end()
#define input(v) for(auto &it:v)cin>>it;
#define CEIL(x,y)  (int)ceil(1.0 * x/y)
const int MOD = 1e9 + 7;
vector<int>dp(1000005,0) ;
int fun(int n){
    if(dp[n] != 0){
        return dp[n];
    }
	if(n == 0){
		return dp[n] = 1;
	}
	it(i,1,7){
        if(n-i>=0){
        dp[n] += fun(n-i);
        dp[n] %= MOD;
        }
    }
    return dp[n];
}
void samadhaan(){  
   int n;
   cin >> n;
   cout << fun(n) << endl;
}
 
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int tt = 1;
// cin >> tt;
while(tt--){
    samadhaan();
    }
    return 0;
}