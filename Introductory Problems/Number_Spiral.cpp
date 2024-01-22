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
ll int t;
cin>>t;
while(t--){
    ll int x,y;
    cin>>x>>y;
    if(x<y){
        if(y%2==0){
            cout<<(y-1)*(y-1)+x<<endl;
        }
        else{
            cout<<y*y-x+1<<endl;
        }
    }
    else{
        if(x%2==0){
            cout<<x*x-y+1<<endl;
        }
        else{
            cout<<(x-1)*(x-1)+y<<endl;
        }
    }
    }
    return 0;
}
