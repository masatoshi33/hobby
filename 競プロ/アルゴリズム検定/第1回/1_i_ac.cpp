#include <bits/stdc++.h>
#include <math.h>
#include <vector>
#include <queue>
#include <iomanip>
#include <string>
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
ll dp[1010][1030]; //mX2^n

ll min(ll x, ll y, ll z){
  if(x<=y&&x<=z) return x;
  else if(y<=z&&y<=x) return y;
  else return z;
}

int main(){
  int n, m;
  cin >> n >> m;
  vector<string> s(m);
  vector<ll> c(m);
  rep(i,m) cin >> s[i] >> c[i];
  vector<int> s_2(m);
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      if(s[i][j]=='Y'){
        s_2[i] += pow(2,j);
      }
    }
  }
  //rep(i,m) cout << s_2[i];
  //cout << endl;

  int set_num = pow(2,n);
  rep(i,m+1){
    rep(j,set_num){
      dp[i][j] = l_INF;
    }
  }
  dp[0][0] = 0;
  rep(i,m+1){
    rep(j,set_num){
      ll y = s_2[i];
      ll x = j|y;
      //cout << x << endl;
      if(dp[i][j]!=l_INF){
        dp[i+1][x] = min(dp[i][j]+c[i],dp[i+1][x],dp[i][x]);
        dp[i+1][j] = min(l_INF,dp[i+1][j],dp[i][j]);
    }
  }
  //rep(i,m) cout << c[i] << " ";
  //cout << endl;
  //確認用
  /*rep(i,m+1){
    rep(j,set_num){
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }*/
  if(dp[m-1][set_num-1]==INF) dp[m-1][set_num-1]=-1;
  cout << dp[m-1][set_num-1] << endl;
}
