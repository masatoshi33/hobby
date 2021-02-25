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
const string alpha="abcdefghijklmnopqrstuvwxyz";
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

int main(){
  string s,t; cin>>s>>t;
  vll a(26),b;
  rep(i,s.size())rep(j,26){
    if(s[i]==alpha[j]) a[j]=i+1;
  }
  rep(i,t.size())rep(j,26){
    if(t[i]==alpha[j]) b.push_back(a[j]);
  }
  ll cnt=0;
  rep(i,t.size()){
    if(b[i]<b[i+1]) continue;
    else{
      cnt++;
    }
  }
  ll ans=cnt*s.size()+b[t.size()-1];
  cout<<ans<<endl;
}
