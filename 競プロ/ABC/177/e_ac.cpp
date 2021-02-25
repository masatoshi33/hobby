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
  map<int,int> insu;
  vi a(n); rep(i,n) cin>>a[i];
  rep(i,n){
    int x=a[i];
    for(int j=2;j<=sqrt(x);j++){
      if(x%j==0) insu[j]++;
      while(x%j==0){
        x/=j;
      }
    }
    if(x>1) insu[x]++;
  }
  bool judge0=true,judge1=false;
  for(auto x:insu){
    if(x.second>1) judge0=false;
  }
  if(judge0){
    cout<<"pairwise coprime"<<endl;
    return 0;
  }
  for(auto x:insu){
    if(x.second==n) judge1=true;
  }
  if(judge1){
    cout<<"not coprime"<<endl;
    return 0;
  }
  cout<<"setwise coprime"<<endl;
}
