#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

// 四方向への移動ベクトル
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
// 入力
int h, w;
// 探索
ll cost[50][50]; // cost[h][w]:始点からの距離
queue<vector<ll>(2)>

struct point{
  int cost, x, y;
}

void dijkstra(int x, int y){
  cost[x][y] = 0;
  //隣の要素にいくのにかかるコスト
  rep(i,n){
    nx = x+dx[i];
    ny = y+dy[i];
    cost[nx][ny] = cost[x][y]+a[nx][ny];
  }
  priority_queue<>
}

int main(){
  cin >> h >> w;
  ll a[h][w];
  rep(i,h){
    rep(j,w){
      cin >> a[i][j];
    }
  }
  gh_1=h-1,gw_1=0,gh_2=h-1,gw_2=h-1,gh_3=0,gw_3=h-1;
  //g1,g2,g3に対してダイクストラ法で距離を求め、３つの輪を取る
  ll ans = INF;
  rep(i,h){
    rep(j,w){
      ll = min_cost;
      dijkstra(i,j);
      min_cost = [gh_1][gw_1]+cost[gh_2][gw_2]+cost[gh_3][gw_3];
      if(min_cost<ans) ans = min_cost;
    }
  }
}
