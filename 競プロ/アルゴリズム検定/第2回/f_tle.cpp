#include <bits/stdc++.h>
#include <math.h>
#include <vector>
#include <queue>
#include <iomanip>
#include <string>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
const ll INF = 101010101000;

int main(){
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  rep(i,n) cin >> a[i] >> b[i];
  int ans=0;
  vector<vector<pair<int,int>>> c(n+1); //n+1日目に可能なタスク
  rep(i,n){
    int j = a[i];
    pair<int,int> p(b[i],a[i]);
    c[j-1].push_back(p);
  }
  rep(i,n){
    int ans_0 = 0;
    int x = 0;
    sort(c[0].begin(),c[0].end());
    reverse(c[0].begin(),c[0].end());
    ans += c[0][0].first;
    c[0][0].first = 0;
    if(i==n-1) cout << ans;
    else cout << ans << endl;
    for(auto p : c[i+1]){
      c[0].push_back(p);
    }
  }
}
