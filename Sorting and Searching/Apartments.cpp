#include<bits/stdc++.h> 
 
#define   TimeTravel  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define   ll          long long
#define   ld          long double
#define   vll         vector<ll int>
#define   vpll        vector<pair<ll int, ll int>>
#define   pb          push_back
#define   pob         pop_back()
#define   mll         map<ll int,ll int>
#define   sll         set<ll int>
#define   mp          make_pair
#define   __lcm(a,b)  (a*b)/__gcd(a,b)
#define   vsort(v)    sort(v.begin(), v.end());
#define   vsortr(v)   sort(v.rbegin(), v.rend());
#define   it(i,n)     for(ll int i=0 ; i<n ; i++)
#define   itt(i,k,n)  for(ll int i=k ; i<n ; i++)
#define   its(i,n)    for(ll int i=n-1 ; i>=0 ; i--)
#define   input(a)    for(auto &it : a){cin>>it;}
#define   output(a)   for(auto &it : a){cout<<it<<" ";}
#define   yes         cout<<"Yes"<<endl;
#define   no          cout<<"No"<<endl;
 
using namespace std;
 
int main(){
TimeTravel
    ll int n,m,k;
    cin >> n >> m >> k;
    vll a(n);
    vll b(m);
    input(a);
    input(b);
    vsort(a);
    vsort(b);
    ll int cnt = 0;
    ll int i=0,j = 0;
    while(i<n && j<m){
        if(abs(a[i]-b[j])<=k){
            cnt++;
            i++;
            j++;
        }
        else{
            if(a[i]-b[j]>k){
                j++;
            }
            else{
                i++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}