#include <bits/stdc++.h>
#include <math.h>
#include <vector>
#include <queue>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep_1 (i,j,n) for(int i=j;i<n;i++)
typedef long long ll;
typedef long l;
const ll l_INF = 1010101010101010;
const int INF = 1010101010;
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

int main(){
  ll x,k,d; cin>>x>>k>>d;
  x=abs(x);
  ll y=x%d;
  ll z=x/d;
  ll ans;
  if(x/d>=k){
    ans=x-k*d;
    cout<<ans<<endl;
    return 0;
  }
  if((abs(k-z))%2==0) cout<<y<<endl;
  else cout<<d-y<<endl;
}
