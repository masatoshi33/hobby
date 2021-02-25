#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <iomanip>
#include <string>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
const ll INF = 101010101000;
ll n, a, b;

int main(){
  ll ans;
  cin >> n >> a >> b;
  if((b-a)%2==0){
    ans = (b-a)/2;
    cout << ans << endl;
    return 0;
  }
  ans = min(n+(1-b-a)/2,(a+b-1)/2);
  cout << ans << endl;
}
