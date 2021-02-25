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
  long min_o=1010101010, min=1010101010;
  long d_o = 0, d = 0;
  rep(i,n){
    if(min>c[i]) min = c[i];
  }
  for(int i=0;i<n;i+=2){
    if(min_o>c[i]) min_o = c[i];
  }
  //cout << min << endl << min_o << endl;
  rep(i,q){
    int x;
    ll y, z;
    cin >> x >> y;
    if(x==1){
      cin >> z;
      y -= 1;
      if(y%2==0&&c[y]-d_o>=z){
        c[y] -= z;
        sum += z;
        if(min_o>c[y]-d_o){
          min_o = c[y]-d_o;
        }
      }else if(y%2==1&&c[y]-d>=z){
        c[y] -= z;
        sum += z;
        if(min>c[y]-d){
          min = c[y]-d;
        }
      }
    }else if(x==2){
      if(min_o>=y){
        sum += ((n+1)/2) * y;
        min_o -= y;
        d_o += y;
      }
    }else{
      if(min>=y&&min_o>=y){
        sum += n * y;
        min -= y;
        min_o -= y;
        d += y;
        d_o += y;
      }
    }
  }
  //cout << d << " " << d_o << endl;
  //cout << min << " " << min_o << endl;
  //rep(i,n) cout << c[i] << " ";
  //cout << endl;
  cout << sum << endl;
}
