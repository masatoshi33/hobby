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

ll gcd(ll x, ll y){
  if(x%y==0){
    return y;
  }else{
    return(gcd(y,x%y));
  }
}
ll lcm(ll x, ll y){
  return x*y/gcd(x,y);
}
int count_2(int x){
  int ans=0;
  while(x%2==0){
    x/=2;
    ans++;
  }
  return ans;
}
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i,n){
    cin >> a[i];
    a[i]/=2;
  }
  ll x=1;
  rep(i,n){
    x = lcm(x,a[i]);
  }
  vector<int> count(n);
  rep(i,n) count[i] = c(a[i]);
  bool ok=true;
  rep(i,n-1) if(count[i]!=count[n-1]) ok = false;
  if(x>m||!ok) cout << 0 << endl;
  else{
    int ans = m / x;
    ans = (ans+1)/2;
    cout << ans << endl;
  }
}
