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
  vvi t(n+2,vi(n+2));
  rep(i,m){
    int a,b,x; cin>>a>>b>>x;
    a--; b--;
    t[a][b]++;
    t[a][b+1]--;
    t[a+x+2][b+1]++;
    t[a+x+1][b]--;
    t[a+x+1][b+x+2]++;
    t[a+x+2][b+x+2]--;
  }
  rep(i,n+1) rep(j,n+2) t[i+1][j]+=t[i][j];
  rep(i,n+2) rep(j,n+1) t[i][j+1]+=t[i][j];
  rep(i,n+1) rep(j,n+1) t[i+1][j+1]+=t[i][j];
  int ans=0;
  rep(i,n)rep(j,i+1) if(t[i][j]) ans++;
  cout<<ans<<endl;
}
