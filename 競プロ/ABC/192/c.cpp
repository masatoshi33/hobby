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
  ll n,k; cin>>n>>k;
  rep(j,k){
    vll a;
    ll x=0;
    while(n>0){
      a.push_back(n%10);
      n/=10;
    }
    sort(a.begin(),a.end());
    rep(i,a.size()){
      x+=a[i]*pow(10,i);
      x-=a[i]*pow(10,a.size()-i-1);
    }
    n = x;
  }
  cout<<n<<endl;
}
