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
char g[1010][1010];
int root[1010][1010];
const int mod = 1000000007;

int main(){
  int h,w;
  cin >> h >> w;
  rep(i,h){
    rep(j,w){
      cin >> g[i+1][j+1];
    }
  }
  rep(i,h+1){
    rep(j,w+1){
      if(i==0||j==0) g[i][j]=='#';
    }
  }
  root[1][1]=1;
  for(int i=1;i<h+1;i++){
    for(int j=1;j<w+1;j++){
      if(g[i-1][j]=='.') root[i][j]+=root[i-1][j];
      root[i][j]%=mod;
      if(g[i][j-1]=='.') root[i][j]+=root[i][j-1];
      root[i][j]%=mod;
    }
  }
  cout << root[h][w];
}
