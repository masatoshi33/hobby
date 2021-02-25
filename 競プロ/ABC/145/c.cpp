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
  vector<pair<double,double>> p(n);
  rep(i,n){
    double x,y; cin>>x>>y;
    p[i]={x,y};
  }
  cout<<setprecision(10);
  vi a(n); rep(i,n) a[i]=i;
  double dist=0.0;
  do{
    rep(i,n-1){
      dist+=pow(pow((p[a[i]].first-p[a[i+1]].first),2.0)+pow(p[a[i]].second-p[a[i+1]].second,2.0),0.5);
    }
    //rep(i,n) cout<<a[i]<<" ";
    //cout<<endl;
  }while(next_permutation(a.begin(),a.end()));
  double kaijou=1;
  rep(i,n){
    kaijou*=(i+1);
  }
  cout<<dist/kaijou<<endl;
}
