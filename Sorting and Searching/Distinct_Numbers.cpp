#include<bits/stdc++.h>
#define TimeTravel ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define ld long double
#define vll vector<ll int>
#define vpll vector<pair<ll int, ll int>>
#define make_pair mp
#define mod 1e9+7
#define it(i,n) for(ll int i=0 ; i<n ; i++)
#define pb push_back
using namespace std;
int main(){
TimeTravel
ll int n;
cin>>n;
ll int a[n];
it(i,n){cin>>a[i];}
ll int cnt=1;
sort(a,a+n);
ll int temp=a[0];
it(i,n){
    if(a[i]!=temp){
        cnt++;
        temp=a[i];
    }
}
cout<<cnt;
    return 0;
}
