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
using vl = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int,int>;

int main(){
  int h,w,k;
  cin>>h>>w>>k;
  vector<vector<char>> c(h,vector<char>(w));
  vvi d(h,vector<int>(w));
  rep(i,h)rep(j,w) cin>>c[i][j];
  int ans=0;
  rep(i,h)rep(j,w){
    if(c[i][j]=='#'){
      d[i][j]=1;
    }
  }
  for(int i=0;i<pow(2,h);i++){
    for(int j=0;j<pow(2,w);j++){
      int count=0;
      for(int k=0;k<h;k++){
        for(int l=0;l<w;l++){
          if(i>>k&1) continue;
          if(j>>l&1) continue;
          count+=d[k][l];
        }
      }
      if(count==k) ans++;
    }
  }
  cout<<ans;
}
