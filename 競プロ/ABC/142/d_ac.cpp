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
  ll a,b; cin>>a>>b;
  if(a>b) swap(a,b);
  while(b%a!=0){
    b=b%a;
    if(a>b) swap(a,b);
    if(a==0) break;
  }
  //cout<<sqrt(a)<<endl;
  int cnt=1;
  ll c=a;
  for(int i=2;i<=sqrt(a);i++){
    bool judge=false;
    while(a%i==0){
      a/=i;
      judge=true;
    }
    if(judge){
      cnt++;
      //cout<<i<<endl;
    }
  }
  if(a>1) cnt++;
  cout<<cnt<<endl;
}
