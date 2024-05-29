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
int n,m;
vvll g;
vector<bool>vis;
vll d;
vll p;
 
void bfs(int source){
    queue<int>q;
    vis[source] = true;
    q.push(source);
    p[source] = -1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto u : g[v]){
            if(!vis[u]){
                q.push(u);
                d[u] = d[v]+1;
                p[u] = v;
                vis[u] = true;
            }
        }
    }
}
 
void samadhaan(){
    cin >> n >> m;
    g.resize(n+1);
    vis.resize(n+1);
    d.resize(n+1);
    d.assign(n+1,1);
    p.resize(n+1);
    it(i,0,m){
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    bfs(1);
    if(d[n] == 1){
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    vll ans;
    int num = n;
    while(p[num] != -1){
        ans.pb(num);
        num = p[num];
    }
    ans.pb(1);
    reverse(all(ans));
    int z = ans.size();
    cout << z << endl;
    see(ans);
 
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
