#include <bits/stdc++.h>
#include <math.h>
#include <vector>
#include <queue>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep_1 (i,j,n) for(int i=j;i<n;i++)
typedef long long ll;
typedef long l;
const ll l_INF = 1010101010101010;
const int INF = 1010101010;
const int dx[] = {-1,0,1,0,-1,-1,1,1};
const int dy[] = {0,-1,0,1,1,-1,1,-1};
#define MAX 100000
#define MAX_E 100000

int par[MAX], friends[MAX];
//初期化
void init(int n){
  rep(i,n){
    par[i]=i;
    friends[i]=0;
  }
}
//親要素の取得
int find(int x){
  if(par[x]==x) return x;
  return par[x]=find(par[x]);
}
//要素同士の結合
void unite(int x,int y){
  x=find(x);
  y=find(y);
  if(x==y) return;
  if(friends[x]<friends[y]) par[x]=y;
  else {
    par[y]=x;
  }
  if(friends[x]==friends[y]) friends[x]++;
}
//同じ親要素を持つか判断する関数
bool same(int x,int y){
  return (find(x)==find(y));
}
//辺を定義
struct edge{int u, v, cost;};
//辺同士の比較
bool comp(const edge &e1, const edge &e2){
  return e1.cost<e2.cost;
}
int v,e;
edge es[MAX_E];
int kruskal(){
  sort(es,es+e,comp);
  init(v);
  int res=0;
  rep(i,e){
    edge e = es[i];
    if(!same(e.u,e.v)){
      unite(e.u,e.v);
      res+=e.cost;
    }
  }
  return res;
}
int main(){
  //s:始点,t:終点,w:重み
  int s,t,w;
  //v:頂点数,e:辺数
  cin>>v>>e;
  rep(i,e){
    cin>>s>>t>>w;
    es[i]=(edge){s,t,w};
  }
  cout<<kruskal()<<endl;
  return 0;
}
