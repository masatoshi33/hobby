#include <bits/stdc++.h>
#include <math.h>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
const ll INF = 1010101010;
int dp[3][101010];

int max_3(int x, int y, int z){
  if(x>=y&&x>=z) return x;
  else if(y>=z&&y>=x) return y;
  else return z;
}

int main(){
  int n;
  cin >> n ;
  vector<int> a(n), b(n), c(n);
  rep(i,n) cin >> a[i] >> b[i] >> c[i];
  rep(i,n+1){
    rep(j,3){
      if(i==0) continue;
      dp[j][i] = INF;
    }
  }
  rep(i,n){
    dp[0][i+1] = max(dp[1][i],dp[2][i]) + a[i];
    dp[1][i+1] = max(dp[0][i],dp[2][i]) + b[i];
    dp[2][i+1] = max(dp[1][i],dp[0][i]) + c[i];
  }
  /*rep(i,n+1){
    rep(j,3){
      cout << dp[j][i] << " ";
    }
    cout << endl;
  }*/
  int ans = max_3(dp[0][n],dp[1][n],dp[2][n]);
  cout << ans << endl;
}
