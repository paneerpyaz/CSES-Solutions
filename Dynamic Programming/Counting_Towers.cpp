#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
#define ll long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
 
const int MOD1 = 998244353;
const int MOD = 1e9+7;
 
class Mint{
  public:
  ll val;
  static ll mod_exp(ll a, ll b){ ll res=1;   a=a%MOD; while(b>0){ if(b%2==1) res=(res*a)%MOD; b/=2; a=(a*a)%MOD; } return res; }
  static ll gcdExtended(ll a, ll b, ll *x, ll *y) { if (a == 0) { *x = 0, *y = 1; return b; } ll x1, y1; ll gcd = gcdExtended(b%a, a, &x1, &y1);*x = y1 - (b/a) * x1; *y = x1; return gcd; }
  static ll modInverse(ll a) { ll x, y; 	ll g = gcdExtended(a, MOD, &x, &y); g++; ll res = (x%MOD);	if(res < 0) res += MOD;	return res;} 
  Mint(){	val = 0;} 
  Mint(ll x){	val = x%MOD;	if(val < 0) val += MOD;}
  Mint& operator +=(const Mint &other){	val += other.val;	if(val >= MOD) val -= MOD; return (*this); }
  Mint& operator -=(const Mint &other){   val -= other.val;if(val < 0) val += MOD;  return (*this); }
  Mint& operator *=(const Mint &other){	val = (val * other.val)%MOD; return (*this); }
  Mint& operator /=(const Mint &other){	val = (val * modInverse(other.val)) % MOD; return (*this); }
  Mint& operator =(const Mint &other) { 	val = other.val; return (*this); }
  Mint operator +(const Mint &other) const {	return Mint(*this) += other; }
  Mint operator -(const Mint &other) const {	return Mint(*this) -= other; }
  Mint operator *(const Mint &other) const {	return Mint(*this) *= other; }
  Mint operator /(const Mint &other) const {	return Mint(*this) /= other; }
  bool operator ==(const Mint &other) const {   return val == other.val; }
  Mint operator ++() { ++val; if(val == MOD) val = 0; return (*this); }
  Mint operator ++(int) { val++; if(val == MOD) val = 0; return Mint(val-1); }
  Mint operator --() { --val; if(val == -1) val = MOD-1; return (*this); }
  Mint operator --(int) { val--; if(val == -1) val = MOD-1; return Mint(val+1); }
  template<typename T>
  Mint& operator ^=(const T &other){   val = mod_exp(val, other); return (*this); }
  template<typename T>
  Mint operator ^(const T &other) const {  return Mint(*this) ^= other; }
  Mint& operator ^=(const Mint &other){   val = mod_exp(val, other.val); return (*this); }
  Mint operator ^(const Mint &other) const {  return Mint(*this) ^= other; }
  template<typename T>
  explicit operator T() {	return (T)val; }
  template<typename T>
  friend Mint operator +(T other, const Mint &M){	return Mint(other) + M; }
  template<typename T>
  friend Mint operator -(T other, const Mint &M){	return Mint(other) - M; }
  template<typename T>
  friend Mint operator *(T other, const Mint &M){	return Mint(other) * M; }
  template<typename T>
  friend Mint operator /(T other, const Mint &M){	return Mint(other) / M; }
  template<typename T>
  friend Mint operator ^(T other, const Mint &M){	return Mint(other) ^ M; }
  friend std::ostream &operator << (std::ostream &output, const Mint &M){  return output << M.val; }
  friend std::istream &operator >> (std::istream &input, Mint &M) { input >> M.val;	M.val %= MOD;	return input;}
};

Mint dp[1000001][2];
 
void solve(){
  int n;
  cin >> n;
  cout << dp[n][0] + dp[n][1] << endl;
} 
 
signed main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  dp[1][0] = 1;
  dp[1][1] = 1;
  for(int i = 2 ; i <= 1000000 ; i++){
    dp[i][0] = 4*dp[i-1][0] + dp[i-1][1];
    dp[i][1] = 2*dp[i-1][1] + dp[i-1][0];
  }
  int tt = 1;
  cin >> tt;
  while(tt--){
    solve();
  }
  return 0;
}