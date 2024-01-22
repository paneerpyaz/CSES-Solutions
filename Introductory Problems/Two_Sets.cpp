#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
	ll int n,k;
	cin>>n;
	k=n*(n+1)/2;
	if(k%2!=0){
		cout<<"NO"<<endl;
	}
	else{
		cout<<"YES"<<endl;
		
		if(n%2==0){
			cout<<n/2<<endl;
			for(ll int i=1 ; i<=n/4 ; i++){
				cout<<i<<" ";
			}
			for(ll int i=3*n/4+1;  i<=n ; i++){
				cout<<i<<" ";
			}
			cout<<endl;
			cout<<n/2<<endl;
			for(ll int i=n/4+1 ; i<=3*n/4 ; i++){
				cout<<i<<" ";
			}
		}
		else{
			cout<<n/2<<endl;
			for(ll int i=1;i<=n/4 ; i++){
				cout<<i<<" ";
			}
			for(ll int i=3*n/4+1;  i<=n ; i++ ){
				cout<<i<<" ";
			}
			cout<<endl;
			cout<<n/2+1<<endl;
			for(ll int i=n/4+1 ; i<=3*n/4 ; i++){
				cout<<i<<" ";
			}
		}
	}
	return 0;
	
}
