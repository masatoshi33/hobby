#include <bits/stdc++.h>
#include <math.h>
#include <vector>
#include <queue>
#include <iomanip>
#include <string>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
typedef long long ll;
const ll INF = 101010101000;

int main(){
  ll n, q;
  cin >> n >> q;
  bool rot = false;
  map<ll,ll> gyou;map<ll,ll> retsu;
  rep(i,n){
    gyou[i]=i;
    retsu[i]=i;
  }
  rep(i,q){
    int x,y,z;
    cin >> x;
    if(x==3){
      rot ^= 1;
    }else if(x==4){
      cin >> y >> z;
      y--;z--;
      if(rot) swap(y,z);
      int s=gyou[y],t=retsu[z];
      cout << n*s+t << endl;
    }else if(x==2){
      cin >> y >> z;
      y--;z--;
      if(!rot) swap(retsu[y],retsu[z]);
      else swap(gyou[y],gyou[z]);
    }else{
      cin >> y >> z;
      y--;z--;
      if(rot) swap(retsu[y],retsu[z]);
      else swap(gyou[y],gyou[z]);
    }
  }
}
