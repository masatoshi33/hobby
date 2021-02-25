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

struct UnionFind{
  //自身が親なら、その集合に属する頂点数に-1をかけたもの
  //そうでなければ親のid
  vector<int> r;

  UnionFind(int n){
    r=vector<int>(n,-1);
  }
  //親要素を返す
  int root(int x){
    if(r[x]<0) return x;
    return r[x] = root(r[x]);
  }
  //二つの要素それぞれを含む友達集合をくっつける
  bool unite(int x, int y){
    x=root(x); y=root(y);
    //親要素が等ければ、失敗
    if(x==y) return false;
    //要素数が大きい方をxをする(どちらも負の数であることに注意)
    if(r[x]>r[y]) swap(x,y);
    r[x]+=r[y];//すべての祖であるxの要素数にyの集合の分を足してあげる
    r[y]=x;//yの親をxと設定
    return true;
  }
  //親要素のrの直つまり要素数を足す
  int size(int x){
    return -r[root(x)];
  }
};

int main(){
  int n,m; cin>>n>>m;
  //友達集合を作る
  UnionFind UF(n);
  rep(i,m){
    int a,b; cin>>a>>b;
    a--;b--;
    //aとbを含む集合を結合
    UF.unite(a,b);
  }
  //最大の友達集合を求める
  int ans=0;
  rep(i,n) ans=max(ans,UF.size(i));
  cout<<ans<<endl;
}
