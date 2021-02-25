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
  int r,c; cin>>r>>c;
  vvi s(r,vi(c));
  rep(i,r)rep(j,c) cin>>s[i][j];
  int ans=0;
  rep(i,1<<r){
    int m_cnt=0;
    rep(j,c){
      int cnt=0;
      rep(k,r){
        if((i>>k)&1) s[k][j]=(s[k][j]+1)%2;
        if(s[k][j]==1) cnt++;
      }
      if(cnt<r/2) cnt=r-cnt;
      m_cnt+=cnt;
    }
    ans=max(ans,m_cnt);
  }
  cout<<ans<<endl;
}
