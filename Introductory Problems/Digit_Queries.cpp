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
    vll nums;
    for(int i = 0LL ;; i++){
        int num = 9LL*pow(10,i)*(i+1);
        if(num <= 1e18){
            nums.pb(num);
        }
        else{
            nums.pb(num);
            break;
        }
    }
    vpll ranges(18);
    for(int i = 0 ; i < 17 ; i++){
        ranges[i].S = nums[i];
    }
    ranges[0].F = 1;
    
    for(int i = 1 ; i < 18 ; i++){
        ranges[i].S += ranges[i-1].S;
    }
    for(int i = 1 ; i < 18 ; i++){
        ranges[i].F = ranges[i-1].S+1;
    }
    int q;
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        int idx;
        for(int i = 0 ; i < 17 ; i++){
            if(x >= ranges[i].F && x <= ranges[i].S){
                idx = i;
                break;
            }
        }
        int res = ((x-ranges[idx].F)/(idx+1)) ;
        int a = pow(10,idx) + res;
        string s = to_string(a);
        int f =  (x-ranges[idx].F)%(idx+1);
        cout << s[f] <<endl;
    }
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
