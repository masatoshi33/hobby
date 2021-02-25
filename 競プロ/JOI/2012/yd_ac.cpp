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
  int n,k; cin>>n>>k;
  vector<int> p(n+1);
  rep(i,k){
    int x,y; cin>>x>>y;
    p[x]=y;
  }
  // dp[a][b][c]:c日目のパスタがa,c+1日目はbであった問いのi+2日目以降の予定の個数
  int dp[4][4][n+1];
  rep(i,4){
    rep(j,4){
      rep(k,n+1){
        dp[i][j][k]=0;
      }
    }
  }
  int tday, neday;
  //
  if(p[1]==0){
    for(tday=1;tday<4;tday++) dp[0][tday][1]+=1;
  }else{
    dp[0][p[1]][1]+=1; //もし1日目が決まってたらそれのみ+1
  }
  // day:日にち,nday:次の日のパスタ,tday:dayのパスタ,yday:前日のパスタ
  for(int day=2;day<=n;day++){
    for(int nday=1;nday<=3;nday++){
      if(p[day]!=0&&p[day]!=nday) continue;
      for(int yday=0;yday<4;yday++){
        for(tday=1;tday<4;tday++){
          if(yday==tday&&tday==nday) continue; //三日連続同じならスルー
          dp[tday][nday][day]+=dp[yday][tday][day-1]%=10000;
        }
      }
    }
  }
  int ans=0;
  for(int i=1;i<4;i++){
    for(int j=1;j<4;j++){
      ans+=dp[i][j][n];
    }
  }
  ans%=10000;
  cout<<ans<<endl;
}
