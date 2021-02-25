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
  int n,m; cin>>n>>m;
  vi a(m),b(m);
  vll avail(m);
  int dp[(1<<n)];
  rep(i,(1<<n)) dp[i]=INF;
  dp[0]=0;
  rep(i,m){
    cin>>a[i]>>b[i];
    rep(j,b[i]){
      int x; cin>>x; x--;
      avail[i]+=(1<<x);
    }
  }
  rep(i,m){
    rep(j,(1<<n)){
      int x=(j|avail[i]);
      dp[x]=min(dp[j]+a[i],dp[x]);
    }
  }
  ll ans=0;
  rep(i,n) ans+=(1<<i);
  //rep(i,n) cout<<avail[i]<<" ";
  //cout<<endl;
  /*rep(j,(1<<n)){
    if(dp[j]==INF) cout<<"INF"<<" ";
    else cout<<dp[j]<<" ";
  }*/
  //cout<<ans<<endl;
  if(dp[ans]==INF) cout<<-1<<endl;
  else cout<<dp[ans]<<endl;
}
