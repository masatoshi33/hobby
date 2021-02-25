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
const ll l_INF = 101010101000;
const int INF = 1010101010;
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int,int>;

int main(){
  int h,w; cin>>h>>w;
  int sh,sw; cin>>sh>>sw;
  int gh,gw; cin>>gh>>gw;
  sh--;sw--;gh--;gw--;
  vector<vector<char>> c(h,vector<char>(w));
  vvi distance(h,vi(w));
  rep(i,h)rep(j,w) distance[i][j]=INF;
  rep(i,h)rep(j,w) cin>>c[i][j];
  queue<pii> q;
  pair<int,int> sp = {sh,sw};
  q.push(sp);
  distance[sh][sw]=0;
  while(!q.empty()){
    pii ip=q.front();
    q.pop();
    rep(i,4){
      pii np;
      np.first=ip.first+dx[i];
      np.second=ip.second+dy[i];
      if(np.first>=h||np.first<0||np.second>=w||np.second<0) continue;
      if(c[np.first][np.second]=='#') continue;
      if(distance[np.first][np.second]!=INF) continue;
      distance[np.first][np.second]=distance[ip.first][ip.second]+1;
      q.push(np);
      //cout<<np.first<<' '<<np.second<<endl;
    }
    if(distance[gh][gw]!=INF) break;
  }
  cout<<distance[gh][gw]<<endl;
}
