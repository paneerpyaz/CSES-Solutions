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
if(n==1){
    cout<<1;
}
else if(n<4){
    cout<<"NO SOLUTION";
}
else{
    for(int i=2 ; i<=n ; i+=2){
        cout<<i<<" ";
    }
    for(int i=1 ; i<=n ; i+=2){
        cout<<i<<" ";
    }
    
}
    return 0;
}
