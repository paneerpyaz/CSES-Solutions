#include<bits/stdc++.h> 
 
#define   TimeTravel  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define   ll          long long
#define   ld          long double
#define   vll         vector<ll int>
#define   vpll        vector<pair<ll int, ll int>>
#define   pb          push_back
#define   mll         map<ll int,ll int>
#define   sll         set<ll int>
#define   mp          make_pair
#define   lcm(a,b)    (a*b)/__gcd(a,b)
#define   vsort(v)    sort(v.begin(), v.end());
#define   vsortr(v)   sort(v.rbegin(), v.rend());
#define   it(i,n)     for(ll int i=0 ; i<n ; i++)
#define   itt(i,k,n)  for(ll int i=k ; i<n ; i++)
#define   its(i,n)    for(ll int i=n-1 ; i>=0 ; i--)
#define   input(a)    for(auto &it:a){cin>>it;}
#define   output(a)   for(auto &it:a){cout<<it<<" ";}cout<<endl;
#define   yes         cout<<"YES"<<endl;
#define   no          cout<<"NO"<<endl;
 
using namespace std;
 
// Binary Exponentiation
 
int binpow(ll int a, ll int b){
ll int n=1e9+7;
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
 
//Number of factors
 
ll int Countfactors(ll int n){
    ll int cnt = 0;
    itt(i,1,sqrt(n)){
        if(n % i == 0){
            cnt+=2;
        }
    }
    ll int z = sqrt(n);
    if( n % z == 0 && z*z == n){
        cnt++;
    }
    return cnt;
}
//Prime Factorization
 
vll PrimeFactors(ll int n){
vll v;
while(n%2 == 0)
 {
   v.pb(2);
   n = n/2;
 }
 ll int z = sqrt(n);
 for(ll int i = 3; i <= z; i = i + 2)
 {
   while (n % i == 0)
   {
     v.pb(i);
     n = n/i;
   }
 }
 if (n > 2){
  v.pb(n);
 }
 return v;
}
 
//Main function
 
int main(){
TimeTravel
ll int t=1;
// cin>>t;
while(t--){
    //  Mera Ghatiya Solution ;(
    ll int n;
    cin >> n;
    vll a(n+1);
    vll pos(n+1,0);
    for(int i = 1 ; i<=n ; i++)
    {
      cin >> a[i];
    }
        for(int i = 1 ; i<=n ; i++)
    {
      pos[a[i]] = i;
    }
    ll int res = 1;
    itt(i,2,n+1){
      if(pos[i] < pos[i-1]) 
      {
       res++;
      }
    }
    cout << res << endl;
    }
 
    
    return 0;
}
