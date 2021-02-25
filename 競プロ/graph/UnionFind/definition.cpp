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
  vector<int> r;
  UnionFind(int n){
    r=vi(n,-1);
  }
  int root(int x){
    if(d[x]<0) return x;
    return d[x] = root(d[x]);
  }
  bool unite(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return false;
    if (r[x] > r[y]) swap(x,y);
    r[x] += r[y];
    r[y] = x;
    return true;
  }
  bool same(int x, int y){
    return root(x)==root(y);
  }
  int size(int x){
    return -r[root(x)];
  }
};
