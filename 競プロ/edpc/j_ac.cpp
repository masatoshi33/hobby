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
double dp[310][310][310];
int n;

double get(int i, int j, int k){
  if(i==0&&j==0&&k==0) return 0.0;
  if(dp[i][j][k]>=0) return dp[i][j][k];
  double ans = 0.0;
  if(i>0) ans += get(i-1,j,k)*i;
  if(j>0) ans += get(i+1,j-1,k)*j;
  if(k>0) ans += get(i,j+1,k-1)*k;
  ans+=n;
  ans *= 1.0/(i+j+k);
  return dp[i][j][k]=ans;
}

int main(){
  cin >> n;
  int c_1=0,c_2=0,c_3=0;
  rep(i,n){
    int x;
    cin >> x;
    if(x==1) c_1++;
    else if(x==2) c_2++;
    else c_3++;
  }
  rep(i,310){
    rep(j,310){
      rep(k,310){
        dp[i][j][k]=-1.0;
      }
    }
  }
  cout << setprecision(10);
  cout << get(c_1,c_2,c_3);
}
