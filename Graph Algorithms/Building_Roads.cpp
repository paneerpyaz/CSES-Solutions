#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vpll vector<pair<int,int>>
#define vll vector<int>
#define vvll vector<vector<int>>
#define ld long double
#define F first
#define S second
#define pb push_back
#define it(i,k,n) for(int i=k ; i<n ; i++)
#define rit(i,k,n) for(int i=n-1 ; i>=k ; i--)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define inp(v) for(auto &it:v)cin>>it;
#define see(v) for(auto &it:v){cout<<it<<" ";}cout<<endl;
#define pr(it,v) for(auto &it:v){cout<<it.F<<" "<<it.S<<endl;}
#define CEIL(x,y)  (int)ceil(1.0 * x/y)
const int MOD1 = 998244353;
const int MOD2 = 1e9+7;
vector<vector<int>>g;
vector<bool>vis;
 
void dfs(int v){
    vis[v] = true;
    for(auto u : g[v]){
        if(!vis[u]){
            dfs(u);
        }
    }
}
 
void samadhaan(){
    int n,m;
    cin >> n >> m;
    g.resize(n+1);
    vis.resize(n+1);
    it(i,0,m){
        int u,v;
        cin >> u >> v;
        g[v].pb(u);
        g[u].pb(v);
    }
    vll disco;
    for(int i =1 ; i<=n ; i++){
        if(!vis[i]){
            disco.pb(i);
            dfs(i);
        }
    }
    int z = disco.size();
    cout << z-1 << endl;
    it(i,0,z-1){
        cout << disco[i] << " " << disco[i+1] << endl;;
    }
 
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int lim = 1;
while(lim-->0){
    samadhaan();
    }
    return 0;
}
