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
#define lb lower_bound
#define ub upper_bound
#define it(i,k,n) for(int i=k ; i<n ; i++)
#define rit(i,k,n) for(int i=n-1 ; i>=k ; i--)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define mxl(v) *max_element(all(v))
#define mnl(v) *min_element(all(v))
#define inp(v) for(auto &it:v)cin>>it;
#define see(v) for(auto &it:v){cout<<it<<" ";}cout<<endl;
#define pr(it,v) for(auto &it:v){cout<<it.F<<" "<<it.S<<endl;}
#define CEIL(x,y)  (int)ceil(1.0 * x/y)
const int MOD1 = 998244353;
const int MOD2 = 1e9+7;
 
bool f(int mid,vll &a,int n,int t){
    int sum = 0;
    it(i,0,n){
        sum += mid/a[i];
        if(sum > t) break;
    }
    return (sum >= t);
}
void samadhaan(){
    int n;
    cin >> n;
    int t;
    cin >> t;
    vll a(n);
    inp(a);
    int s = 0;
    int e = 1e18;
    int mid,ans;
    while(s <= e){
        mid = s + (e-s)/2;
        if(f(mid,a,n,t)){
            ans = mid;
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    cout << ans << endl;
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
 
