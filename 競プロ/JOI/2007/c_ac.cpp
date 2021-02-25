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
  int n; cin>>n;
  map<int,set<int>> p;
  rep(i,n){
    int x,y; cin>>x>>y;
    p[x].insert(y);
  }
  int s=0;
  for(auto p1 :p)for(auto p3 :p1.second){
    for(auto p2 :p)for(auto p4 :p2.second){
      if(p1==p2) continue;
      if(p1.first<p2.first||p3<p4) continue;
      if((p1.first-p2.first+p3-p4)%2==1) continue;
      int v_x,v_y;
      v_x=(p1.first-p2.first+p3-p4)/2;
      v_y=(p1.first-p2.first-p3+p4)/2;
      int d_x0,d_y0,d_x1,d_y1;
      d_x0=p2.first+v_x; d_y0=p4-v_y;
      d_x1=p2.first+v_y; d_y1=p4+v_x;
      if(p[d_x0].count(d_y0)&&p[d_x1].count(d_y1)){
        s=max(s,v_x*v_y*2+(v_x-v_y)*(v_x-v_y));
        cout<<v_x*v_y*2+(v_x-v_y)*(v_x-v_y)<<endl;
      }
    }
  }
  cout<<s;
}
