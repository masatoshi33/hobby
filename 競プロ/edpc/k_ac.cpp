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
int dp[101010];

int main(){
  int n,k;
  cin >> n >> k;
  vi a(n);
  rep(i,n) cin >> a[i];
  dp[0]=2;
  for(int i=1;i<k+1;i++){
    rep(j,n){
      int x = a[j];
      if(i-x>=0&&dp[i-x]==2){
        dp[i]=1;
      }
    }
    if(dp[i]==0) dp[i]=2;
  }
  /*rep(i,n){
    cout << a[i] << " ";
  }
  cout << endl;*/
  /*rep(i,k+1){
    cout << dp[i] << " ";
  }
  cout << endl;*/
  if(dp[k]==2) cout << "Second";
  else cout << "First";
}
