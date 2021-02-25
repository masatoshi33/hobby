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
  double n, k;
  cin >> n >> k;
  vector<double> sum(n);
  rep(i,n){
    double x;
    cin >> x;
    if(i>0) sum[i] += sum[i-1] + (x+1.0)/2;
    else sum[i] = (x+1.0)/2;
  }
  double ans = 0;
  if(ans<sum[k-1]) ans = sum[k-1];
  rep(i,n-k){
    double x = sum[i+k]-sum[i];
    if(ans<x) ans = x;
  }
  cout << setprecision(10);
  cout << ans << endl;
}
