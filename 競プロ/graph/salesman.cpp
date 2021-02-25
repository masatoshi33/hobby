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
int n,m,a,b,c,x[20]20]; //n:頂点数,m:辺数,x:各頂点の直接の距離
int dp[20][1<<20]; //今いる位置、どこに達したことがあるか

int main(){
  rep(i,20){
    rep(j,20) x[i][j]=INF;
    rep(j,(1<<20)) dp[i][j]=INF;
  }
  cin>>n>>m;
  rep(i,m){
    cin>>a>>b>>c; //a:始点,b:終点,c:重み
    x[a][b]=c;
  }
  dp[0][1]=0;
  rep(i,(1<<n)){ //iは達しているなら1,そうでなければ0のn個の数列
    rep(j,n){ //今いる位置
      if(dp[j][i]<INF){ //もうiの位置に達しているなら
        rep(k,n){ //移動する位置
          if(!((i/(1<<k))%2&1){
            int dist=dp[j][i]+x[j][k];
            int pos=i+(1<<k); //kの位置を追加
            if(dp[k][pos]>dist){
              dp[k][pos]=dist;
            }
          }
        }
      }
    }
  }
  int maxn=INF;
  rep(i,n) maxn=min(dp[i][(1<<n)-1]+x[i][0],maxn);
  if(maxn==INF) maxn=-1;
  cout<<maxn<<endl;
}
