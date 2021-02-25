#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
  int n, q;
  ll sum=0;
  cin >> n;
  vector<ll> c(n);
  rep(i,n) cin >> c[i];
  cin >> q;
  rep(i,q){
    int x;
    ll y, z;
    cin >> x >> y;
    if(x==1){
      cin >> z;
      y -= 1;
      if(c[y]>=z){
        c[y] -= z;
        sum += z;
      }
    }else if(x==2){
      bool ok=true;
      for(int j=0;j<n;j+=2){
        if(c[j]<y){
          ok = false;
          break;
        }
      }
      if(ok){
        for(int j=0;j<n;j+=2){
          c[j] -= y;
          sum += y;
        }
      }
    }else{
      bool ok=true;
      //cout << y << endl;
      rep(j,n){
        if(c[j]<y){
          ok = false;
          break;
        }
      }
      if(ok){
        rep(j,n){
          c[j] -= y;
          sum += y;
        }
      }
    }
  }
  //rep(i,n) cout << c[i] << endl;
  cout << sum << endl;
}
