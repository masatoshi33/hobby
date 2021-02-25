#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <iomanip>
#include <string>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
const ll INF = 1010101010;
int dp[60][60];
vector<vector<pair<int,int>>> num(11);

int dist(pair<int,int> p_1,pair<int,int> p_2){
  return abs(p_1.first-p_2.first)+abs(p_1.second-p_2.second);
}

ll dfs(pair<int,int> p,int N){
  if(N==0) return 0;
  if(dp[p.first][p.second]!=INF) return dp[p.first][p.second];
  ll ans=INF;
  for(auto x : num[N-1]){
    ans = min(ans,dfs(x,N-1)+dist(p,x));
    cout << x.first << " " << x.second << endl;
  }
  return dp[p.first][p.second] = ans;
}

int main(){
  int n, m;
  cin >> n >> m;
  char a[n][m];
  rep(i,n){
    rep(j,m){
      cin >> a[i][j];
    }
  }
  vector<vector<pair<int,int>>> num(11);
  pair<int,int> g;
  rep(i,n){
    rep(j,m){
      dp[i][j]=INF;
      pair<int,int> p;
      p.first = i;
      p.second = j;
      if(a[i][j]=='S'){
        num[0].push_back(p);
      }else if(a[i][j]=='G'){
        num[10].push_back(p);
        g = p;
      }else{
        int x = a[i][j]-'0';
        num[x].push_back(p);
      }
    }
  }
  for(int i=1;i<10;i++){
    if(num[i].empty()){
      cout << -1 << endl;
    }
  }
  //g.first = 2;
  //g.second = 2;
  ll ans = dfs(g,10);
  cout << ans << endl;
  //確認用
  rep(i,11){
    for(auto x : num[i]){
      cout << i << ":" << x.first << x.second << endl;
    }
  }
  rep(i,n){
    rep(j,m){
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
  pair<int,int> s_1;
  s_1.first = 0;
  s_1.second = 0;
  cout << dfs(s_1,1);
}
