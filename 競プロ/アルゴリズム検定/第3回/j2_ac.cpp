#include <bits/stdc++.h>
#include <math.h>
#include <vector>
#include <queue>
#include <iomanip>
#include <string>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
const ll INF = 1010101010;
vector<int> t(301010);
int n, m;
//二分探索
//s:start,e:end,x:来た寿司
/*int search1(int s, int e, int x){
  if(s==e){
    t[s] = x;
    if(s+1<=n) return s+1;
    else return -1;
  }
  if(t[(s+e)/2]<=x) search(s,(s+e)/2,x);
  else search((s+e)/2+1,e,x);
}*/
int search2(int x){
  int s=0,e=n;
  while(s<e){
    if(t[(s+e)/2]<x) e = (s+e)/2;
    else s = (s+e)/2+1;
  }
  t[s] = x;
  if(s<=n-1) return s+1;
  else return -1;
}

int main(){
  cin >> n >> m;
  rep(i,m){
    int a;
    cin >> a;
    if(i<m-1) cout << search2(a) << ' ';
    else cout << search2(a) << endl;
  }
  rep(i,5) cout << t[i] << ' ';
}
