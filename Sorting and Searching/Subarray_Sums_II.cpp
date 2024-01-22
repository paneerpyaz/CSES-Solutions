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
const int N = 1e7;
vector<int>prime;
vector<int>spf(1e7+1,-1);
 
int binpow(int a, int b) {
    int m = MOD1;
    a %= m;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
void sieve(){
    vector<bool>is_prime(N+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= N; i++) {
        if (is_prime[i] && i * i <= N) {
            for (int j = i * i; j <= N; j += i)
                is_prime[j] = false;
        }
    }
    for(int i = 0 ; i <= N ; i++){
        if(is_prime[i]){
            prime.pb(i);
        }
    }
}
void spfsieve()
{
    spf[1] = 1;
    for (int i = 2; i < 1e7+1; i++) spf[i] = i;
    for (int i = 4; i < 1e7+1; i += 2)spf[i] = 2;
    for (int i = 3; i * i < 1e7+1; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < 1e7+1; j += i){
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}
vll getFac(int x)
{
    vector<int> ret;
    while (x != 1) {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}
 
 
void samadhaan(){
    int n,k;
    cin >> n >> k;
    vll a(n);
    inp(a);
    vll pref(n+1);
    pref[0] = 0;
    it(i,1,n+1){
        pref[i] = pref[i-1] + a[i-1];
    }
    //pref[R+1]-pref[L] == k
    int cnt = 0;
    map<int,int>m;
    for(int R = 0 ; R <= n-1 ; R++){
         m[pref[R]]++;
         cnt += m[-k + pref[R+1]];
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
