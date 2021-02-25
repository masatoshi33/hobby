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
  int n,m; cin>>n;
  vector<pii> s_0(n);
  vector<pii> s(n-1);
  map<int,set<int>> p;
  rep(i,n){
    int x,y; cin>>x>>y;
    s_0[i]={x,y};
  }
  rep(i,n-1){
    int x,y;
    x=s_0[i+1].first-s_0[0].first;
    y=s_0[i+1].second-s_0[0].second;
    s[i]={x,y};
  }
  cin>>m;
  rep(i,m){
    int x,y; cin>>x>>y;
    p[x].insert(y);
  }
  vector<bool> judge(m);
  pii vec;
  for(auto p1:p)for(auto p2:p1.second){
    rep(j,n-1){
      int x,y;
      x=p1.first+s[j].first;
      y=p2+s[j].second;
      if(p[x].count(y)){
        judge[j]=true;
        int dx,dy;
        dx=p1.first-s_0[0].first;
        dy=p2-s_0[0].second;
        vec={dx,dy};
      }
    }
    //check
    bool f_judge=true;
    rep(i,m){
      if(!judge[i]) f_judge=false;
    }
    if(f_judge){
      break;
    }
  }
  cout<<vec.first<<" "<<vec.second<<endl;
}
