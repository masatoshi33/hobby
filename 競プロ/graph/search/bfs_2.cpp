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
queue<pii> U;
char s[25][25]; //通れるか通れないか'#'or'.'
int h,w;

int bfs(int x, int y){
  int dist[25][25]; //始点(x,y)からの距離
  rep(i,h){
    rep(j,w){
      dist[i][j]=-1; //未訪問
    }
  }
  dist[x][y]=0;
  int max=0;
  pii p = make_pair(x,y);
  U.push(p);
  while(!U.empty()){
    pii p_0 = U.front();
    U.pop();
    rep(i,4){
      int nx = p_0.first + dx[i];
      int ny = p_0.second + dy[i];
      if(nx>=h||nx<0||ny>=w||ny<0) continue; //範囲外はスルー
      if(s[nx][ny]=='#') continue; //'#'はスルー
      if(dist[nx][ny]!=-1) continue; //訪問済はスルー
      pii np = make_pair(nx,ny);
      dist[nx][ny]=dist[p_0.first][p_0.second]+1;
      if(dist[nx][ny]>max) max = dist[nx][ny];
      U.push(np);
    }
  }
  return max;
}
