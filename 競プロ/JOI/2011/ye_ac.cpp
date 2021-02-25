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
const string num = "123456789";
const ll l_INF = 101010101000;
const int INF = 1010101010;
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int,int>;

int main(){
  int h,w,n; cin>>h>>w>>n;
  vector<vector<char>> c(h,vector<char>(w));
  vector<pii> cheeze(n+1);
  rep(i,h)rep(j,w){
    cin>>c[i][j];
    if(c[i][j]=='S') cheeze[0]={i,j};
    if(c[i][j]=='.') continue;
    rep(k,9){
      if(c[i][j]==num[k]) cheeze[k+1]={i,j};
    }
  }
  int ans=0;
  rep(i,n+1){
    //cout<<cheeze[i].first<<" "<<cheeze[i].second<<endl;
  }
  rep(i,n){
    vvi distance(h,vi(w));
    rep(i,h)rep(j,w) distance[i][j]=INF;
    pii sp=cheeze[i];
    pii gp=cheeze[i+1];
    queue<pii> q;
    q.push(sp);
    distance[sp.first][sp.second]=0;
      while(!q.empty()){
      pii ip=q.front();
      q.pop();
      rep(i,4){
        pii np;
        np.first=ip.first+dx[i];
        np.second=ip.second+dy[i];
        if(np.first>=h||np.first<0||np.second>=w||np.second<0) continue;
        if(c[np.first][np.second]=='X') continue;
        if(distance[np.first][np.second]!=INF) continue;
        distance[np.first][np.second]=distance[ip.first][ip.second]+1;
        q.push(np);
        //cout<<np.first<<' '<<np.second<<endl;
      }
      if(distance[gp.first][gp.second]!=INF){
        ans+=distance[gp.first][gp.second];
        break;
      }
    }
  }
  cout<<ans;
}
