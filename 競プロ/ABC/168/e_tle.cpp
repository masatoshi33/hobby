#include <bits/stdc++.h>
#include <iostream>
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const ll M = 1000000007;
const ll INF = 10000000000001;

ll pow_mod(ll x, ll n){ //x^n(mod M)
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % M;
        x = x*x % M;
        n = n >> 1;
    }
    return ans;
}
int main(){
  int n;
  cin >> n;
  vector<double> a(n),b(n);
  for(int i=0;i<n;i++) cin >> a[i] >> b[i];
  vector<double> c(n);
  for(int i=0;i<n;i++){
    if(b[i]==0) c[i] = INF;
    else c[i] = a[i] / b[i];
  }
  int count = 0;
  ll ans = 0;
  vector<int> kirai(n);
  for(int i=0;i<n;i++){
    count = 0;
    if(a[i]==0&&b[i]==0){
      count=n-i-1;
    }else{
      for(int j=i+1;j<n;j++){
        if(c[i]*c[j]==-1) count++;
      }
    }
    kirai[i] = count;
  }
  for(int i=0;i<n;i++){
    ans += pow_mod(2,n-1-i-kirai[i]);
  }
  ans %= M;
  cout << ans << endl;
}
