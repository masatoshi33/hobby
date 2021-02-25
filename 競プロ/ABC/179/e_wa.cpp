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
ll m;

// a^nのmod
ll modpow(ll a,ll n){
  ll ans=1;
  while(n!=0){
      if(n&1)ans=ans*a%m;
      a=a*a%m;
      n=n>>1;
  }
  return ans;
}
// 逆元の計算
ll modinv(ll a){
  return modpow(a,m-2);
}

int main(){
  ll n,x; cin>>n>>x>>m;
  /*ll ans=(x*x)%m;
  ans*=(modpow(x*x,n)-1);
  ans%=m;
  ans*=modinv(x*x-1);
  ans+=x;
  ans%=m;
  if(ans<0) ans+=m;*/
  ll ans_0,ans_1;
  int index;
  set<int> judge;
  vi judge2;
  bool judge3=false;
  vi judge4(101010);
  ll y=x;
  rep(i,n){
    if(y==0){
      judge3=true;
      break;
    }
    if(judge.count(y)){
      ans_0=i+1;
      index=y;
      break;
    }
    if(!(judge.count(y))){
      judge.insert(y);
      judge2.push_back(y);
      judge4[y]=i;
    }
    y=y*y;
    y%=m;
  }
  ll sum=0;
  rep(i,judge4[index]) sum+=judge2[i];
  n-=judge4[index];
  ans_0-=judge4[index];
  for(auto z:judge) sum+=z;
  ans_1=(n/ans_0)*sum;
  if(judge3){
    cout<<sum<<endl;
    return 0;
  }
  for(auto z:judge2) ans_1+=z;
  cout<<ans_1<<endl;
}
