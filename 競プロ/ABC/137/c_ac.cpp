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
  int n; cin>>n;
  vector<string> s(n); rep(i,n) cin>>s[i];
  rep(i,n) sort(s[i].begin(),s[i].end());
  sort(s.begin(),s.end());
  vll num;
  ll cnt=1;
  rep(i,n-1){
    if(i<n-2&&s[i]==s[i+1]) cnt++;
    else{
      if(s[i]==s[i+1]) cnt++;
      num.push_back(cnt);
      cnt=1;
    }
  }
  ll ans=0;
  for(auto x:num){
    ans+=(x-1)*x/2;
  }
  cout<<ans<<endl;
}
