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

int f(int x){
  int cnt=0;
  int tmp=x;
  for(int i=1;i<sqrt(x);i++){
    if(tmp%i==0) cnt++;
  }
  cnt*=2;
  int y=sqrt(x)*1;
  if(y!=0&&y*y==x&&x%y==0) cnt++;
  return cnt;
}
int main(){
  int n; cin>>n;
  int ans=0;
  for(int i=i;i<n;i++){
    ans+=f(i);
  }
  cout<<ans<<endl;
}
