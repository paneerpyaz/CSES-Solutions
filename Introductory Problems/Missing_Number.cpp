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
ll int n;
cin>>n;
ll int a[n-1];
ll int b[n];
it(i,n-1){cin>>a[i];}
it(i,n){b[i]=i+1;}
sort(a,a+n-1);
bool flag=true;
it(i,n-1){
    if(b[i]!=a[i]){
        cout<<b[i];
        flag=false;
        break;
    }
}
if(flag){
    cout<<b[n-1];
}
    return 0;
}
