#include<bits/stdc++.h>
using namespace std;
 
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
    it(i,0,n){
        if(a[i] > 0){
            a[i] %= n;
        }
        else{
            a[i] = (a[i] + 1000000000*n)%n;
        }
    }
    // see(a);
    vll pref(n+1,0);
    it(i,1,n+1) pref[i] = pref[i-1] + a[i-1];
    // see(pref);
    it(i,0,n+1) pref[i]%=n;
    // see(pref);
    int cnt = 0;
    map<int,int>m;
    for(int R = 0 ; R <= n-1 ; R++){
         m[pref[R]]++;
         cnt += m[pref[R+1]-n];
         cnt += m[pref[R+1]];
    }
    cout << cnt << endl;
 
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
