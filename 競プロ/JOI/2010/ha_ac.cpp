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
  n--;
  vll a(n); vi b(m);
  rep(i,n) cin>>a[i]; rep(i,m) cin>>b[i];
  vll s(n+1); s[0]=0LL;
  rep(i,n) s[i+1]=s[i]+a[i];
  ll ans=0;
  int now=0;
  rep(i,m){
    ans+=abs(s[b[i]+now]-s[now]);
    //cout<<abs(s[b[i]+now]-s[now])<<endl;
    now+=b[i];
  }
  ans%=100000;
  cout<<ans<<endl;
}
