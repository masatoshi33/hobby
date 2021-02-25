#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1e+9
#define max_v 10

struct edge{
  int to;
  int cost;
}
//<最短距離,頂点の番号>
using P = pair<int, int>;

//pairに対して+演算子をオーバーロード
/*pair<int, int> operator+(pair<int, int> a, pair<int, int> b) {
  pair<int, int> ret;
  ret.first = a.first + b.first;
  ret.second = a.second + b.second;
  return ret;
}*/

// .second → .first の順に比較
/*bool operator<(pair<int, int> l, pair<int, int> r) {
  if (l.second != r.second) {
    return l.second < r.second;
  } else {
    return l.first < r.first;
  }
}*/

int v;
vector<edge> G[max_v];
int d[max_v];

void dijkstra(int s) {
  priority_queue<P, vector<P>, greater<P>> que;
  fill(d,d+v,INF);
  d[s]=0;
  que.push(P(0,s));

  while(!que.empty()){
    P p = que.top();
    que.pop();
    int v = p.second;
    if(d[v]<p.first) continue;

    for(int i=0;i<G[v].size();i++){
      edge e = G[v][i];
      if(d[e.to]>d[v]+e.cost){
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to]));
      }
    }
  }
}
int main(){
  cin >> v;
  int E;
  cin >> E;
  rep(i,E){
    int a, b, c;
    cin >> a >> b >> c;
    edge e = {b,c};
    G[a].push_back(e);
  }
  dijkstra(0);
  rep(i,v){
    if(d[i]!=INF) cout << "0から" << i << "までのコスト: " << d[i] << endl;
  }
}
