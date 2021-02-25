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
  ll n; cin>>n;
  ll a[n+1],b[n+1],c[n+1];
  rep(i,n) cin>>a[i];
  rep(i,n) cin>>b[i];
  rep(i,n) cin>>c[i];
  sort(a,a+n);
  sort(b,b+n);
  sort(c,c+n);
  ll count=0;
  ll count_b[n];
  a[n] = b[n] = c[n] = 1000000007;
  /*rep(i,n){
    ll x_c = lower_bound(c,c+n+1,b[n-1-i]+1)-c;
    if(i==0)count_b[n-1-i]=n-x_c;
    else count_b[n-1-i]=count_b[n-i]+n-x_c;
  }
  for(auto x : a){
    ll x_b = lower_bound(b,b+n+1,x+1)-b;
    count+=count_b[x_b];
  }*/
  for (int i = 0; i < n; i++) count += 1ll * (lower_bound(a, a + n + 1, b[i]) - a) * (n - (upper_bound(c, c + n + 1, b[i]) - c));
  cout<<count<<endl;
}
