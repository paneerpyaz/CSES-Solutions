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
bool customComparator(const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
    if (a.first.first == b.first.first) {
        return a.first.second > b.first.second;
    }
    return a.first.first < b.first.first;
}
void samadhaan(){
    int n;
	cin >> n;
	vector<pair<pair<int,int>,int>>a(n);
	it(i,0,n){
		cin >> a[i].F.F>> a[i].F.S;
		a[i].S = i;
	}
	sort(all(a),customComparator);
	vll does_it_contain(n,0);
	vll contained_by_anyone(n,0);
	
	pbds A;
	it(i,0,n){
		A.insert(a[i].F.S);
		if(A.size()-A.order_of_key(a[i].F.S)-1 > 0){
			contained_by_anyone[a[i].S] = A.size()-A.order_of_key(a[i].F.S)-1;
		}
	}
	it(i,0,n){
		swap(a[i].F.F,a[i].F.S);
	}
	sort(all(a),customComparator);
	pbds B;
	it(i,0,n){
		B.insert(a[i].F.S);
		if(B.size()-B.order_of_key(a[i].F.S)-1 > 0){
			does_it_contain[a[i].S] = B.size()-B.order_of_key(a[i].F.S)-1;
		}
	}
	see(does_it_contain);
	see(contained_by_anyone);
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
