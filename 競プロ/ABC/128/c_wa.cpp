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
  int n,m; cin>>n>>m;
  vi k(m);
  vector<set<int>> s(m);
  rep(i,m){
    cin>>k[i];
    rep(j,k[i]){
      int in; cin>>in;
      s[i].insert(in);
    }
  }
  //各電球のonのスイッチの合計
  vi sum(m);
  int p=0;
  int cnt=0;
  rep(i,m){
    int p_0; cin>>p_0;
    p+=(1<<i)*p_0;
  }
  rep(i,1<<n){
    int res=0;
    rep(i_1,m){
      rep(j,n){
        if(((i>>j)&1)&&s[i_1].count(j+1)) sum[i_1]++;
      }
    }
    //check
    /*bool judge=true;
    rep(i_2,m){
      if(sum[i_2]%2!=p[i_2]) judge=false;
    }
    if(judge) count++;*/
    rep(j,n){
      res+=(sum[j]%2)*(1<<j);
    }
    if(res==p) cnt++;
  }
  cout<<cnt;
}
