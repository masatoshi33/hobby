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
  int n; cin>>n;
  vi a(n); rep(i,n) cin>>a[i];
  int max=0, max_i=0, s_max=0;
  rep(i,n){
    if(max<=a[i]){
      s_max = max;
      max = a[i];
      max_i = i;
    }else if (s_max<=a[i]){
      s_max = a[i];
    }
  }
  rep(i,n){
    if(i==max_i) cout<<s_max<<endl;
    else cout<<max<<endl;
  }
}
