#include <bits/stdc++.h>
#include <math.h>
#include <vector>
#include <queue>
#include <iomanip>
#include <string>
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
using vvi = vector<vi>;
using pii = pair<int,int>;

int main(){
  int n;
  cin >> n;
  set<int> a;
  vi c(1010100);
  rep(i,n){
    int y;
    cin >> y;
    a.insert(y);
    c[y]++;
  }
  for(auto x : a){
    int num=x*2;
    while(num<=1000000){
      if(a.count(num)){
        a.erase(num);
      }
      c[num]=0;
      num+=x;
    }
  }
  ll sum=0;
  rep(i,1010100) if(c[i]>1) sum+=c[i];
  ll ans=0;
  rep(i,1010100) ans += c[i];
  cout << ans - sum;
}
