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
  vll l(n); rep(i,n) cin>>l[i];
  int cnt=0;
  sort(l.begin(),l.end());
  rep(i,n)for(int j=i+1;j<n;j++)for(int k=j+1;k<n;k++){
    if(l[i]==l[j]||l[j]==l[k]||l[i]==l[k]) continue;
    if(l[i]+l[j]>l[k]) cnt++;
  }
  cout<<cnt<<endl;
}
