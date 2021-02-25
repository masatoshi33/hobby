#include <bits/stdc++.h>
#include <queue>
#include <math.h>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int dp[101010];

int main(){
  int n;
  cin >> n;
  vector<int> h(n);
  rep(i,n) cin >> h[i];
  dp[0] = 0;
  dp[1] = abs(h[0]-h[1]);
  //rep(i,n) cout << h[i] << endl;
  rep(i,n){
    if(i==0) i+=2;
    dp[i] = min(dp[i-1]+abs(h[i]-h[i-1]),dp[i-2]+abs(h[i]-h[i-2]));
  }
  //rep(i,n-1) cout << dp[i] << endl;
  cout << dp[n-1] << endl;
}
