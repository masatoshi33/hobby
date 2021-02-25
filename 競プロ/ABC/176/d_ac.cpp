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
  int sh,sw,gh,gw; cin>>sh>>sw>>gh>>gw;
  sh--;sw--;gh--;gw--;
  //cout<<sh<<" "<<sw<<" "<<gh<<" "<<gw<<endl;
  vector<vector<char>> s(1010,vector<char>(1010));
  rep(i,h)rep(j,w) cin>>s[i][j];
  int dist[1010][1010];
  rep(i,h)rep(j,w){
    dist[i][j]=INF;
  }
  stack<pair<int,int>> s1;
  stack<pair<int,int>> s2;
  s1.push({sh,sw});
  int nh,nw;
  int cnt=0;
  while(!(s1.empty()&&s2.empty())){
    //if(s1.empty()) cout<< "empty"<<endl;
    if(s1.empty()){
      cnt++;
      while(!(s2.empty())){
        //cout<<"s2 empty"<<endl;
        int x=s2.top().first, y=s2.top().second;
        s2.pop();
        for(int dx=-2;dx<=2;dx++)for(int dy=-2;dy<=2;dy++){
          if(x+dx>=h||x+dx<0||y+dy>=w||y+dy<0) continue;
          if(dist[x+dx][y+dy]==INF&&s[x+dx][y+dy]=='.'){
            s1.push({x+dx,y+dy});
            //cout<<x+dx<<" "<<y+dy<<endl;
          }
        }
        if(s1.empty()&&s2.empty()) break;
      }
    }
    if(s1.empty()&&s2.empty()) break;
    nh=s1.top().first,nw=s1.top().second;
    s1.pop();
    if(dist[nh][nw]!=INF) continue;
    s2.push({nh,nw});
    dist[nh][nw]=cnt;
    rep(d,4){
      pair<int,int> np={nh+dx[d],nw+dy[d]};
      if(np.first>=h||np.first<0||np.second>=w||np.second<0) continue;
      if(dist[np.first][np.second]!=INF) continue;
      if(s[np.first][np.second]=='#') continue;
      s1.push(np);
      //cout<<np.first<<" "<<np.second<<endl;
    }
    if(dist[gh][gw]!=INF) break;
    if(s1.empty()&&s2.empty()) break;
  }
  if(dist[gh][gw]==INF) cout<<-1<<endl;
  else cout<<dist[gh][gw]<<endl;
}
