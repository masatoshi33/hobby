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
  string s; cin>>s;
  string alpha = "abcdefghijklmnopqrstuvwxyz";
  string Alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  bool judge=true;
  for(int i=0;i<s.length();i++){
    bool judge1=false;
    if(i%2==0)rep(j,26){
      if(alpha[j]==s[i]) judge1 = true;
    }else{
      rep(j,26){
        if(Alpha[j]==s[i]) judge1 = true;
      }
    }
    if(!judge1) judge = false;
  }
  if(judge) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
