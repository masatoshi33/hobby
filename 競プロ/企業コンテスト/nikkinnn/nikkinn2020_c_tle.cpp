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
  int n,k;
  cin >> n >> k;
  vector<int> a(n);
  vector<int> b(n);
  rep(i,n) cin >> a[i];
  rep(i,k){
    rep(j,n){
      for(int l=j-a[j];l<=j+a[j];l++){
        if(l>=0&&l<n) b[l]++;
      }
    }
    rep(j,n) a[j] = b[j]:
    rep(j,n) b[j] = 0;
  }
  rep(i,n){
    if(i!=n-1) cout << a[i] << ' ';
    else cout << a[i];
  }
}
