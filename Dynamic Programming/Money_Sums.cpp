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
    int n;
    cin >> n;
    vll a(n);
    inp(a);
    vector<bool>dp(100005,false);
    dp[a[0]] = true;
    for(int i = 1 ; i < n ; i++ ){
        for(int j = 100000 ; j >= 0; j--){
            if(dp[j]){
                dp[j+a[i]] = true;
            }
        }
        dp[a[i]] = true;
    }
    vll ans;
    for(int i = 1 ; i < 100005 ; i++){
        if(dp[i]){
            ans.pb(i);
        }
    }
    cout << ans.size() << endl;
    see(ans);
    
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
