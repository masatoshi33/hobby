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
  //vector<vector<int>> g(n);
  vector<set<int>> g(n);
  rep(i,m){
    int a,b; cin>>a>>b;
    a--; b--;
    //g[a].push_back(b);
    //g[b].push_back(a);
    if(!(g[a].count(b)))g[a].insert(b);
    if(!(g[b].count(a)))g[b].insert(a);
  }
  int ans=1;
  vi dist(n);
  rep(i,n) dist[i]=INF;
  rep(i,n){
    if(dist[i]!=INF) continue;
    dist[i]=0;
    int cnt=1;
    for(auto x:g[i]){
      if(dist[x]!=INF) continue;
      for(auto y:g[x]){
        if(dist[y]!=INF) continue;
        g[i].insert(y);
      }
      dist[x]=0;
      cnt++;
    }
    ans=max(cnt,ans);
  }
  /*vi y(n); rep(i,n) y[i]=g[i].size()+1;
  rep(i,n) ans=max(ans,y[i]);*/
  cout<<ans<<endl;
}
