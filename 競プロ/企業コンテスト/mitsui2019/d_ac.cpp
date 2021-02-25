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
  string s; cin>>s;
  set<int> ans;
  int cnt=0;
  rep(i,10){
    rep(j,10){
      rep(k,10){
        bool judge1=false,judge2=false,judge3=false;
        rep(x,n){
          if(!judge1&&i==s[x]-'0') judge1=true;
          else if(!judge2&&!judge3&&judge1&&s[x]-'0'==j) judge2=true;
          else if(!judge3&&judge2&&s[x]-'0'==k) judge3=true;
        }
        if(judge3){
          cnt++;
          cout<<i*100+j*10+k<<" ";
        }
      }
    }
  }
  cout<<endl;
  cout<<cnt;
}
