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
 
int binpow(ll int a, ll int b){
ll int n= 998244353;
ll int ans=1;
a=a%n;
while(b>0){
if(b&1){
ans=(ans%n*a%n)%n;
}
a=(a%n*a%n)%n;
b=b>>1;
}
return ans;
}

int main(){
TimeTravel
    ll int n,m;
    cin >> n >> m;  
    multiset<ll int>s;
    ll int temp;
    it(i,n){
        
        cin >> temp;
        s.insert(temp);
    }
    ll int t;
 
    it(i,m){
        cin >> t;
        auto it = s.upper_bound(t);
        if(it == s.begin()){
            cout << -1 << endl;
        }
        else{
            cout << *(--it) << endl;
            s.erase(it);
        }
    }
    return 0;
}
