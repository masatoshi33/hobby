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
  vll a(n); rep(i,n) cin>>a[i];
  ll dp[n*2][n*2];
  rep(i,n*2)rep(j,n*2) dp[i][j]=0;
  rep(i,n*2-1){ //区間幅
    rep(j,n*2-1){ //区間の始点
      if(i==0) dp[j][j+i]=a[j];
      if(i==0&&j>n-1) dp[j][j+i]=a[j-n+1];
      else{
        if(i%2==0){
          dp[j][j+i]=max(dp[j][j+i-1]+a[j+i],dp[j+1][j+i]+a[j]);
          if(j==0) dp[j][j+i]=max(dp[j][j+i-1]+a[j+i],dp[j+1][j+i]+a[j]);
          if(j==n-1)dp[j][j+i]=max(dp[j][j+i-1]+a[j+i],dp[j+1][j+i]+a[j]);
        }else{
          if(a[j]>a[j+i]) dp[j][j+i]=dp[j+1][j+i];
          else dp[j][j+i]=dp[j][j+i-1];
        }
      }
    }
  }
  //rep(i,n) cout<<dp[i][i]<<" ";
  //cout<<endl;
  rep(i,n){
    rep(j,n){
      cout<<dp[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<dp[0][n-1]<<endl;
}
