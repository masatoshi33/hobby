#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

const ll M = 1000000007;
const ll max_n = 210100;//n<=2*10~5より

vector<ll> fac(max_n); //n!(mod M)
vector<ll> ifac(max_n); //k!^{M-2} (mod M)

ll pow_mod(ll x, ll n){ //x^n(mod M)
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % M;
        x = x*x % M;
        n = n >> 1;
    }
    return ans;
}

ll comb_mod(ll a, ll b){ //aCbをmod計算
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0)return 0;
    ll ans = ifac[a-b]* ifac[b] % M;
    return ans * fac[a] % M;
}

int main(){
  ll n,k;
  cin >> n >> k;
  //先にfac[i]とifac[i]を全て計算しておく
  fac[0] = 1;//0!のmod
  ifac[0] = 1;//0!(=1)の逆元
  for(ll i = 0; i<max_n; i++){
      fac[i+1] = fac[i]*(i+1) % M; // n!(mod M)
      ifac[i+1] = ifac[i]*pow_mod(i+1, M-2) % M; // k!^{M-2} (mod M)
  }
  if(k>n-1) k = n-1;
  ll ans = 0;
  for(ll i=0;i<=k;i++){
    ans += comb_mod(n,i) * comb_mod((n-i-1)+i, i);
    ans %= M;
  }
  cout << ans << endl;
}
