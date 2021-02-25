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
  vi a(n); rep(i,n) cin>>a[i];
  int x=max(n+1,1001);
  bool setjudge=false;
  rep(i,x){
    if(i<2) continue;
    bool judge=false;
    rep(j,n){
      if(judge&&a[j]%i==0){
        setjudge=true;
        break;
      }else if(a[j]%i==0) judge=true;
    }
  }
  if(setjudge){
    rep(i,x){
      if(i<2) continue;
      bool judge=true;
      rep(j,n){
        if(a[j]%i!=0) judge=false;
      }
      if(judge){
        cout<<"not coprime"<<endl;
        return 0;
      }
    }
    cout<<"setwise coprime"<<endl;
  }else{
    cout<<"pairwise coprime"<<endl;
  }
}
