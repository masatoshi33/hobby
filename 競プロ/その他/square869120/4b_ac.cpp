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
  int n,k; cin>>n>>k;
  vll a(n); rep(i,n) cin>>a[i];
  ll ans=l_INF;
  rep(i,1<<(n-1)){
    int cnt=0;
    set<int> select;
    vll b(n);
    rep(j,n-1){
      if((i>>j)&1){
        cnt++;
        select.insert(j);
      }
    }
    ll sum=0;
    if(cnt==k-1){
      b[0]=a[0];
      rep(j,n-1){
        if(select.count(j)){
          if(a[j+1]>b[j]) b[j+1]=a[j+1];
          else b[j+1]=b[j]+1;
        }else{
          if(a[j+1]>=b[j]) b[j+1]=a[j+1];
          else b[j+1]=b[j];
        }
      }
      for(auto x:select){
        sum+=b[x+1]-a[x+1];
        //cout<<b[x+1]<<" ";
      }
      ans=min(ans,sum);
      //cout<<ans<<" ";
    }
  }
  //cout<<endl;
  cout<<ans<<endl;
}
