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

const int limit=50;
int n,m;
int a[limit],b[limit];

bool graph[limit][limit]; //直接つながっているかどうか
bool visited[limit]; //訪問済みかどうか

void dfs(int v){
  visited[v]=true;
  rep(v2,n){
    if(!(graph[v][v2])) continue; //直接繋がっていなければスルー
    if(visited[v2]) continue; //訪問済みならスルー
    dfs(v2);
  }
}

int main(){
  cin>>n>>m;
  rep(i,m){
    cin>>a[i]>>b[i]; a[i]--; b[i]--;
    graph[a[i]][b[i]]=graph[b[i]][a[i]]=true;
  }
  int ans=0;
  rep(i,m){
    graph[a[i]][b[i]]=graph[b[i]][a[i]]=false; //一つの辺を消す
    rep(j,n) visited[j]=false;
    dfs(0);
    bool bridge=false;
    rep(j,n) if(!(visited[j])) bridge=true;
    if(bridge) ans++;
    graph[a[i]][b[i]]=graph[b[i]][a[i]]=true; //元に戻す
  }
  cout<<ans<<endl;
}
