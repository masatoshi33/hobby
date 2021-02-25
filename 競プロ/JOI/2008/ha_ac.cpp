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
  int n; cin>>n;
  int s=0; //手前の碁石
  int s0=0;
  vi b; //境界線
  rep(i,n){
    int x; cin>>x;
    if(i==0) s0=x;
    if(i%2==0){
      if(s!=x||i==0) b.push_back(i);
      s=x;
    }else{
      if(s==x) continue;
      int l=b.size();
      if(!b[l-1]==0) b.pop_back();
      s=x;
    }
  }
  b.push_back(n);
  int ans=0;
  int l=b.size();
  if(s==0&&l%2==1){
    for(int i=1;i<l-1;i+=2){
      ans+=b[i+1]-b[i];
    }
  }else if(s==1&&l%2==0){
    for(int i=1;i<l-1;i+=2){
      ans+=b[i+1]-b[i];
    }
  }else{
    for(int i=0;i<l-1;i+=2){
      ans+=b[i+1]-b[i];
    }
  }
  /*rep(i,l){
    cout<<b[i]<<" ";
  }
  cout<<endl;
  cout<<s<<endl;*/
  cout<<ans<<endl;
}
