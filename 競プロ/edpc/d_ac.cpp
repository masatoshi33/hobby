#include <bits/stdc++.h>
#include <math.h>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
const ll INF = 1010101010;
ll dp[110][101010]; //N*Wの配列

int max_3(int x, int y, int z){
  if(x>=y&&x>=z) return x;
  else if(y>=z&&y>=x) return y;
  else return z;
}

int main(){
  int n, W;
  cin >> n >> W;
  vector<int> w(n), v(n);
  rep(i,n) cin >> w[i] >> v[i];

  rep(i,n){
    int w_i = w[i];
    int v_i = v[i];
    rep(j,W+1){
      if(j-w_i>=0) dp[i+1][j] = max(dp[i][j],dp[i][j-w_i]+v[i]);
      else dp[i+1][j] = dp[i][j];
    }
  }
  /*rep(i,n+1){
    rep(j,W+1){
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }*/
  cout << dp[n][W] << endl;
}
