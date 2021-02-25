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
  string x; cin>>x;
  ll m; cin>>m;
  int max_x=0;
  rep(i,x.length()){
    max_x = max(max_x, x[i]-'0');
  }
  int y=max_x+1;
  //cout<<y<<endl;
  //cout<<x.length()<<endl;
  int cnt=0;
  ll ans=0;
  while(ans<=m){
    ans=0;
    rep(i,x.length()){
      ans+=(x[x.length()-i-1]-'0')*pow(y,i);
    }
    y++;
    cnt++;
    if(ans>=576460752303423488) break;
    //cout<<ans<<endl;
    if(ans<0){
      break;
    }
  }
  //string lm = "456";
  //cout<<(lm[0]-'0')<<endl;
  cout<<cnt-1<<endl;
  //char z='7';
  //cout<<3*(z-'0')<<endl;
}
