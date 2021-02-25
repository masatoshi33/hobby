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
using vl = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int,int>;

int main(){
  int n; cin>>n;
  vl a(n);
  rep(i,n) cin>>a[i];
  ll count=0;
  ll left=0,right=1;
  ll sum=0;
  while(left<n){
    while(right<n&&a[right]>a[right-1]){
      right++;
    }
    sum+=(right-left+1)*(right-left)/2;
    left=right;
    right=left+1;
  }
  cout<<sum;
}
