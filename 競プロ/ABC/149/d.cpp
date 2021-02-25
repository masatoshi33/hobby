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

int judge(char x){
  if(x=='r') return 2;
  else if(x=='s') return 0;
  else return 1;
}

int main(){
  int n,k;
  cin>>n>>k;
  int gomi=n/k+1;
  int dp[k][gomi][3];
  rep(i,k) rep(j,gomi) rep(l,3) dp[i][j][l] = 0;
  vi h(3);
  cin>>h[0]>>h[1]>>h[2];
  string t;
  cin>>t;
  //rep(i,3) dp[0][i]=0;
  rep(i,k){
    int m=(n-i)/k;
    rep(j,m){
      char y = t[j*k+i];
      int x = judge(y);
      //int x=0;
      /*rep(l,3){
        if(l!=x){
          dp[i][j][x]=max(dp[i][j][x],dp[i][j-1][l]+h[x]);
          rep(p,3){
            if(p!=l) dp[i][j][l]=max(dp[i][j][l],dp[i][j-1][p]);
          }
        }
      }*/
      if(x==0){
        dp[i][j][0]=max(dp[i][j-1][1]+h[x],dp[i][j-1][2]+h[x]);
        dp[i][j][1]=max(dp[i][j-1][0],dp[i][j-1][2]);
        dp[i][j][2]=max(dp[i][j-1][1],dp[i][j-1][0]);
      }
      if(x==1){
        dp[i][j][0]=max(dp[i][j-1][1],dp[i][j-1][2]);
        dp[i][j][1]=max(dp[i][j-1][0]+h[x],dp[i][j-1][2]+h[x]);
        dp[i][j][2]=max(dp[i][j-1][1],dp[i][j-1][0]);
      }
      if(x==2){
        dp[i][j][0]=max(dp[i][j-1][1],dp[i][j-1][2]);
        dp[i][j][1]=max(dp[i][j-1][0],dp[i][j-1][2]);
        dp[i][j][2]=max(dp[i][j-1][1]+h[x],dp[i][j-1][0]+h[x]);
      }
    }
  }
  ll ans=0;
  rep(i,k){
    int ans_0=0;
    rep(j,3){
      int m=(n-i)/k;
      ans_0+=max(ans_0,dp[i][m-1][j]);
    }
    cout << ans_0 << endl;
    ans += ans_0;
  }
  cout << ans;
}
