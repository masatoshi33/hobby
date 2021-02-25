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

ll dp[101010];

int main(){
  int n,l;
  cin >> n >> l;
  vi x(101010);
  rep(i,n){
    int y;
    cin>>y;
    x[y]++;
  }
  int t1,t2,t3;
  cin >>t1>>t2>>t3;
  rep(i,101010){
    dp[i] = l_INF;
  }
  dp[0]=0;
  rep(i,l){
    if(x[i]>0) dp[i]+=t3;
    dp[i+1] = min(dp[i+1],dp[i]+t1);
    dp[i+2] = min(dp[i+2],dp[i]+t1+t2);
    dp[i+4] = min(dp[i+4],dp[i]+t1+t2*3);
  }
  ll ans = min(dp[l],dp[l+1]-(t1+t2)/2);
  ans = min(ans,dp[l+2]-(t1+t2*3)/2);
  ans = min(ans,dp[l+3]-(t1+t2*5)/2);
  cout << ans;
}
