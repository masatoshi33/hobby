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

struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main(){
  ll n,k; cin>>n>>k;
  vll p(n),c(n); rep(i,n) cin>>p[i]>>c[i];
  UnionFind tree(n);
  rep(i,n){
    tree.unite(i,p[i]);
  }
  vll cost(n);
  rep(i,n){
    int x=i;
    while(x!=p[i]){
      x=p[x];
      cost[i]+=c[x];
    }
  }
  vi num(n);
  rep(i,n){
    num[tree.par[i]]++;
  }
  vector<vector<ll>> list(n);
  vector<ll> m_cost(n);
  rep(i,n){
    int x=i;
    while(x!=p[i]){
      ll y;
      if(list[i].empty()) y=0;
      else y=list[i].front();
      list[i].push_back(y+c[x]);
      m_cost[i]=max(m_cost[i],y+c[x]);
      x=p[x];
    }
  }
  ll ans=0;
  rep(i,n){
    ll sum=0;
    ll x=k;
    if(x>=num[i]){
      sum+=max(0LL,cost[i]*(x/num[i]));
      x%=num[i];
    }
    ll sum2=0;
    rep(j,x){
      sum2=max(sum2,list[i][j]);
    }
    sum+=sum2;
    ans=max(ans,sum);
  }
  cout<<ans<<endl;
}
