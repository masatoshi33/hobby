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

int main(){
  int q; cin>>q;
  int s[101010];
  for(int i=3;i<101010;i++){
    s[i]=s[i-1];
    bool judge1=true,judge2=true;
    for(int j=2;j<=sqrt(i);j++){
      if(i%j==0){
        judge1=false;
      }
    }
    for(int j=2;j<=sqrt((i+1)/2);j++){
      if(((i+1)/2)%j==0){
        judge2=false;
      }
    }
    if(judge1&&judge2) s[i]++;
  }
  rep(i,q){
    ll l,r;
    cin>>l>>r;
    cout << s[r]-s[l-1] << endl;
  }
  //チェック
  //rep(i,50) cout <<s[i]<<endl;
}
