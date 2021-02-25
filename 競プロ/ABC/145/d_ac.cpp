#include <bits/stdc++.h>
#include <math.h>
#include <vector>
#include <queue>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep_1 (i,j,n) for(int i=j;i<n;i++)
typedef long long ll;
typedef long l;
const ll l_INF = 1010101010101010;
const int INF = 1010101010;
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
const ll mod = 1000000007;
ll k_mod(ll x){
  ll ans=1;
  rep(i,x){
    ans*=(i+1);
    ans%=mod;
  }
  return ans;
}
ll modpow(ll x, ll n){
  ll ans=1;
  while(n!=0){
    if(n&1) ans=ans*x%mod;
    x=x*x%mod;
    n=n>>1;
  }
  return ans;
}
ll invmod(ll x){
  return modpow(x,mod-1);
}
ll modcom(ll x, ll y){
  ll ans=1LL;
  ans*=k_mod(x);
  ans%=mod;
  ll z=modpow(k_mod(y),1000000005);
  z*=modpow(k_mod(x-y),1000000005);
  z%=mod;
  ans*=z;
  ans%=mod;
  /*ans*=invmod(k_mod(y));
  cout<<ans<<endl;
  ans%=mod;
  cout<<ans<<endl;
  ans*=invmod(k_mod(x-y));
  cout<<ans<<endl;
  ans%=mod;
  cout<<ans<<endl;*/
  return ans;
}
int main(){
  ll x,y; cin>>x>>y;
  if((x+y)%3!=0){
    cout<<0<<endl;
    return 0;
  }
  ll a,b;
  a=(x+y)/3;
  b=abs(x-y);
  b=(a-b)/2;
  if(b<0){
    cout<<0<<endl;
    return 0;
  }
  //aCbを調べれば良い

  //cout<<k_mod(a)<<endl;
  //cout<<invmod(k_mod(a))<<endl;
  cout<<modcom(a,b)<<endl;
}
