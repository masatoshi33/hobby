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

ll j(ll x){
  for(ll i=1;i<x;i++){
    if(x>=i*(i+1)/2&&x<(i+1)*(i+2)/2){
      return i;
    }
  }
}

int main(){
  ll n;
  cin >> n;
  if(n==1){
    cout << 0 << endl;
    return 0;
  }
  ll ans=0;
  for(ll i=2;i<=1000000;i++){
    if(n%i==0){
      ll count=0;
      while(n%i==0) {
        n/=i;
        count++;
        //cout <<1<<endl;
      }
      ans += j(count);
    }
  }
  if(n!=1){
    cout << 1 << endl;
    return 0;
  }
  cout << ans<<endl;
  //cout << n_2<<endl;
  //n_2+=10000;
  //cout <<n_2*n_2;
  //cout << j(125);
}
