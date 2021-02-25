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
  vector<vector<char>> s(5,vector<char>(n));
  rep(i,5)rep(j,n) cin>>s[i][j];
  int dp[3][n];
  rep(i,n){
    int r=0,b=0,w=0,k=0;
    rep(j,5){
      if(s[j][i]=='R') r++;
      if(s[j][i]=='B') b++;
      if(s[j][i]=='W') w++;
      if(s[j][i]=='#') k++;
    }
    if(i==0){
      dp[0][i]=5-r;
      dp[1][i]=5-b;
      dp[2][i]=5-w;
      continue;
    }
    dp[0][i]=min(dp[1][i-1],dp[2][i-1])+5-r;
    dp[1][i]=min(dp[0][i-1],dp[2][i-1])+5-b;
    dp[2][i]=min(dp[1][i-1],dp[0][i-1])+5-w;
  }
  int ans=INF;
  rep(i,3) ans=min(ans,dp[i][n-1]);
  cout<<ans<<endl;
}
