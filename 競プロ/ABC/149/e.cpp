#include <bits/stdc++.h>
#include <math.h>
#include <vector>
#include <queue>
#include <iomanip>
#include <string>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep_1 (i,j,n) for(int i=j;i<n;i++)
typedef long long ll;
typedef long l;
const ll l_INF = 101010101000;
const int INF = 1010101010;
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;
//k以上のものの数を数える関数
ll count(ll k, vector<ll> &a){
  ll n=a.size();
  ll ans=0;
  rep(i,n){
    ll res=k-a[i];
    //aのなかでres以上の値が出る最初の要素の順番を得る。
    ans+=a.end()-lower_bound(a.begin(),a.end(),res);
  }
  return ans;
}
int main(){
  ll n,m;
  cin>>n>>m;
  vector<ll> a(n);
  rep(i,n) cin>>a[i];
  sort(a.begin(),a.end());
  ll l=0; ll r=200005;
  while(l+1<r){
    ll now=(l+r)/2;
    if(count(now,a)>=m) l=now;
    else r=now;
  }
  //l:l以上の幸福度の握手のみ含まれる
  ll sum=0;
  vector<ll> b(n+5);
  rep(i,n) b[0]+=a[i];
  rep(i,n-1) b[i+1]=b[i]-a[i];
  ll r_count=0;
  rep(i,n){
    ll res=l-a[i];
    //
    ll key=lower_bound(a.begin(),a.end(),res)-a.begin();
    sum+=b[key]; //右手の分としてkey以降のようそをたす
    sum+=(n-key)*a[i]; //左手の分
    r_count+=n-key; //握手はn-key回完了
  }
  sum-=(r_count-m)*l; //ぴったり値がlになるものをいくつか余分に足しちゃうので引く
  cout<<sum<<endl;
}
