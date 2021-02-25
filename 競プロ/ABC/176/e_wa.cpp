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
  int h,w; cin>>h>>w;
  int m; cin>>m;
  vi yoko(h),tate(w);
  //bool b[h+10][w+10];
  set<pii> r;
  /*rep(i,h)rep(j,w){
    b[i][j]=false;
  }*/
  rep(i,m){
    int x,y; cin>>x>>y;
    x--;y--;
    yoko[x]++;tate[y]++;
    //b[x][y]=true;
    r.insert({x,y});
  }
  int max_h=0,max_w=0;
  vi k,l;
  rep(i,h){
    if(max_h<yoko[i]){
      max_h=yoko[i];
      k.clear();
      k.push_back(i);
    }else if(max_h==yoko[i]){
      k.push_back(i);
    }
  }
  rep(i,w){
    if(max_w<tate[i]){
      max_w=tate[i];
      l.clear();
      l.push_back(i);
    }else if(max_w=tate[i]){
      l.push_back(i);
    }
  }
  int ans=max_h+max_w;
  //bool judge=false;
  for(auto x:k)for(auto y:l){
    if(!(r.count({x,y}))){
      cout<<ans<<endl;
      return 0;
    }
  }
  ans--;
  cout<<ans<<endl;
}
