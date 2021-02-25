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
using vl = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int,int>;

int main(){
  int n;
  cin>>n;
  vl a(n);
  rep(i,n) cin>>a[i];
  vl s(n+1);
  ll count=0;
  rep(i,n) s[i+1]=s[i]+a[i];
  map<ll,ll> y;
  rep(i,n+1){
    ll x = s[i];
    y[x]++;
  }
  for(auto z : y){
    if(z.second>1) count+=(z.second*(z.second-1)/2);
    //cout << z.second<< endl;
  }
  cout<<count<<endl;
}
