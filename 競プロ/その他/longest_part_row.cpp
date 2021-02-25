#include <bits/stdc++.h>
#include <math.h>
#include <vector>
#include <queue>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep_1 (i,j,n) for(int i=j;i<n;i++)
typedef long long ll;
typedef long l;
const ll l_INF = 1010101010101010;
const int INF = 1010101010;
const int dx[] = {-1,0,1,0,-1,-1,1,1};
const int dy[] = {0,-1,0,1,1,-1,1,-1};

int main(){
  int n; cin>>n;
  int c[n],dp[101010];
  rep(i,n) cin>>c[i];
  rep(i,n) dp[i]=INF;
  rep(i,n){
    int key=lower_bound(dp,dp+n,c[i])-dp;
    cout<<key<<endl;
    dp[key]=c[i];
  }
  int ans=0;
  rep(i,n) if(dp[i]!=INF) ans=i+1;
  rep(i,n) cout<<c[i]<<" ";
  cout<<endl;
  rep(i,n) cout<<dp[i]<<" ";
  cout<<endl;
  cout<<ans<<endl;
}
