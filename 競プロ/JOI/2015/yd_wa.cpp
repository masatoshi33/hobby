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
  int n,m; cin>>n>>m;
  vll d(n); rep(i,n) cin>>d[i];
  vll c(m); rep(i,m) cin>>c[i];
  ll dp[1010][1010]; //dp[i][j]:i個目の都市にj日目にいる時の中で疲労度が最小のもの
  rep(i,1010)rep(j,1010) dp[i][j]=l_INF;
  rep(i,m) dp[0][i]=0;
  rep(i,n){
    rep(j,m){
      for(int k=j+1;k<=m;k++){
        dp[i+1][k]=min(dp[i+1][k],dp[i][j]+d[i]*c[k]);
      }
    }
  }
  ll ans=l_INF;
  /*rep(i,m){
    rep(j,n+1){
      cout<<dp[j][i]<<" ";
    }
    cout<<endl;
  }*/
  rep(i,m) ans=min(ans,dp[n][i]);
  cout<<ans<<endl;
}
