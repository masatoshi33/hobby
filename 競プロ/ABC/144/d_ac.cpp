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
  const double pi=3.141592653589793;
  double a,b,x; cin>>a>>b>>x;
  cout<<setprecision(20);
  double left=0.0,right=90.0,mid;
  if(a*a*b>=2.0*x){
    while(right-left>1e-10){
      mid=(right+left)/2.0;
      if(a*b*b<=2*x*tan(mid*pi/180.0)) right=mid;
      else left=mid;
    }
  }else{
    while(right-left>1e-10){
      mid=(right+left)/2.0;
      if(a*a*(2.0*b-a*tan(mid*pi/180.0))<=2.0*x) right=mid;
      else left=mid;
    }
  }
  cout<<(right+left)/2.0<<endl;
}
