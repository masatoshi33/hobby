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
  string s; cin>>s;
  int len=s.size();
  vi ans(len);
  int l=0,r=0;
  int c=0;
  while(c<len+1){
    if(l==0&&s[c]=='R') r++;
    if(s[c]=='L') l++;
    if(l!=0&&s[c]=='R'){
      if(abs(r-l)%2==1){
        if(max(r,l)%2==0){
          ans[c-l]=r;
          ans[c-l-1]=l;
        }else{
          ans[c-l]=l;
          ans[c-l-1]=r;
        }
      }else{
        ans[c-l]=(l+r)/2;
        ans[c-l-1]=(l+r)/2;
      }
      r=1;l=0;
    }
    if(c==len){
      if((r-l)%2==1){
        if(max(r,l)%2==0){
          ans[c-l]=r;
          ans[c-l-1]=l;
        }else{
          ans[c-l]=l;
          ans[c-l-1]=r;
        }
      }else{
        ans[c-l]=(l+r)/2;
        ans[c-l-1]=(l+r)/2;
      }
      r=1;l=0;
    }
    c++;
  }
  rep(i,len) cout<<ans[i]<<" ";

}
