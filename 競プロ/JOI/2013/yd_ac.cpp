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
  int d,n; cin>>d>>n;
  vector<int> t(d); rep(i,d) cin>>t[i];
  vector<int> a(n),b(n),c(n); rep(i,n) cin>>a[i]>>b[i]>>c[i];
  int dp[210][210]; //dp[i][j]:i日目にきていく服がj-1番目の服である時の派手さの絶対値の合計の最大値
  rep(i,d+1)rep(j,n) dp[i][j]=0;
  rep(i,d-1){
    rep(j,n){ //i日目に着る服
      if(a[j]>t[i+1]||b[j]<t[i+1]) continue;
      rep(k,n){ //k:一個前の服
        if(a[k]>t[i]||b[k]<t[i]) continue;
        dp[i+1][j]=max(dp[i+1][j],dp[i][k]+abs(c[j]-c[k]));
      }
    }
  }
  int ans=0;
  rep(i,n){
    ans=max(ans,dp[d-1][i]);
  }
  cout<<ans<<endl;
}
