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
  vector<set<int>> g(n);
  rep(i,m){
    int x,y; cin>>x>>y;
    x--;y--;
    g[x].insert(y);
    g[y].insert(x);
  }
  int ans=0;
  rep(i,1<<n){
    vi com;
    rep(j,n){
      if((i>>j)&1) com.push_back(j);
    }
    bool judge=true;
    for(auto x:com){
      for(auto y:com){
        if(x!=y&&!(g[x].count(y))) judge=false;
      }
    }
    int l=com.size();
    if(judge) ans=max(l,ans);
  }
  cout<<ans<<endl;
}
