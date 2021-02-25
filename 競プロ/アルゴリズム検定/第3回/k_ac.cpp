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
  int n,q;
  cin >> n >> q;
  //自分の下の箱の番号
  vi under(n);
  //i番目の台の一番高い箱の番号
  vi top(n);
  rep(i,n){
    under[i] = -1;
    top[i] = i;
  }

  rep(i,q){
    int f, t, x;
    cin >> f >> t >> x;
    f--, t--, x--;
    int n_top = top[f];
    top[f] = under[x];

    under[x] = top[t];
    top[t] = n_top;
  }
  vi ans(n);
  rep(i,n){
    int cur = top[i];
    while(cur!=-1){
      ans[cur]=i;
      cur=under[cur];
    }
  }
  rep(i,n) cout << ans[i]+1 << endl;
}
