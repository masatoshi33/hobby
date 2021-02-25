#include <bits/stdc++.h>
#include <math.h>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
const ll INF = 1010101010;
int dp[101010];

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  rep(i,n) cin >> h[i];
  rep(i,n) dp[i] = INF;
  dp[0] = 0;
  //rep(i,n) cout << h[i] << endl;
  rep(i,n){
    if(i==0) continue;
    for(int j=1;j<=k;j++){
      if(i-j>=0) dp[i] = min(dp[i],dp[i-j]+abs(h[i]-h[i-j]));
    }
  }
  //rep(i,n-1) cout << dp[i] << endl;
  cout << dp[n-1] << endl;
}
