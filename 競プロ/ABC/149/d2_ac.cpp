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

int judge(char x){
  if(x=='r') return 2;
  else if(x=='s') return 0;
  else return 1;
}

int main(){
  int n,k;
  cin>>n>>k;
  int gomi=n/k+1;
  int dp[k][gomi][3];
  rep(i,k) rep(j,gomi) rep(l,3) dp[i][j][l] = 0;
  vi h(3);
  cin>>h[0]>>h[1]>>h[2];
  vector<char> t(n);
  rep(i,n) cin>>t[i];
  ll ans=0;
  rep(i,n){
    int x=judge(t[i]);
    if(i<k) ans+=h[x];
    else{
      if(t[i-k]==t[i]){
        t[i]=' ';
        continue;
      }else {
        ans+=h[x];
      }
    }
  }
  cout << ans;
}
