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

int main(){
  string s;
  cin >> s;
  int l = s.length();
  int a=0,b=0,c=0;
  rep(i,l){
    if(s[i]=='a') a++;
    else if(s[i]=='b') b++;
    else c++;
  }
  char ans = 'a';
  if(a<b) ans = 'b';
  if(a<c&&b<c) ans = 'c';
  cout << ans << endl;
}
