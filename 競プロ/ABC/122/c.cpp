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
  int n,q;
  cin>>n>>q;
  string s; cin>>s;
  int count[n];
  count[0]=0;
  rep(i,n-1){
    if(s[i]=='A'&&s[i+1]=='C') count[i+1]=count[i]+1;
    else count[i+1]=count[i];
  }
  rep(i,q){
    int l,r;
    cin>>l>>r;
    l--;r--;
    cout << count[r]-count[l] <<endl;
  }
  rep(i,n){
    //cout<<count[i]<<endl;
  }
}
