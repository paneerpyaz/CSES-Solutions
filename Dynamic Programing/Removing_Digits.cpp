#include<bits/stdc++.h>;
using namespace std;
 
// #define int long long
#define ld long double
#define F first
#define S second
#define it(i,k,n) for(int i=k ; i<n ; i++)
#define rit(i,k,n) for(int i=n-1 ; i>=k ; i--)
#define all(v) v.rbegin(),v.rend()
#define input(v) for(auto &it:v)cin>>it;
#define output(v) for(auto &it:v){cout<<it<<" ";}cout<<endl;
#define CEIL(x,y)  (int)ceil(1.0 * x/y)
const int MOD1 = 998244353;
const int MOD2 = 1e9+7;
 
void samadhaan(){ 
    int n ;
    int cnt = 0;
    cin >> n;
    while(n > 0){
        string s = to_string(n);
        int num = -1;
        int z = s.length();
        it(i,0,z){
            num = max(num,int(s[i]-48));
        }
        n -= num;
        cnt++;
    }
    cout << cnt << endl;
}   
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int tt = 1;
// cin >> tt;
while(tt-->0){
    samadhaan();
    }
    return 0;
}
