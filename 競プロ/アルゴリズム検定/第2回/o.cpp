#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

struct UnionFind{
  // par[i] : データiが属する木の親の番号。iが木の根の時 par[i] = i
  vector<int> par;
  // sizes[i] : 親ノードiの木に含まれるデータの数。iが親ノードでない時無効
  vector<int> sizes;
  // コンストラクタ
  UnionFind(int n) : par(n), sizes(n,1){ //メンバ初期化子リスト。ここは適宜変える。
    //最初全てのデータは別々
    rep(i,n) par[i] = i;
  }
  int find(int x){
    if(x==par[x]) return x;
    return par[x] = find(par[x]);
  }
  // ２つのデータx,yが属する木をマージする
  void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x==y) return;
    if(sizes[x]<sizes[y]) swap(x,y);
    par[y] = x;
    sizes[x] += sizes[y];
    sizes[y] = 0; //根以外は無効な値なので0を代入
  }
  // 同じ木に属するか
  bool same(int x, int y){
    return find(x) == find(y);
  }
  int size(int x){
    return sizes[find(x)];
  }
};

struct Edge{
  int a, b, cost;
  // コストの大小で順序定義
  // 演算子オーバーロード
  /*返り値の型 operator<(引数の型 引数) {
    // 処理内容
  }*/
  bool operator<(const Edge& o) const{
    return cost < o.cost;
  }

};

struct Graph{
  int n; //頂点数
  vector<Edge> es; //辺集合

  // クラスカル法で無向最小全域木のコストの和を計算する
  // グラフが非連結のときは最小全域森のコストの和となる
  int kruscal(){
    //コストが小さい順にソート
    //operatorによりEdgeの大小をコストに定めているからこそできる
    sort(es.begin(), es.end());

    UnionFind uf(n);
    int min_cost = 0;

    rep(i,es.size()){
      Edge& e = es[i]; //i番目のes自体に変化をもたらそうとしているためポインタ型
      if(!uf.same(e.a,e.b)){
        min_cost += e.cost;
        uf.unite(e.a,e.b);
      }
    }
    return min_cost;
  }
};
// 入力を関数でまとめた
Graph input_graph(){
  Graph g;
  vector<Graph> g_0(m);
  int m;
  cin >> g.n >> m;
  rep(i,m){
    Edge e;
    cin >> e.a >> e.b >> e.cost;
    g.es.push_back(e);
  }
  return g;
}
int main(){
  Graph g = input_graph();
  rep(i,m){
    
  }
  return 0;
}
