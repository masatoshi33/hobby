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
  int n,m,Q; cin>>n>>m>>Q;
  vvi x(n+1,vi(n+1));
  rep(i,m){
    int l,r; cin>>l>>r;
    x[l][r]++;
  }
  vvi c(n+1,vi(n+1));
  //rep(i,n)rep(j,n) c[i+1][j+1]+=c[i+1][j]+x[i+1][j+1];
  rep(i,n)rep(j,n) c[i+1][j+1]+=c[i+1][j]+c[i][j+1]-c[i][j]+x[i+1][j+1];
  rep(i,Q){
    int p,q; cin>>p>>q;
    int ans=0;
    //for(int j=p;j<q+1;j++) ans+=c[j][q]-c[j][p-1];
    ans=c[q][q]-c[p-1][q]-c[q][p-1]+c[p-1][p-1];
    cout<<ans<<endl;
  }
}
