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
  int n,m; cin>>n>>m;
  vi a(m),b(m);
  vi cost(n,INF);
  rep(i,m){
    cin>>a[i]>>b[i];
    rep(j,b[i]){
      int x; cin>>x; x--;
      if(cost[x]>a[i]) cost[x]=a[i];
    }
  }
  int ans=0;
  vi costl;
  rep(i,n){
    bool judge=false;
    if(cost[i]==INF){
      cout<<-1<<endl;
      return 0;
    }
    for(auto x:costl){
      if(x==cost[i]) judge=true;
    }
    if(judge) continue;
    ans+=cost[i];
    costl.push_back(cost[i]);
  }
  cout<<ans<<endl;
}
