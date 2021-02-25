#include <bits/stdc++.h>
#include <math.h>
#include <vector>
#include <queue>
#include <iomanip>
#include <string>
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

int get_max(int x){
  while(x>=10){
    x/=10;
  }
  return x;
}

int main(){
  int n;
  cin >> n;
  int count[10][10];
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      count[i][j]=0;
    }
  }
  rep(i,n+1){
    if(i==0) continue;
    int x,y;
    x = get_max(i);
    y = i%10;
    count[x][y]++;
  }
  ll ans=0LL;
  /*for(int i=1;i<10;i++){
    for(int j=1;j<10;j++){
      cout << count[i][j] << " ";
    }
    cout << endl;
  }*/
  for(int i=1;i<10;i++){
    for(int j=i;j<10;j++){
      if(i!=j) ans += count[i][j]*count[j][i]*2;
      else ans += count[i][j]+count[i][j]*(count[i][j]-1);
    }
  }
  cout << ans;
}
