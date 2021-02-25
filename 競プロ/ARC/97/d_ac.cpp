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

struct UnionFind{
  vi r;
  UnionFind(int n){
    r=vi(n,-1);
  }
  int root(int x){
    if(r[x]<0) return x;
    return r[x]=root(r[x]);
  }
  bool unite(int x, int y){
    x=root(x); y=root(y);
    if(x==y) return false;
    if(r[x]<r[y]) swap(x,y);
    r[x]+=r[y];
    r[y]=x;
    return true;
  }
  int size(int x){
    return -r[root(x)];
  }
  int same(int x, int y){
    if(root(x)==root(y)) return true;
    else return false;
  }
};

int main(){
  int n,m; cin>>n>>m;
  int ans=0;
  vi p(n); rep(i,n) cin>>p[i];
  rep(i,n) p[i]--;
  UnionFind UF(n+1);
  rep(i,m){
    int x,y; cin>>x>>y; x--; y--;
    UF.unite(x,y);
  }
  rep(i,n){
    if(UF.same(i,p[i])) ans++;
  }
  cout<<ans<<endl;
}
