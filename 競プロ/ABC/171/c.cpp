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
  ll n;
  cin >> n;
  const string x = "abcdefghijklmnopqrstuvwxyz";
  string ans="";
  while(n>0){
    n--;
    int y=n%26;
    ans = x[y]+ans;
    n/=26;
  }
  /*rep(i,20){
    if(n<=pow(26,i)){
      n--;
      rep(j,i){
        int y=n%26;
        ans = x[y] + ans;
        n/=26;
      }
      break;
    }else{
      n -= pow(26,i);
    }
  }*/
  cout << ans;
}
