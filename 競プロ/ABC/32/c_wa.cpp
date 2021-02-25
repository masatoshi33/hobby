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
const ll l_INF = 101010101000;
const int INF = 1010101010;
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;

int main(){
  ll n,k;
  cin>>n>>k;
  vector<ll> s(n);
  rep(i,n) cin>>s[i];
  rep(i,n){
    if(s[i]==0){
      cout<<n<<endl;
      return 0;
    }
  }
  //しゃくとり法
  int e=0; //b:区間開始,e:区間終了
  ll x=1;
  int max_l=0;
  for(int b=0;b<n;b++){
    while(e<n&&(x*s[e])<=k){
      x*=s[e];
      e++;
    }
    max_l=max(e-b,max_l);
    if(b==e) e++;
    else x/=s[b];
  }
  cout<<max_l;
}
