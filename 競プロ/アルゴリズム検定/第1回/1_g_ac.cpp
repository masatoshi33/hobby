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

int main(){
  int n;
  cin >> n;
  vector<vector<ll>> a(n,vector<ll>(n));
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      int x;
      cin >> x;
      a[i][j] = x;
    }
  }
  //入力チェック
  /*for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      cout << a[i][j];
    }
    cout << endl;
  }*/
  ll max_n = 1;
  rep(i,n+1) max_n *= 3;
  vector<int> group(n);
  ll ans = INF; //ansが歩にしかならない時があるから最小値として-INFを置かなきゃ
  ans *= -1;
  for(ll i=0;i<max_n;i++){
    ll sum = 0;
    ll x = i;
    rep(j,n){
      group[j] = x % 3;
      x /= 3;
      //cout << group[j] << endl;
    }
    for(int j=0;j<n-1;j++){
      for(int k=j+1;k<n;k++){
        if(group[j] == group[k]){
          sum += a[j][k];
        }
      }
    }
    if(ans<=sum){
      ans = sum;
      //cout << i << endl;
    }
  }
  cout << ans << endl;
  return 0;
}
