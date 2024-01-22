#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
// #define int long long
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
    vpll a(n+1);
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i].F;
        a[i].S = i;
    }
    stack<pair<int,int>>stk;
    vll ans;
    ans.pb(0);
    stk.push({a[1].F,1});
    for(int i = 2 ; i <= n ; i++){
        while(!stk.empty() && stk.top().F >= a[i].F ){
            stk.pop();
        }
        if(!stk.empty()){
            ans.pb(stk.top().S);
        }
        else{
            ans.pb(0);
        }
        stk.push({a[i].F,i});
    }
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
