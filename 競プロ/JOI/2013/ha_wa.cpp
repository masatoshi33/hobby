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
  int n; cin>>n;
  vi num(n); rep(i,n) cin>>num[i];
  vi a;
  int cnt=0;
  rep(i,n){
    cnt++;
    if(num[i]==num[i+1]){
      a.push_back(cnt);
      cnt=0;
    }else if(i==n-1){
      a.push_back(cnt);
    }
  }
  int ans=0;
  int l=a.size();
  /*rep(i,l) cout<<a[i]<<" ";
  cout<<endl;*/
  for(int i=0;i<l-2;i++){
    ans=max(a[i]+a[i+1]+a[i+2],ans);
  }
  cout<<ans<<endl;
}
