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
  int n,k; cin>>n>>k;
  string s; cin>>s;
  vi num;
  int ans=0;
  int cnt=1;
  rep(i,n-1){
    if(s[i]==s[i+1]&&i<n-2) cnt++;
    else{
      if(cnt>1) ans+=(cnt-1);
      num.push_back(cnt);
      cnt=1;
    }
  }
  for(auto x:num) cout<<x<<endl;
  ans+=(2*k);
  if(ans>(n-1)) cout<<n-1<<endl;
  else cout<<ans<<endl;
}
