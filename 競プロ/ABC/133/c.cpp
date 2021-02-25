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
  int l,r; cin>>l>>r;
  if(r-l>=2019){
    cout<<0<<endl;
    return 0;
  }
  l %= 2019;
  r %= 2019;
  if(r-l<=0){
    cout<<0<<endl;
    return 0;
  }
  int ans=2018;
  for(int i=l;i<=r;i++){
    for(int j=i+1;j<=r;j++){
      ans = min(ans, i*j%2019);
    }
  }
  cout<<ans<<endl;
}
