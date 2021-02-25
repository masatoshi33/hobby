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
  vi a(n),b(n); rep(i,n) cin>>a[i]>>b[i];
  vi c_a(101010), c_b(101010);
  rep(i,n){
    c_a[a[i]]++; c_b[b[i]]++;
  }
  bool judge=true;
  rep(i,101010){
    if(c_a[i]+c_b[i]>=n) judge=false;
  }
  if(!judge) cout<<"No"<<endl;
  else{
    cout<<"Yes"<<endl;
    rep(i,n){
      if(b[n-i-1]==a[i]){
        int x=0;
        while(b[n-i-1])
        int tmp=b[n-i-1];

      }
    }
  }
}
