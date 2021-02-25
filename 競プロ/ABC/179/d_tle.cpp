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
const ll mod=998244353;
int dp[201010];

int f(int x){
  if(dp[x]!=INF) retur dp[x];
  int ans=0;
  for(int i=1;i<=x;i++) if(judge.count(i)) ans+=f(x-i);
  return ans;
}

int main(){
  int n,k; cin>>n>>k;
  vi l(k), r(k);
  rep(i,k){
    cin>>l[i]>>r[i];
  }
  set<int> judge;
  rep(i,201010){
    rep(j,k){
      if(i>=l[j]&&i<=r[j]&&!(judge.count(i))) judge.insert(i);
    }
  }
  rep(i,201010) dp[i]=INF;
  dp[0]=1;
  /*rep(i,n+1){
    if(i==0) continue;
    for(int j=1;j<=i;j++) if(judge.count(j)) dp[i]+=dp[i-j];
  }*/
  //rep(i,n) cout<<dp[i]<<endl;
  int ans2=f(n-1);
  ans2%=mod;
  cout<<ans2<<endl;
}
