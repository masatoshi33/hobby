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
  vll a(n); rep(i,n) cin>>a[i];
  deque<int> d;
  // a[i]の値より小さいものがなければa[i]を先頭に追加し、あればその中で最大
  // のものをa[i]に置き換える。という操作をしている。
  rep(i,n){
    // p : a[i]より小さいものの中で最大のものの番号
    int p = lower_bound(d.begin(), d.end(), a[i]) - d.begin();
    if(p==0){
      d.push_front(a[i]);
    }else d[p-1] = a[i];
  }
  int ans = d.size();
  cout<<ans<<endl;
}
