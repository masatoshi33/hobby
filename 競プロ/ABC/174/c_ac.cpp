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
  int k; cin>>k;
  ll s=7;
  int ans=-1;
  ll x=7;
  if(k==1||k==7){
    cout<<1<<endl;
    return 0;
  }else if(k==11||k==77){
    cout<<2<<endl;
    return 0;
  }
  rep(i,1010100){
    x*=10;
    x%=k;
    s+=x;
    s%=k;
    if(s==0){
      ans=i+2;
      break;
    }
  }
  cout<<ans<<endl;
}
