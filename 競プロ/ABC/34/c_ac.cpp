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
const int mod = 1000000007;
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

ll pow_mod(ll x, ll n){
  ll ans=1;
  while(n != 0){
      if(n&1) ans = ans*x % mod;
      x = x*x % mod;
      n = n >> 1;
  }
  return ans;
}

ll kaijou_mod(ll n){
  ll ans=1;
  rep(i,n){
    ans*=(i+1);
    ans%=mod;
  }
  return ans;
}


int main(){
  ll w,h; cin>>w>>h;
  w--; h--;
  //w+hCwを求めれば良い
  //ans=(w+h)!/w!*h!
  ll ans=kaijou_mod(w+h);
  //cout<<kaijou_mod(w)<<endl;
  ll x=pow_mod(kaijou_mod(w),1000000005);
  //cout<<pow_mod(kaijou_mod(w),1000000005)<<endl;
  //cout<<kaijou_mod(h)<<endl;
  x%=mod;
  x*=pow_mod(kaijou_mod(h),1000000005);
  x%=mod;
  ans*=x;
  ans%=mod;
  cout<<ans<<endl;
}
