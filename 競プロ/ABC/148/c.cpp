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
using vvi = vector<vi>;
using pii = pair<int,int>;
//最大公約数
ll gcd(ll x, ll y){
  if(x%y==0){
    return y;
  }else{
    return(gcd(y,x%y));
  }
}
//最小公倍数
ll lcm(ll x, ll y){
  return x*y/gcd(x,y);
}


int main(){
  ll a,b;
  cin>>a>>b;
  cout << lcm(a,b);
}
