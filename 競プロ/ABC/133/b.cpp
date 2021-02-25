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
  int n,d; cin>>n>>d;
  vvi x(n,vi(d));
  rep(i,n)rep(j,d){
    cin>>x[i][j];
    //cout<<x[i][j]<<endl;
  }
  int cnt=0;
  rep(i_y,n){
    for(int j_y=i_y+1;j_y<n;j_y++){
      int sum=0;
      rep(j,d){
        sum += pow(x[i_y][j]-x[j_y][j],2);
      }
      rep(i,150){
        if(sum==pow(i+1,2)){
          cnt++;
          //cout<<sum<<endl;
        }
      }
    }
  }
  cout<<cnt<<endl;
}
