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
double dp[3030][3030];

int main(){
  int n;
  cin >> n;
  vector<double> p(n);
  rep(i,n){
    cin >> p[i];
  }
  dp[0][0]=1.0;
  /*rep(i,n) cout <<p[i]<<" ";
  cout << endl;*/
  for(int i=1;i<n+1;i++){
    for(int j=0;j<n+1;j++){
      dp[i][j]+=dp[i-1][j]*(1-p[i-1]);
      dp[i][j]+=dp[i-1][j-1]*p[i-1];
    }
  }
  double ans=0;
  for(int i=(n+2)/2;i<n+1;i++){
    ans += dp[n][i];
  }
  /*rep(i,n){
    cout << dp[1][i] <<" ";
  }*/
  //cout <<endl;
  cout << ans;
}
