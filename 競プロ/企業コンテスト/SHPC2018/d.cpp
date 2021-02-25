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
  int n,m,s,t; cin>>n>>m>>s>>t;
  s--;t--;
  //グラフを作成
  vector<vector<pll>> g_a(n);
  vector<vector<pll>> g_b(n);
  rep(i,m){
    int u,v,a,b; cin>>u>>v>>a>>b;
    u--;v--;
    g_a[u].push_back({v,a});
    g_a[v].push_back({u,a});
    g_b[u].push_back({v,b});
    g_b[v].push_back({u,b});
  }
  //円、スヌーくそれぞれでいく場合の最小距離を設定
  vll dist_a(n);
  vll dist_b(n);
  //初期値
  rep(i,n){
    dist_a[i]=l_INF;
    dist_b[i]=l_INF;
  }
  priority_queue<pll,vector<pll>,greater<pll>> q_a,q_b;
  q_a.push({0,s});
  dist_a[s]=dist_b[t]=0;
  // 優先度付きキューには (距離, 頂点番号) の組を入れる
  while(!q_a.empty()){
    ll pos = q_a.top().second; q_a.pop();
    for(ll i=0;i<g_a[pos].size();i++){
      ll to=g_a[pos][i].first, cost=g_a[pos][i].second;
      if(dist_a[to]>dist_a[pos]+cost){
        dist_a[to]=dist_a[pos]+cost;
        q_a.push({dist_a[to],to});
      }
    }
  }
  q_b.push({0,t});
  // 優先度付きキューには (距離, 頂点番号) の組を入れる
  while(!q_b.empty()){
    ll pos = q_b.top().second; q_b.pop();
    for(ll i=0;i<g_b[pos].size();i++){
      ll to=g_b[pos][i].first, cost=g_b[pos][i].second;
      if(dist_b[to]>dist_b[pos]+cost){
        dist_b[to]=dist_b[pos]+cost;
        q_b.push({dist_b[to],to});
      }
    }
  }
  vll ans(n);
  ll val=l_INF;
  for(int i=n-1;i>=0;i--){
    val=min(dist_a[i]+dist_b[i], val);
    ans[i]=1000000000000000-val;
  }
  //rep(i,n) cout<<dist_a[i]<<' '; cout<<endl;
  //rep(i,n) cout<<dist_b[i]<<' '; cout<<endl;
  rep(i,n) cout<<ans[i]<<endl;
}
