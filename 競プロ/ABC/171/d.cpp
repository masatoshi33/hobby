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

int main(){
  int n;
  cin >> n;
  map<ll,ll> a;
  rep(i,n){
    ll x;
    cin >> x;
    a[x]+=x;
  }
  ll ans=0;
  for(auto x : a){
    ans+=x.second;
  }
  int q;
  cin >>q;
  rep(i,q){
    ll b,c;
    cin >> b >> c;
    a[c]+=a[b]/b*c;
    ans += a[b]/b*c-a[b];
    a[b]=0;
    cout <<ans<<endl;
  }
}
