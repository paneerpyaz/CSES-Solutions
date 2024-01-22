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
ll int fun(ll int n){
    ll sum=0;
    ll int i=1;
    while(n/pow(5,i)>0){
        sum+=n/pow(5,i);
        i++;
    }
    return sum;
}
int main(){
TimeTravel
ll int n;
cin>>n;
cout<<fun(n);
return 0;
}
