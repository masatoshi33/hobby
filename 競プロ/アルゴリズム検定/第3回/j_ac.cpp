#include <bits/stdc++.h>
#include <math.h>
#include <vector>
#include <queue>
#include <iomanip>
#include <string>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
const ll INF = 1010101010;
vector<int> e(101010);
int f(int x,int s, int t){
  if(s==t){
    e[s] = x;
    return s;
  }
  if(e[(s+t)/2]>=x) f(x,(s+t)/2+1,t);
  else f(x,s,(s+t)/2);
}

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  rep(i,m) cin >> a[i];
  int min_e=INF;
  rep(i,m){
    bool no=true;
    if(a[i]<=min_e){
      if(e[n-1]!=0) cout << -1 << endl;
      else min_e=a[i];
    }
    cout << f(a[i],0,n-1) << endl;;
  }
}
