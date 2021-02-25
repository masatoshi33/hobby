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
const ll l_INF = 101010101000;
const int INF = 1010101010;
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int,int>;

int main(){
  ll n,m; cin>>n>>m;
  vll p(n+1);
  rep(i,n+1) p[i]=0;
  rep(i,n) cin>>p[i];
  vll q;
  sort(p.begin(),p.end());
  rep(i,n+1){
    rep(j,n+1){
      if(p[i]+p[j]<=m)q.push_back(p[i]+p[j]);
    }
  }
  sort(q.begin(),q.end());
  ll ans=0;
  rep(i_1,n+1){
    rep(i_2,n+1){
      if(p[i_1]+p[i_2]<=m){
        ll x=m-(p[i_1]+p[i_2]);
        int y = upper_bound(q.begin(),q.end(),x)-q.begin();
        ans=max(ans,p[i_1]+p[i_2]+q[y-1]);
      }
    }
  }
  cout<<ans<<endl;
}
