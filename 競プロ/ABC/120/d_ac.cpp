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

int comb(int x){
  return x*(x-1)/2;
}

int main(){
  ll n,m; cin>>n>>m;
  vll a(m),b(m); rep(i,m) cin>>a[i]>>b[i];
  rep(i,m) a[i]--,b[i]--;
  UnionFind UF(n);
  vll ans(m,n*(n-1)/2);
  for(int i=m-1;i>=0;i--){
    if(i>0&&!(UF.same(a[i],b[i]))){
      ans[i-1]=ans[i]-UF.size(a[i])*UF.size(b[i]);
    }else if(i>0){
      ans[i-1]=ans[i];
    }
    UF.unite(a[i],b[i]);
  }
  rep(i,m){
    cout<<ans[i]<<endl;
  }
}
