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

//ワーシャルフロイト法
int main(){
  int n,m,l; cin>>n>>m>>l;
  Graph dist(n,vi(n,INF));
  rep(i,n) dist[i][i]=0;
  rep(i,m){
    int a,b,c; cin>>a>>b>>c;
    a--;b--;
    dist[a][b]=dist[b][a]=c;
  }
  rep(k,n)rep(i,n)rep(j,n) dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
  vvi dist2(n,vi(n,INF));
  rep(i,n)rep(j,n){
    if(dist[i][j]<=l) dist2[i][j]=1;
  }
  rep(k,n)rep(i,n)rep(j,n) dist2[i][j]=min(dist2[i][j],dist2[i][k]+dist2[k][j]);
  int q; cin>>q;
  rep(i,q){
    int s,t; cin>>s>>t; s--; t--;
    int ans=dist2[s][t]-1;
    if(dist2[s][t]==INF) ans=-1;
    cout<<ans<<endl;
  }
}
