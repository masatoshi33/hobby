//dequeを用いた深さ優先探索
//オーダー:

#include <bits/stdc++.h>
#include <deque>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for(int i=0;i<n;i++)
deque<int> U;
vector<bool> seen;

int dfs(const Graph &G, int v){
  U.push_front(v);
  while(U.front()>0){
    int v_2 = U.front();
    U.pop_front();
    seen[v_2] = true;
    for(auto next_v : G[v_2]){
      if(seen[next_v]) continue;
      U.push_front(next_v);
    }
  }
}
int main() {
    // 頂点数と辺数、s と t
    int N, M, s, t; cin >> N >> M >> s >> t;
    // グラフ入力受取
    Graph G(N+1);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    // 頂点 s をスタートとした探索
    seen.assign(N, false); // 全頂点を「未訪問」に初期化
    dfs(G, s);

    // t に辿り着けるかどうか
    if (seen[t]) cout << "Yes" << endl;
    else cout << "No" << endl;
}
