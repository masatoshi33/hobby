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

int main(){
  int n; cin>>n;
  vi c(n); rep(i,n) cin>>c[i];
  /* o(n^2)で却下
  vi num;
  int dp[n+10][n+10];
  rep(i,n+1)rep(j,n+1) dp[i][j]=INF;
  dp[0][0]=0;
  rep(i,n){
    rep(j,i+1){
      //dp[i+1][j+1]=dp[i][j+1];
      if(dp[i][j]<c[i]) dp[i+1][j+1]=c[i];
      if(dp[i][j+1]!=INF) dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j+1]);
    }
  }
  int ans=0;
  rep(i,n+1){
    rep(j,n+1){
      cout<<dp[i][j]<<" ";
    }
    cout<<endl;
  }
  rep(i,n+1) if(dp[n][i]!=INF) ans=max(ans,i);
  cout<<n-ans<<endl;
  */
  int dp[30001];
  rep(i,30001) dp[i]=INF;
  rep(i,n){
    int key=lower_bound(dp,dp+n,c[i])-dp;
    dp[key]=c[i];
  }
  int ans=0;
  rep(i,30001){
    if(dp[i]==INF){
      ans=i; break;
    }
  }
  ans=n-ans;
  cout<<ans<<endl;
}
