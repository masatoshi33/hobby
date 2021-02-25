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
int n,m;

struct UnionFind{
  vector<int> r;

  UnionFind(int n){
    r=vector<int>(n,-1);
  }
  int root(int x){
    if(r[x]<0) return x;
    return r[x]=root(r[x]);
  }
  bool unite(int x, int y){
    x=root(x),y=root(y);
    if(x==y) return false;
    if(r[x]<r[y]) swap(x,y);
    r[x]+=r[y];
    r[y]=x;
    return true;
  }
  int size(int x){
    return -r[root(x)];
  }
};

int main(){
  cin>>n>>m;
  int ans=0;
  vi a(m),b(m);
  rep(i,m){
    cin>>a[i]>>b[i];
    a[i]--;b[i]--;
  }
  rep(i,m){
    UnionFind UF(n);
    rep(j,m){
      if(j==i) continue;
      UF.unite(a[j],b[j]);
    }
    bool bridge=false;
    /*rep(j,n){
      if(UF.root(j+1)!=0){
        bridge=true;
        cout<<UF.root(j+1)<<" ";
      }
    }*/
    int x = UF.root(0);
    rep(j,n-1){
      if(UF.root(j+1)!=x) bridge=true;
    }
    if(bridge) ans++;
  }
  //cout<<endl;
  cout<<ans<<endl;
}
