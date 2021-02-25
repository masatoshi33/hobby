#include <bits/stdc++.h>
#include <math.h>
#include <vector>
#include <queue>
#include <iomanip>
#include <string>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
const ll INF = 101010101000;
const string large = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string small = "abcdefghijklmnopqrstuvwxyz";
int main(){
  string s,t;
  cin >> s >> t;
  if(s==t){
    cout << "same";
    return 0;
  }
  string s_1, t_1;
  rep(i,3){
    rep(j,26){
      if(large[j]==s[i]||small[j]==s[i]) s_1+=small[j];
    }
  }
  rep(i,3){
    rep(j,26){
      if(large[j]==t[i]||small[j]==t[i]) t_1+=small[j];
    }
  }
  if(s_1==t_1) cout << "case-insensitive";
  else cout << "different";
}
