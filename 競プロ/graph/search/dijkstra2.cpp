#include <bits/stdc++.h>
#include <math.h>
#include <vector>
#include <queue>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep_1 (i,j,n) for(int i=j;i<n;i++)
typedef long long ll;
typedef long l;
const ll l_INF = 1010101010101010;
const int INF = 1010101010;
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

int main(){
  //n:点,m:道,s:start,t:goal
  int n,m,s,t;
  cin>>n>>m>>s>>t;
  s--;t--;
  //グラフの作成
  Graph g(n);
  rep(i,m){
    int u,v,c;
    cin>>u>>v>>c;
    u--;v--;
    g[u].push_back({v,c});
    g[v].push_back({u,c});
  }
  //距離の初期設定
  vi dist(n);
  rep(i,n) dist[i]=INF;
  dist[s]=0;
  priority_queue<pii,vector<pii>,greater<pll>> q;
  q.push({0,s});
  //dijkstraを実行
  while(!q.empty()){
    int pos=q.top().second; q.pop;
    rep(i,g[pos].size()){
      //to:posの行き先,cost:そこまでにかかるコスト
      int to=g[pos][i].first; cost=g[pos][i].second;
      if(dist[to]>dist[pos]+cost){ //もし今のとこのtoへの最短距離よりposからいった方が最短距離が短い時
        dist[to]=dist[pos]+cost; //toへの最短距離を更新
        q.push({dist[to],to}); //toをqに追加
      }
    }
  }
  //sからtまでの距離を出力
  cout<<dist[t];
}
