#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <iomanip>
#include <string>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
const ll INF = 101010101000;
ll n, m, v, p;

int main(){
  cin >> n >> m >> v >> p;
  vector<ll> a(n),b(n);
  rep(i,n) cin >> a[i];
  sort(a.begin(),a.end());
  b[0] = a[0];
  for(int i=1;i<n;i++) b[i] = b[i-1] + a[i];
  ll max_a = a[n-1];
  vector<ll> u_score(max_a+1);
  rep(i,n){
    int x = a[i];
    u_score[x]++;
  }
  rep(i,max_a+1){
    if(i!=0) u_score[i] = u_score[i-1]+u_score[i];
  }
  int ans = 0;
  for(int i=0;i<n;i++){
    int s = a[i];
    if(i>=n-p){
      ans++;
      continue;
    }else if(a[i]+m<a[p-1]){
      continue;
    }
    bool judge = false;
    ll amount = (u_score[s]+p-1)*m;
    amount += (s+m)*(n-p+1-u_score[s]);
    amount -= b[n-p] - b[u_score[s]-1];
    if(amount>=v*m) judge = true;
    if(judge) ans++;
  }
  cout << ans << endl;
}
