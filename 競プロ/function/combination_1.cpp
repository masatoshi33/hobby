#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long = ll;
const long long mod=1000000007;

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
