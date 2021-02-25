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
  int x, n;
  vi p(101);
  cin >> x >> n;
  rep(i,n){
    int y;
    cin >> y;
    p[y]++;
  }
  rep(i,101){
    if(p[x-i]==0){
      cout << x-i;
      return 0;
    }else if(p[x+i]==0){
      cout << x+i;
      return 0;
    }
  }
}
