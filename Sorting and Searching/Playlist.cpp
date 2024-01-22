#include<bits/stdc++.h>;
#define ll long long
using namespace std;
 
void samadhaan(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(auto &it : a) cin >> it ;
    int res = 0;
    map<int,int>m;
    int j = 0;
    for(int i = 0; i < n ; i++){
        while( j < n && m[a[j]] < 1){
            m[a[j]]++;
            j++;
            
        }
        res = max( res , j - i);
        m[a[i]]--;
 
 
    }
    cout << res << endl;
}
 
int main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int tt = 1;
// cin >> tt;
while(tt--){
    samadhaan();
    }
    return 0;
}
