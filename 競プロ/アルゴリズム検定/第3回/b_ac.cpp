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
const string large = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string small = "abcdefghijklmnopqrstuvwxyz";
int main(){
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> score(m+1);
  vector<vector<int>> p(n);
  rep(i,q){
    int x,y,z;
    int ans=0;
    cin >> x >> y;
    if(x==1){
      for(auto a : p[y-1]){
        ans += n-score[a];
      }
      cout << ans << endl;
    }else{
      cin >> z;
      p[y-1].push_back(z);
      score[z]++;
    }
  }
}
