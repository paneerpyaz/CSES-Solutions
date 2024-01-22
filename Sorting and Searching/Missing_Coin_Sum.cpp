#include<bits/stdc++.h>;
using namespace std;
 
void samadhaan(){
    int n;
    cin >> n;
    int *a = new int[n];
    for(int i = 0 ; i<n ; i++) cin >> a[i];
    sort(a,a+n);
    long long sum = 0;
    for(int i = 0 ; i<n ; i++){
        if(1 + sum < a[i]){
            break;
        }
        sum += a[i];
    }
    cout << sum + 1 << endl;
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
