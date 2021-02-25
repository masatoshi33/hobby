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
vector<ll> h,s;
ll n;

bool check(ll m){
  vll limit(n);
  rep(i,n){
    //全てをm以下にする時それを達する秒数を計算
    //もしそもそもhがm以下でに無理なら失敗
    if(h[i]<=m) limit[i]=(m-h[i])/s[i];
    else return false;
  }
  sort(limit.begin(),limit.end());
  //必要な秒数が0,1,2,..となるならok
  rep(i,n){
    if(limit[i]<i)return false;
  }
  return true;
}

int main(){
  cin>>n;
  h.resize(n);
  s.resize(n);
  rep(i,n) cin>>h[i]>>s[i];
  ll ng=0;
  ll ok=10000000000000000;
  while(abs(ok-ng)>1){ //範囲がただ一つの整数を示すまで繰り返す
    ll m=(ok+ng)/2;
    if(check(m)) ok=m; //もしokなら余裕があるため範囲を小さい方にずらす
    else ng=m;
  }
  cout<<ok<<endl;
}
