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
  long double p; cin>>p;
  //double time=x+p/(pow(2,x/1.5));
  long double left=0.0, right=p+1, m;
  while(right-left>1e-15){
    m=(right+left)/2;
    //cout<<m+p*pow(2,-m/1.5)<<endl;
    if(1-(p*(log(2)/1.5)*pow(2,-m/1.5))<0) left=m;
    else right=m;
    //cout << m << endl;
  }
  long double ans=m+p*pow(2,-m/1.5);
  cout<<setprecision(20);
  cout<<ans<<endl;
}
