#include <bits/stdc++.h>
#include <iostream>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
queue<int> U;
vector<int> dist;
vector<int> d(101010);

void dfs(const Graph &G, int v){
  U.push(v);
  dist[v] = 0;
  while(!U.empty()){
    int v_2 = U.front();
    U.pop();
    for(auto next_v : G[v_2]){
      if(dist[next_v]==-1){
        U.push(next_v);
        dist[next_v] = dist[v_2] + 1;
        d[next_v] = v_2+1;
        //cout << next_v << endl; //通った場所を出力(確認用)
      }
    }
  }
}
int main(){
  int n,m;
  cin >> n >> m;
  Graph G(n+1);
  for (int i = 0;i<m;i++) {
      int a, b;
      cin >> a >> b;
      a--;b--;
      G[a].push_back(b);
      G[b].push_back(a);
  }
  // 頂点 s をスタートとした探索
  dist.assign(n+1, -1); // 全頂点を「未訪問」に初期化
  dfs(G,0);
  // t に辿り着けるかどうか
  for(int i=1;i<n;i++){
    if(dist[i]==-1){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  rep(i,n-1){
    cout << d[i+1] << endl;
  }
}
