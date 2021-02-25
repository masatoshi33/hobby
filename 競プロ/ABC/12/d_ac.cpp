#include <bits/stdc++.h>
#include <math.h>
#include <vector>
#include <queue>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;
using Graph = vector<vector<pair<int,int>>>;
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
  Graph g(n);
  rep(i,m){
    int a,b,t; cin>>a>>b>>t;
    a--;b--;
    g[a].push_back({b,t});
    g[b].push_back({a,t});
  }
  vvi c(n,vi(n));
  //初期化
  rep(i,n)rep(j,n) c[i][j]=INF;
  rep(i,n) c[i][i]=0;
  rep(i,n)for(auto x:g[i]){
    c[i][x.first]=x.second;
  }
  rep(i,n)rep(j,n)rep(k,n){
    c[j][k]=min(c[j][k],c[j][i]+c[i][k]);
  }
  vi ma(n);
  rep(i,n) ma[i]=0;
  rep(i,n)rep(j,n){
    ma[i]=max(ma[i],c[i][j]);
  }
  sort(ma.begin(),ma.end());
  cout<<ma[0]<<endl;
}
