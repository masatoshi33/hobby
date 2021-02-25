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
int dp[3010][3010];

int main(){
  string s,t;
  cin >> s >> t;
  int s_l=s.length()+1, t_l=t.length()+1;
  rep(i,s_l){
    rep(j,t_l){
      dp[i][j]=0;
    }
  }
  for(int i=1;i<s_l;i++){
    for(int j=1;j<t_l;j++){
      dp[i][j]=max(dp[i][j],dp[i-1][j]);
      dp[i][j]=max(dp[i][j],dp[i][j-1]);
      if(s[i-1]==t[j-1]) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
    }
  }
  /*rep(i,s_l){
    rep(j,t_l){
      cout << dp[i][j];
    }
    cout << endl;
  }*/
  string ans="";
  int x=s_l-1,y=t_l-1;
  while(dp[x][y]!=0){
    if(dp[x][y]==dp[x][y-1]) y--;
    else if(dp[x][y]==dp[x-1][y]) x--;
    else{
      ans = s[x-1]+ans;
      x--;y--;
    }
  }
  cout << ans;
}
