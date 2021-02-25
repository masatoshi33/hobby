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
  int num[n]; rep(i,n) cin>>num[i];
  ll dp[n-1][21];
  rep(i,n-1)rep(j,21) dp[i][j]=0;
  int z=num[0];
  dp[0][z]=1;
  rep(i,n-2){
    int x=num[i+1];
    rep(j,21){
      if(j-x>=0) dp[i+1][j-x]+=dp[i][j];
      if(j+x<=20) dp[i+1][j+x]+=dp[i][j];
    }
  }
  int y=num[n-1];
  cout<<dp[n-2][y]<<endl;
}
