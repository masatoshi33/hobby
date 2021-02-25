#include <bits/stdc++.h>
#include <math.h>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
const ll INF = 101010101000;
ll dp[110][101010]; //N*Vの配列。最低の重さ。

int main(){
  int n, W;
  ll max_v = 0;
  cin >> n >> W;
  vector<ll> w(n), v(n);
  rep(i,n) cin >> w[i] >> v[i];
  rep(i,n) max_v += v[i];
  //初期化
  rep(i,n+1){
    rep(j,max_v+1){
      dp[i][j] = INF;
    }
  }
  dp[0][0] = 0;

  rep(i,n){
    ll w_i = w[i];
    ll v_i = v[i];
    rep(j,max_v+1){
      if(j-v_i>=0) dp[i+1][j] = min(dp[i][j],dp[i][j-v_i]+w_i);
      else dp[i+1][j] = min(dp[i][j],dp[i+1][j]);
    }
  }
  /*rep(i,n+1){
    rep(j,max_v+1){
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }*/
  ll ans = 0;
  rep(i,max_v+1){
    if(dp[n][i]<=W){
      ans = i;
    }
  }
  cout << ans << endl;
}
