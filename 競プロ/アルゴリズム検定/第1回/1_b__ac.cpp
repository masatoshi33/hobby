#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int n;
  cin >> n;
  vector<ll> A(n);
  for(int i=0;i<n;i++) cin >> A[i];
  for(int i=0;i<n-1;i++){
    ll x = A[i+1] - A[i];
    if(x==0) cout << "stay" << endl;
    else if(x>0) cout << "up " << x << endl;
    else cout << "down " << -x << endl;
  }
}
