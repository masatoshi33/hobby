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
  int n,q; cin>>n>>q;
  Graph g(n);
  int c[n],s[n];
  rep(i,n) s[i]=-1;
  rep(i,n) c[i]=0;
  rep(i,n-1){
    int a,b; cin>>a>>b;
    a--;b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  rep(i,q){
    int p,x; cin>>p>>x;
    p--;
    c[p]+=x;
  }
  //rep(i,n) cout<<c[i]<<" ";
  //cout<<endl;
  stack<int> p;
  p.push(0);
  s[0]=c[0];
  while(!p.empty()){
    int y=p.top(); p.pop();
    for(auto x:g[y]){
      if(s[x]!=-1) continue;
      p.push(x);
      s[x]=s[y]+c[x];
      //cout<<s[x]<<endl;
    }
  }
  rep(i,n){
    if(i!=n-1) cout<<s[i]<<" ";
    else cout<<s[i];
  }
}
