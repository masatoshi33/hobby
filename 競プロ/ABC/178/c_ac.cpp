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
const int mod=1000000007;

ll f(ll x,int n){
  ll ans=1;
  rep(i,n){
    ans*=x;
    ans%=mod;
  }
  return ans;
}

int main(){
  int n; cin>>n;
  ll ans=f(10LL,n)+2 *(mod-f(9LL,n))+f(8LL,n);
  ans%=mod;
  cout<<ans<<endl;
}
