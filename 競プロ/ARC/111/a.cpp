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
  int t; cin>>t;
  rep(i,t){
    int x,y;
    cin>>x>>y;
    ll n;
    if(y==0){
      cout<<1<<endl;
      continue;
    }
    if(y/2<x){
      cout<<0<<endl;
      continue;
    }
    n = y-x;
    if(x!=0) cout<<n*(n-1)/2<<endl;
    else cout<<n*(n-1)/2+n+1<<endl;
  }
}
