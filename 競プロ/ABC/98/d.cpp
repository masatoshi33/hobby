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
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int,int>;

int main(){
  int n; cin>>n;
  vll a(n);
  rep(i,n) cin>>a[i];
  //しゃくとり法
  ll right=0;
  ll sum=0;
  ll ans=0;
  rep(left,n){
    while(right<n&&(sum^a[right])==(sum+a[right])){
      sum+=a[right];
      right++;
    }
    //cout<<right-left<<endl;
    ans+=right-left;
    if(left==right)right++;
    else sum-=a[left];
  }
  cout<<ans<<endl;
}
