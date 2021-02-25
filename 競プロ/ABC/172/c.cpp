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
using vvi = vector<vi>;
using pii = pair<int,int>;

int main(){
  ll n,m,k;
  cin>>n>>m>>k;
  vector<ll> a(n),b(m);
  vector<ll> sum_a(n),sum_b(m);
  ll sum=0;
  rep(i,n){
    cin>>a[i];
  }
  rep(i,m){
    cin>>b[i];
  }
  sum_a[0]=a[0];
  sum_b[0]=b[0];
  rep(i,n-1){
    sum_a[i+1]=sum_a[i]+a[i];
    if(sum_a[i]>=k){
      n=i+1;
      break;
    }
  }
  rep(i,m-1){
    sum_b[i+1]=sum_b[i]+b[i];
    if(sum_b[i]>=k){
      m=i+1;
      break;
    }
  }
  if(sum_a[n-1]+sum_b[m-1]<=k){
    cout<<n+m;
    return 0;
  }
  int ans=0;
  rep(i,n){
    ll y = k-sum_a[i];
    if(y>=0){
      rep(j,m){
        if(sum_b[j]<=y) ans=max(ans,j+i+2);
      }
    }else{
      break;
    }
  }
  cout << ans;

}
