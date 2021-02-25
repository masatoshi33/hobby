#include<bits/stdc++.h>

using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0;i<n;i++)

//深さ優先探索
vector<bool> seen;
void dfs(const Graph &G, int v){ //vは始点
  seen[v] = true; //始点なので訪問済

  for(auto next_v : G[v]){
    if(seen[next_v]) continue; //next_vが訪問済ならスルー
    dfs(G, next_v); //再起的に探索
  }
}

//sからtに辿り着けるか
int main(){
  int n, m, s, t; //頂点数、辺数
  cin >> n >> m >> s >> t;

  Graph G(n);
  rep(i,n){
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a); //無向グラフなので双方向
  }
  int count=0; //連結成分の数を初期化
  seen.assign(n,false); //N個すべて未訪問に
  for(int i=0;i<n;i++){
    if(seen[i]==true) continue; //訪問済ならスルー
    dfs[G, i]; //未訪問の点を始点に深さ優先探索
    count++; //カウントを増やす
  }
}
