#include<bits/stdc++.h> 
    
    #define   TimeTravel  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define   ll          long long
    #define   ld          long double
    #define   vll         vector<ll int>
    #define   vpll        vector<pair<ll int, ll int>>
    #define   fi          first
    #define   se          second
    #define   pb          push_back
    #define   mll         map<ll int,ll int>
    #define   sll         set<ll int>
    #define   mp          make_pair
    #define   lcm(a,b)  (a*b)/__gcd(a,b)
    #define   vsort(v)    sort(v.begin(), v.end());
    #define   vsortr(v)   sort(v.rbegin(), v.rend());
    #define   it(i,n)     for(ll int i=0 ; i<n ; i++)
    #define   itt(i,k,n)  for(ll int i=k ; i<n ; i++)
    #define   its(i,n)    for(ll int i=n-1 ; i>=0 ; i--)
    #define   input(a)    for(auto &it : a){cin>>it;}
    #define   output(a)   for(auto &it : a){cout<<it<<" ";}
    #define   yes         cout<<"YES"<<endl;
    #define   no          cout<<"NO"<<endl;
 
    using namespace std;
 
    // Binary Exponentiation
 
    int binpow(ll int a, ll int b){
    ll int n=1e9+7;
    if( a== 0 && b == 0){
        return 1;
    }
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
    bool check(vll a , ll int n){
        it(i,n){
            if(a[i]>0){
                return false;
            }
        }
        return true;
    }
    //Main function
 
    int main(){
    TimeTravel
    ll int t=1 ;
    // cin>>t;
    while(t--){
        //  Mera Ghatiya Solution ;(
        ll int n;
        cin >> n;
        vll a(n);
        input(a);
        ll int currsum = 0;
        ll int maxsum = 0;
        it(i,n){
            currsum += a[i];
            if(currsum<0){
                currsum=0;
            }
            maxsum = max(currsum,maxsum);
        }
        if(check(a,n)){
            vsortr(a);
            cout << a[0] << endl;
        }
        else{
        cout << maxsum << endl;
        }
    
    }
        return 0;
}
