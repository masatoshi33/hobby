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
  int n, m;
  cin >> n >> m;
  vector<bool> done(n);
  vector<int> wa(n);
  rep(i,n) done[i] = false;
  int p_count=0, a_count=0;
  rep(i,m){
    int x; string s;
    cin >> x >> s;
    if(done[x-1]) continue;
    if(s=="AC"){
      done[x-1] = true;
      a_count++;
      p_count+=wa[x-1];
    }else if(s=="WA") wa[x-1]++;
  }
  cout << a_count << " " << p_count;
}
