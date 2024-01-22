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
    string s ;
    cin >> s;
    ll int n = s.length();
    unordered_map<char,int>m;
    it(i,n){
        m[s[i]]++;
    }
    int cnt = 0;
    char odd;
    for(auto it : m){
        if(it.second%2 == 1){
            odd = it.first;
            cnt++;
        }
    }
    if(cnt>1 || (cnt == 1 && n%2==0)){
        cout << "NO SOLUTION " << endl;
    }
    else{
        string ans = "";
        string a = "";
        string b="";
        for(auto it : m){
            string str(it.second/2 , it.first);
            a=a+str;
            b=str+b;
        }
        if(cnt == 1){
           ans= a + odd + b;
        }
        else{
            ans=a+b;
        }
        cout << ans;
    }
    return 0;
}
