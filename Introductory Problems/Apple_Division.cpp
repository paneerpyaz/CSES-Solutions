#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
#define int long long
#define vpll vector<pair<int,int>>
#define vll vector<int>
#define vvll vector<vector<int>>
#define ld long double
#define F first
#define S second
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define inp(v) for(auto &it:v)cin>>it;
#define it(i,k,n) for(int i=k ; i<n ; i++)
#define rit(i,k,n) for(int i=n-1 ; i>=k ; i--)
#define see(v) for(auto &it:v){cout<<it<<" ";}cout<<endl;
#define pr(it,v) for(auto &it:v){cout<<it.F<<" "<<it.S<<endl;}
#define CEIL(x,y)  (int)ceil(1.0 * x/y)
 
const int MOD1 = 998244353;
const int MOD2 = 1e9+7;
void samadhaan(){
    int n;
   cin >> n;
   vll a(n);
   inp(a);
   vector<string>s;
   for(int i = 1 ; i <= 1048574; i++){
      s.pb(std::bitset<20>(i).to_string());
   }
   for(int i = 0 ; i < 1048574 ; i++){
       reverse(all(s[i]));
   }
    int ans = 1e20;
   for(int i = 0 ; i < 1048574 ; i++){
       string r = s[i];
       int sum1 = 0;
       int sum2 = 0;
       for(int j = 0 ; j < n ; j++){
           if(r[j] == '0') sum1 += a[j];
           else sum2 += a[j];
       }
       ans = min(ans,abs(sum1-sum2));
   }
   cout << ans << endl;
}
 
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int lim = 1;
// cin >> lim;
while(lim-->0){
    samadhaan();
    }
    return 0;
}
