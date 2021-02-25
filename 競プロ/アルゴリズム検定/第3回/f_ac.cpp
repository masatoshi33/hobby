#include <bits/stdc++.h>
#include <math.h>
#include <vector>
#include <queue>
#include <iomanip>
#include <string>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
const ll INF = 101010101000;
const string small = "abcdefghijklmnopqrstuvwxyz";

int main(){
  int n;
  cin >> n;
  vector<vector<char>> a(n,vector<char>(n));
  vector<vector<int>> count(n,vector<int>(26));
  rep(i,n){
    rep(j,n){
      cin >> a[i][j];
      rep(k,26){
        if(small[k]==a[i][j]) count[i][k]++;
      }
    }
  }
  vector<char> ans(n);
  bool judge=true;
  rep(i,n){
    bool ok=false;
    rep(j,26){
      if(count[i][j]>0&&count[n-i-1][j]>0){
        ans[i] = small[j];
        ans[n-1-i] = small[j];
        ok=true;
      }
    }
    if(!ok) judge=false;
  }
  if(judge){
    rep(i,n){
      cout << ans[i];
    }
  }else cout << -1 << endl;
}
