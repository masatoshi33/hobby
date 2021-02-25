#include <bits/stdc++.h>
#include <math.h>
#include <vector>
#include <queue>
#include <iomanip>
#include <string>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
const ll l_INF = 101010101000;
const int INF = 1010101010;

int main(){
  int n,m,q;
  cin >> n >> m >> q;
  Graph G(n);
  vector<int> c(n);
  rep(i,m){
    int a, b;
    cin >> a >> b;
    a--;b--;
    G[a].push_back(b);
    G[b].push_back(a); //無向グラフなので双方向
  }
  rep(i,n) cin >> c[i];
  rep(i,q){
    int x,y,z;
    cin >> x >> y;
    if(x==1){
      cout << c[y-1] << endl;
      for(auto t : G[y-1]){
        c[t] = c[y-1]; //塗り替える
      }
    }else{
      cin >> z;
      cout << c[y-1] << endl;
      c[y-1] = z;
    }
  }
}
