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

vector<string> fun(int n){
    vector<string>v ;
    if(n == 1){
        v.pb("1");
        v.pb("0");
        return v;
    }
    vector<string>temp = fun(n-1);
    int k = temp.size();
    it(i,k){
        v.pb("0" + temp[i]);
    }
    its(i,k){
        v.pb("1"+temp[i]);
    }
    return v;
}
int main(){
TimeTravel
    int n;
    cin >> n;
    vector<string> v;
    v = fun(n);
    for(auto it : v){
        cout << it << endl;
    }
    return 0;
}
