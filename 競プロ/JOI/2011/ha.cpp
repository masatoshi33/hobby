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
  int n,m; cin>>n>>m;
  int k; cin>>k;
  vector<vector<char>> g(n,vector<char>(m));
  rep(i,n)rep(j,m) cin>>g[i][j];
  vvi jungle(n+1,vi(m+1)),ocean(n+1,vi(m+1)),ice(n+1,vi(m+1));
  rep(i,n)rep(j,m){
    int x=0,y=0,z=0;
    if(g[i][j]=='J') x=1;
    jungle[i+1][j+1]=jungle[i][j+1]+jungle[i+1][j]-jungle[i][j]+x;
    if(g[i][j]=='O') y=1;
    ocean[i+1][j+1]=ocean[i][j+1]+ocean[i+1][j]-ocean[i][j]+y;
    if(g[i][j]=='I') z=1;
    ice[i+1][j+1]=ice[i][j+1]+ice[i+1][j]-ice[i][j]+z;
  }
  rep(i,k){
    int s_x,s_y,e_x,e_y;
    cin>>s_x>>s_y>>e_x>>e_y;
    int x=jungle[e_x][e_y]-jungle[e_x][s_y-1]-jungle[s_x-1][e_y]+jungle[s_x-1][s_y-1];
    int y=ocean[e_x][e_y]-ocean[e_x][s_y-1]-ocean[s_x-1][e_y]+ocean[s_x-1][s_y-1];
    int z=ice[e_x][e_y]-ice[e_x][s_y-1]-ice[s_x-1][e_y]+ice[s_x-1][s_y-1];
    cout<<x<<" "<<y<<" "<<z<<endl;
  }
}
