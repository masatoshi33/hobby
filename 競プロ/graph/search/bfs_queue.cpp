//queueを用いた深さ優先探索

#include <bits/stdc++.h>
#include <queue>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for(int i=0;i<n;i++)
queue<int> U;
vector<int> dist;

int dfs(const Graph &G, int v){
  U.push(v);
  dist[v] = 0;
  while(!U.empty()){
    int v_2 = U.front();
    U.pop();
    for(auto next_v : G[v_2]){
      if(dist[next_v]==-1){
        U.push(next_v);
        dist[next_v] = dist[v_2] + 1;
        //cout << next_v << endl; //通った場所を出力(確認用)
      }
    }
  }
}
int main() {
  // 頂点数と辺数、s と t
  int n, m, s, t; cin >> n >> m >> s >> t;
  // グラフ入力受取
  Graph G(n+1);
  for(int i=0;i<m;i++){
      int a, b;
      cin >> a >> b;
      G[a].push_back(b);
      //G[b].push_back(a); //双方向
  }

  // 頂点 s をスタートとした探索
  dist.assign(n+1, -1); // 全頂点を「未訪問」に初期化
  dfs(G,s);

  // t に辿り着けるかどうか
  if (dist[t]!=-1) cout << "Yes" << endl;
  else cout << "No" << endl;
  rep(i, N){
    cout << dist[i+1] << endl;
  }
}
