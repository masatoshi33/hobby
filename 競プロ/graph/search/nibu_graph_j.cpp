#include<bits/stdc++.h>

using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0;i<n;i++)

//二部グラフ判定
vector<int> color;
bool dfs(const Graph &G, int v,int cur = 0){ //vは始点
  color[v] = cur;
  for(auto next_v : G[v]){
    //隣接頂点がすでに色確定していた場合
    if(color[next_v]!=-1){
      if(color[next_v]==cur) return false; //同じ色が隣接したらダメ
      continue;
    }
    //隣接頂点の色を変えて、再起的に探索
    if(!dfs(G,next_v,1-cur)) return false;
  }
  return true;
}

int main(){
  //頂点数と辺数
  int n,m; cin >> n >> m;
  //グラフ入力受け取り
  rep(i,m){
    int a,b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  //探索
  color.assign(n,-1);
  bool is_bipartite = true;
  rep(v,n){
    if(color[v]!=-1) continue;
    if(!dfs(G,v)) is_bipartite = false;
  }
  if(is_bipartite) cout << "Yes" << endl;
  else cout << "No" << endl;
}
