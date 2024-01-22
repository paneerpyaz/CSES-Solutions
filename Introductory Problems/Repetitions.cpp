#include<bits/stdc++.h>
#define TimeTravel ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define ld long double
#define vll vector<ll int>
#define vpll vector<pair<ll int, ll int>>
#define bs binary_search
#define make_pair mp
#define m 1e9+7
#define vsort sort(v.begin(), v.end());
#define vsortd sort(v.begin(), v.end(),greater<int>());
#define it(i,n) for(ll int i=0 ; i<n ; i++)
#define pb push_back
using namespace std;
int main(){
TimeTravel
string s;
cin>>s;
ll int n=s.length();
vll v;
if(n==1){
    cout<<1;
}
else{
ll int cnt=0;
char a=s[0];
it(i,n){
    if(s[i]==a){
        cnt++;
    }
    else{
        v.pb(cnt);
        cnt=1;
        a=s[i];
    }
}
if(cnt!=1){
    v.pb(cnt);
}
vsortd
cout<<v[0];
}
    return 0;
}
