#include <bits/stdc++.h>
#include <math.h>
#include <vector>
#include <queue>
#include <iomanip>
#include <string>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep_1 (i,j,n) for(int i=j;i<n;i++)
typedef long long ll;
typedef long l;
const ll l_INF = 101010101000;
const int INF = 1010101010;
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;
Graph g(101010);
vector<int> dist(101010);

int bfs(int s){
  if(dist[s]>0) return dist[s];
  int ans=0;
  for(auto x : g[s]){
    ans = max(ans, bfs(x)+1);
  }
  return dist[s]=ans;
}

int main(){
  int n, m;
  cin >> n >> m;
  rep(i,m){
    int x,y;
    cin >> x >> y;
    x--;y--;
    g[x].push_back(y);
  }
  int ans=0;
  rep(i,n){
    bfs(i);
  }
  rep(i,n){
    if(ans<dist[i]) ans = dist[i];
  }
  cout << ans;
}
