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

int main(){
  string t;
  cin >> t;
  int l = t.length();
  vector<char> ans(l);
  rep(i,l){
    /*if(t[i]=='?'){
      if(i!=l-1&&i!=0){
        if(t[i+1]=='D') ans[i]='P';
        else if(t[i+1]=='D'&&ans[i-1]=='D') ans[i]='P';
        else if(t[i+1]=='?'&&ans[i-1]=='D') ans[i]='P';
        else ans[i] = 'D';
      }else if(i==l-1){
        ans[i] = 'D';
      }else{
        if(t[i+1]=='D'||t[i+1]=='?') ans[i]='P';
        else ans[i] = 'D';
      }
    }*/
    if(t[i]=='?'){
      ans[i]='D';
    }
    else{
      ans[i]=t[i];
    }
  }
  rep(i,l) cout << ans[i];
}
