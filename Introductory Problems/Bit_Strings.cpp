#include<bits/stdc++.h>
#define TimeTravel ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define ld long double
#define vll vector<ll int>
#define vpll vector<pair<ll int, ll int>>
#define bs binary_search
#define make_pair mp
const int mod =1e9+7;
#define vsort sort(v.begin(), v.end());
#define vsortd sort(v.begin(), v.end(),greater<int>());
#define it(i,n) for(ll int i=0 ; i<n ; i++)
#define pb push_back
using namespace std;
long long binpow(long long a, long long b, long long mod) {
    a %= mod;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
int main(){
TimeTravel
ll int n;
cin>>n;
cout<<binpow(2,n,mod);
 
    return 0;
}