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
  int n; cin>>n;
  vll x(n), y(n);
  rep(i,n) cin>>x[i]>>y[i];
  vll s(n), d(n);
  rep(i,n){
    s[i]=abs(x[i]+y[i]);
    d[i]=x[i]-y[i];
  }
  sort(s.begin(),s.end());
  sort(d.begin(),d.end());
  ll ans_0=s[n-1]-s[0];
  ll ans_1=d[n-1]-d[0];
  ll ans=max(ans_0,ans_1);
  cout<<ans<<endl;
}
