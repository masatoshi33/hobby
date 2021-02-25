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
  int n; cin>>n;
  string s; cin>>s;
  set<int> ans;
  rep(i,n){
    for(int j=i+1;j<n;j++){
      for(int k=j+1;k<n;k++){
        int num=100*(s[i]-'0')+10*(s[j]-'0')+(s[k]-'0');
        if(!ans.count(num)) ans.insert(num);
      }
    }
  }
  for(auto x :ans){
    cout<<x<<" ";
  }
  cout<<endl;
  cout<<ans.size();
}
