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
const string check = "AGTC";

int main(){
  string s;
  cin>>s;
  int ans=0;
  int l=s.size();
  rep(i,l){
    for(int j=i;j<l;j++){
      bool m_judge = true;
      for(int k=i;k<=j;k++){
        bool judge = false;
        rep(x,4){
          if(check[x]==s[k]) judge=true;
        }
        if(!judge) m_judge=false;
      }
      if(m_judge) ans = max(ans,j-i+1);
    }
  }
  cout<<ans;
}
