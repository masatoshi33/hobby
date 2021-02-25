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
  int n,q;
  cin>>n>>q;
  vi a(n);
  rep(i,n) a[i]=i;
  rep(i,q){
    int t,x,y;
    cin>>t>>x>>y;
    x--;y--;
    if(t==1){
      int z=a[x];
      a[x]=a[x+1];
      a[x+1]=z;
    }else{
      sort(a.begin()+x,a.begin()+y+1);
    }
  }
  rep(i,n){
    if(i<n-1) cout << a[i] << " ";
    else cout << a[i];
  }
}
