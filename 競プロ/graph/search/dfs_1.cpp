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
  int N, M, s, t; //頂点数、辺数
  cin >> N >> M >> s >> t;

  Graph G(N);
  rep(i,N){
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
  }

  seen.assign(N,false); //N個すべて未訪問に
  dfs(G,s); //sを始点としてdfsを行う

  if(seen[t]) cout << "Yes" << endl;
  else cout << "No" << endl;
}
