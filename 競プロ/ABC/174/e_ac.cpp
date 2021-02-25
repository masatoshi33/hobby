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
  vector<ll> a(n); rep(i,n) cin>>a[i];
  sort(a.begin(),a.end#include <bits/stdc++.h>
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
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  ll ans=500001;
  ll left=1000000000, right=0;
  while(right!=ans&&left!=ans){
    ll cnt=0;
    rep(i,n){
      cnt+=(a[i]/ans);
    }
    if(cnt<=k){
      left=ans;
      ans=(left+right+1)/2;
    }else{
      right=ans;
      ans=(left+right+1)/2;
    }
  }
  if(k!=0)cout<<ans<<endl;
  else cout<<a[0]<<endl;
}

  reverse(a.begin(),a.end());
  ll ans=500000;
  ll right=-1, left=1000000000;
  while(right!=ans&&left!=ans){
    ll cnt=0;
    ans=(right+left)/2;
    rep(i,n){
      cnt+=(a[i]/ans);
      if(a[i]%ans==0) cnt--;
    }
    if(cnt<=k){
      left=ans;
    }else{
      right=ans;
    }
  }
  //ans=(right+left)/2;
  /*if(ans==1000000001){
    cout<<1000000000<<endl;
    return 0;
  }*/
  if(k!=0)cout<<ans<<endl;
  else cout<<a[0]<<endl;
}
