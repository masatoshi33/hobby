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
const ll mod=1000000007;


// x!のmod
ll kaijou_mod(ll n){
  ll ans=1;
  rep(i,n){
    ans*=(i+1);
    ans%=mod;
  }
  return ans;
}
// a^nのmod
ll modpow(ll a,ll n){
  ll ans=1;
  while(n!=0){
      if(n&1)ans=ans*a%mod;
      a=a*a%mod;
      n=n>>1;
  }
  return ans;
}
// 逆元の計算
ll modinv(ll a, ll m){
  return modpow(a,m-2);
}

long long com_mod(long long x, long long y){
  long long ans = 1;
  ans *= kaijou_mod(x);
  ans%=mod;
  ans *= modinv(kaijou_mod(y),mod);
  ans%=mod;
  ans *= modinv(kaijou_mod(x-y),mod);
  ans%=mod;
  return ans;
}

int main(){
  int s; cin>>s;
  ll ans=0;
  int x=s/3;
  rep(i,x){
    ans+=com_mod(s-2*i-3,i);
    //cout<<ans<<endl;
    ans%=mod;
  }
  cout<<ans<<endl;
}
