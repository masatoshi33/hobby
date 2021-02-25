//dequeを用いた深さ優先探索

#include <bits/stdc++.h>
#include <queue>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for(int i=0;i<n;i++)
queue<int> U;
//vector<int> dist;
vector<bool> seen(101010);
vector<int> group(101010);
vector<set<int>> member(101010);
Graph friends(101010);
Graph block(101010);
int group_id=1;

void dfs(int v){
  seen[v] = true;
  group[v] = group_id;
  member[group_id].insert(v);
  for(auto next_v : friends[v]){
      if(!seen[next_v]) dfs(next_v);
  }
}
int main() {
    // 頂点数と辺数、s と t
    int n, m, k; cin >> n >> m >> k;
    // グラフ入力受取
    for(int i=0;i<m;i++) {
      int a, b;
      cin >> a >> b;
      a--;b--;
      friends[a].push_back(b);
      friends[b].push_back(a);
    }
    for(int i=0;i<k;i++){
      int c, d;
      cin >> c >> d;
      c--;d--;
      block[c].push_back(d);
      block[d].push_back(c);
    }
    rep(i,n){
      if(!seen[i]){
        dfs(i);
        group_id++;
      }
    }
    rep(i,n){
      int x = group[i];
      int ans = member[x].size() - 1 - friends[i].size();
      for(int y : block[i]){
        if(member[x].count(y)) ans --;
      }
      cout << ans << " ";
    }
}
