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
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  vector<vector<int>> ans(n);
  vector<int> f_ans(n);
  int j = 0;
  for(int i=0;i<n;i++){
    ans[j].push_back(i+1);
    int k = a[i];
    while(k!=i+1){
      ans[j].push_back(k);
      k = a[k-1];
    }
    for(auto x : ans[j]){
      f_ans[x-1] = ans[j].size();
    }
    j++;
  }
  rep(i,n-1) cout << f_ans[i] << " ";
  cout << f_ans[n-1];
}
