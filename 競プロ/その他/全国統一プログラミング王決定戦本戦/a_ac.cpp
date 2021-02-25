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
const ll mod = 1000000007;

int main(){
  int n; cin>>n;
  vll a(n); rep(i,n) cin>>a[i];
  vll s(n+1);
  s[0]=0;
  rep(i,n) s[i+1]=s[i]+a[i];
  rep(k,n){
    ll ans=0;
    rep(i,n-k){
      ans=max(ans,s[i+k+1]-s[i]);
    }
    cout<<ans<<endl;
  }
}
