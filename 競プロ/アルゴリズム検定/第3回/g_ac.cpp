#include <bits/stdc++.h>
#include <math.h>
#include <vector>
#include <queue>
#include <iomanip>
#include <string>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
const int INF = 1000000;
const int dx[6] = {1,0,-1,1,-1,0};
const int dy[6] = {1,1,1,0,0,-1};
queue<pair<int,int>> U;
int dist[403][403];
int J[403][403];
int g_x,g_y;

int bfs(int x, int y){
  pair<int,int> p;
  p.first = x;
  p.second = y;
  U.push(p);
  while(!U.empty()){ //永遠に回す
    pair<int,int> p_0;
    p_0 = U.front();
    U.pop();
    rep(i,6){
      pair<int,int> np;
      np.first=p_0.first+dx[i];
      np.second=p_0.second+dy[i];
      if(np.first<0||np.second<0||np.first>402||np.second>402) continue;
      if(J[np.first][np.second]==1) continue;
      if(dist[np.first][np.second]!=-1) continue;
      U.push(np);
      dist[np.first][np.second] = dist[p_0.first][p_0.second]+1;
      //if(dist[g_x][g_y]!=-1) return dist[g_x][g_y]; //ゴールの距離定ったら返して終了
    }
  }
  return dist[g_x][g_y];
}
int main(){
  int n;
  cin >> n >> g_x >> g_y;
  g_x+=201;g_y+=201;
  //初期化
  for(int i=0;i<403;i++){
    for(int j=0;j<403;j++){
      dist[i][j]=-1;
    }
  }
  //障害物設置
  rep(i,n){
    int x_0,y_0;
    cin >> x_0 >> y_0;
    x_0+=201;
    y_0+=201;
    J[x_0][y_0] = 1;
  }
  dist[201][201]=0; //初期化
  cout << bfs(201,201) << endl;
  //チェック
  /*for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      cout << dist[i+196][j+196];
    }
    cout << endl;
  }*/
}
