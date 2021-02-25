#include <bits/stdc++.h>
#include <math.h>
#include <vector>
#include <queue>
#include <iomanip>
#include <string>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(ll i=0;i<n;i++)
typedef long long ll;
const ll l_INF = 101010101000;
const int INF = 1010101010;
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};
int dist[510][510];
int k[502][502];
ll n;

int dfs(int x, int y){
  if(x==1||y==1||x==n||y==n) return dist[x][y]==0;
  if(dist[x][y]!=INF) return dist[x][y];
  int ans=INF;
  rep(i,4){
    int nx=x+dx[i];
    int ny=y+dy[i];
    if(nx < 0 || nx > n+1 || ny < 0 || ny > n+1) continue;
    if(k[nx][ny] == 1) ans = min(ans,dfs(nx,ny)+1);
    else ans = min(ans,dfs(nx,ny));
  }
  return dist[x][y]=ans;
}

int main(){
  cin >> n;
  vector<ll> p(n*n);
  rep(i,n*n){
    cin >> p[i];
    p[i]--;
  }
  rep(i,n){
    rep(j,n){
      k[i+1][j+1] = 1;
    }
  }
  rep(i,n){
    rep(j,n){
      dist[i+1][j+1]=INF;
    }
  }
  ll count=0;
  rep(i,n*n){
    ll x = p[i]%n;
    ll y = p[i]/n;
    x++;y++;
    /*bool judge_0=true,judge_1=true,judge_2=true,judge_3=true;
    ll count_0=0,count_1=0,count_2=0,count_3=0;
    rep(j,y){
      if(k[x][j]==1){
        judge_0 = false;
        count_0++;
      }
    }
    rep(j,x){
      if(k[j][y]==1){
        judge_1 = false;
        count_1++;
      }
    }
    for(ll j=x+1;j<n;j++){
      if(k[j][y]==1){
        judge_2 = false;
        count_2++;
      }
    }
    for(ll j=y+1;j<n;j++){
      if(k[x][j]==1){
        judge_3 = false;
        count_3++;
      }
    }
    if((!judge_0)&&(!judge_1)&&(!judge_2)&&(!judge_3)){
      ll ans_0 = min(count_0,count_1);
      ll ans_1 = min(count_2,count_3);*/
      //count+= min(ans_0,ans_1);
      count+= dfs(x,y);
      //cout << p[i] << endl;
    k[x][y]-=1;

  }
  cout << count << endl;
}
