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
  int n; cin>>n;
  vector<pair<int,int>> d(n);
  rep(i,n){
    int x,y; cin>>x>>y;
    d[i].first=x;
    d[i].second=y;
  }
  rep(i,n-2){
    if(d[i].first==d[i].second){
      if(d[i+1].first==d[i+1].second){
        if(d[i+2].first==d[i+2].second){
          cout<<"Yes"<<endl;
          return 0;
        }
      }
    }
  }
  cout<<"No"<<endl;
}
