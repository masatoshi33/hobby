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

bool check(int a){
  if(a==2||a==3||a==5||a==7) return true;
  int a_2 = sqrt(a);
  for(int i=2;i<=a_2+1;i++){
    if(a%(i)==0) return false;
  }
  return true;
}
int main(){
  int x;
  cin>>x;
  while(true){
    if(check(x)){
      cout << x;
      return 0;
    }
    x++;
  }
}
