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
const ll l_INF = 101010101000;
const int INF = 1010101010;
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int,int>;

int main(){
  int n; cin>>n;
  vector<set<int>> good(n);
  vector<set<int>> bad(n);
  rep(i,n){
    int a; cin>>a;
    rep(j,a){
      int x,y; cin>>x>>y;
      x--;
      if(y==1) good[i].insert(x);
      if(y==0) bad[i].insert(x);
    }
  }
  int ans=0;
  cout<<"good"<<endl;
  rep(i,n){
    cout<<i<<":";
    for(auto z : good[i]){
      cout<<z;
    }
    cout<<endl;
  }
  cout<<"bad"<<endl;
  rep(i,n){
    cout<<i<<":";
    for(auto z : bad[i]){
      cout<<z;
    }
    cout<<endl;
  }
  rep(i,1<<n){
    int count=0;
    rep(j,n){
      if(i&(1<<j)) count++;
    }
    bool judge=true;
    rep(j,n){
      rep(k,n){
        if(j!=k&&((i>>j)&1)&&((i>>k)&1)){
          if(!good[j].count(k)) judge=false;
          if(bad[j].count(k)) judge=false;
        }
        if(j!=k&&((i>>j)&1)&&((i>>k)&0)){
          if(good[j].count(k)) judge=false;
        }
      }
    }
    if(judge){
      ans=max(ans,count);
      cout<<i<<endl;
    }
  }
  cout<<ans;
  return 0;
}
