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
 
void samadhaan(){
    int n;
    cin >> n;
    vll a(n);
    inp(a);
    multiset<int>s;
    s.insert(a[0]);
    it(i,1,n){
        auto it = s.ub(a[i]);
        if(it == s.end()){
            s.insert(a[i]);
        }
        else{
            s.erase(it);
            s.insert(a[i]);
        }
    }
    cout << s.size() << endl;
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
