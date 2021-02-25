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
const ll l_INF = 101010101000;
const int INF = 1010101010;
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;
ll y[10101010];

ll judge(ll x){
  ll count=0;
  for(int i=1;i<=sqrt(x);i++){
    if(x%i==0)count++;
  }
  return count;
}

bool judge_2(ll x){
  ll y = sqrt(x);
  if(y*y==x)return true;
  else return false;
}

int main(){
  ll n;
  cin>>n;
  ll ans=0;
  for(ll i=1;i<3200;i++){
    ll big=i;
    while(big<10101010){
      if(i<=sqrt(big)) y[big]++;
      big+=i;
    }
  }

  rep(i,n){
    if(judge_2(i+1)){
      ans+=(2*y[i+1]-1)*(i+1);
      //cout<<(2*judge(i+1)-1)*(i+1)<<endl;
    }else{
      //cout <<"false"<<endl;
      ans+=2*y[i+1]*(i+1);
      //cout<<2*judge(i+1)*(i+1)<<endl;
    }
  }
  rep(i,50){
    cout<<y[i+1]<<endl;
  }
  cout << ans;
}
