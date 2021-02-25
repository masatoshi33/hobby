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
  int d_0; cin>>d_0;
  int n; cin>>n;
  int m; cin>>m;
  vi d;
  d.push_back(0);
  d.push_back(d_0);
  rep(i,n-1){
    int x;
    cin>>x;
    d.push_back(x);
    d.push_back(x+d_0);
    d.push_back(x-d_0);
  }
  vi k(m);
  rep(i,m) cin>>k[i];
  sort(d.begin(),d.end());
  int sum=0;
  //rep(i,m)cout<<k[i]<<" ";
  //cout<<endl;
  //for(auto x:d) cout<<x<<" ";
  //cout<<endl;
  rep(i,m){
    int x_0=k[i];
    auto x=lower_bound(d.begin(),d.end(),x_0);
    auto y=lower_bound(d.begin(),d.end(),x_0)-1;
    int z=min(abs(k[i]-*y),abs(*x-k[i]));
    sum+=z;
    //cout<<z<<" ";
  }
  //cout<<endl;
  cout<<sum<<endl;
}
