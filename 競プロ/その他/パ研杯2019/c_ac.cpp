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
  vvll a(n,vll(m));
  rep(i,n)rep(j,m) cin>>a[i][j];
  ll ans=0;
  rep(t_0,m)for(int t_1=t_0+1;t_1<m;t_1++){
    ll score=0;
    rep(i,n){
      score+=max(a[i][t_0],a[i][t_1]);
    }
    ans=max(ans,score);
  }
  cout<<ans;
}
