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
  vll p(m); rep(i,m) cin>>p[i];
  vll a(n-1),b(n-1),c(n-1);
  rep(i,n-1) cin>>a[i]>>b[i]>>c[i];
  vll s(n-1);
  rep(i,m-1){
    int x=p[i],y=p[i+1];
    if(x<y){
      s[x-1]++; s[y-1]--;
    }else{
      s[y-1]++; s[x-1]--;
    }
  }
  rep(i,n-2) s[i+1]+=s[i];
  ll ans=0;
  rep(i,n-1){
    ans+=min(a[i]*s[i],b[i]*s[i]+c[i]);
  }
  cout<<ans<<endl;
}
