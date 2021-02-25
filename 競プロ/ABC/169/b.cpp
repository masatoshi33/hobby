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

int main(){
  int n;
  cin>>n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  rep(i,n){
    if(a[i]==0){
      cout <<0;
      return 0;
    }
  }
  ll ans=1;
  rep(i,n){
    if(1000000000000000000/ans<a[i]){
      cout <<-1;
      return 0;
    }
    ans*= a[i];
  }
  cout << ans;
}
