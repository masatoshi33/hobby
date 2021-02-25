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
const ll l_INF = 101010101000;
const int INF = 1010101010;
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;

int main(){
  int n; cin>>n;
  ll d[n][n];
  ll s[n+1][n+1];
  rep(i,n) rep(j,n) cin>>d[i][j];
  rep(i,n){
    rep(j,n){
      s[i+1][j+1]=s[i][j+1]+s[i+1][j]-s[i][j]+d[i][j];
    }
  }
  //m[i]:面積i以下における最大の美味しさ
  ll m[n*n+1];
  rep(i,n*n+1) m[i]=0; //初期化
  //それぞれの長方形に対して全探索
  for(int x1=0;x1<n;x1++){
    for(int x2=x1+1;x2<=n;x2++){
      for(int y1=0;y1<n;y1++){
        for(int y2=y1+1;y2<=n;y2++){
          ll area=(x2-x1)*(y2-y1);
          ll sum=s[x2][y2]-s[x2][y1]-s[x1][y2]+s[x1][y1];
          m[area]=max(m[area],sum);
        }
      }
    }
  }
  //各面積での最大値から各面積以下の最大値を出す
  rep(i,n*n) m[i+1]=max(m[i+1],m[i]);
  int q; cin>>q;
  rep(i,q){
    int p;
    cin>>p;
    cout << m[p] << endl;
  }
}
