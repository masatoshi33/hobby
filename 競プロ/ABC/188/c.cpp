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
  vector<int> a(1<<n);
  rep(i,1<<n) cin>>a[i];
  int f_max=0, f_max_i=0;
  rep(i,(1<<n)/2){
    if(f_max<a[i]){
      f_max = a[i];
      f_max_i = i;
    }
  }
  int s_max=0, s_max_i=0;
  rep(i,(1<<n)/2){
    if(s_max<a[i+(1<<n)/2]){
      s_max = a[i+(1<<n)/2];
      s_max_i = i + (1<<n)/2;
    }
  }
  int ans=0;
  if(s_max<f_max) ans = s_max_i;
  else ans = f_max_i;
  cout<<ans+1<<endl;
}
