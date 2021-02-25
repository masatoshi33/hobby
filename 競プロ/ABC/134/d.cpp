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
  vi a(n); rep(i,n) cin>>a[i];
  vi ans(n);
  for(int i=n;i>0;i--){
    int j=1,cnt=a[i-1];
    while(j*i<=n){
      if(ans[j*i-1]==1) cnt++;
      j++;
    }
    if(cnt%2==1) ans[i-1]=1;
  }
  int ans_cnt=0;
  rep(i,n){
    if(ans[i]==1) ans_cnt++;
  }
  cout<<ans_cnt<<endl;
  rep(i,n){
    if(ans[i]==1) cout<<i+1<< " ";
  }
}
