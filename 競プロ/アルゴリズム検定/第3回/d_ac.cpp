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
  int n;
  cin >> n;
  vector<string> s(5);
  vector<int> num(n+1);
  rep(i,5) cin >> s[i];
  for(int i=1;i<n+1;i++){
    if(s[2][4*i-3]=='#'&&s[2][4*i-2]=='.'&&s[2][4*i-1]=='#'){
      num[i-1] = 0;
      continue;
    }else if(s[2][4*i-3]=='.'&&s[2][4*i-2]=='.'&&s[2][4*i-1]=='#'){
      num[i-1] = 7;
      continue;
    }else if(s[2][4*i-3]=='.'&&s[2][4*i-2]=='#'&&s[2][4*i-1]=='.'){
      num[i-1] = 1;
      continue;
    }else if(s[3][4*i-3]=='#'&&s[3][4*i-2]=='.'&&s[3][4*i-1]=='.'){
      num[i-1] = 2;
      continue;
    }else if(s[4][4*i-3]=='.'&&s[4][4*i-2]=='.'&&s[4][4*i-1]=='#'){
      num[i-1] = 4;
      continue;
    }else if(s[1][4*i-3]=='#'&&s[1][4*i-2]=='.'&&s[1][4*i-1]=='#'&&s[3][4*i-3]=='#'&&s[3][4*i-2]=='.'&&s[3][4*i-1]=='#'){
      num[i-1] = 8;
      continue;
    }else if(s[3][4*i-3]=='#'&&s[3][4*i-2]=='.'&&s[3][4*i-1]=='#'){
      num[i-1] = 6;
      continue;
    }else if(s[1][4*i-3]=='#'&&s[1][4*i-2]=='.'&&s[1][4*i-1]=='#'){
      num[i-1] = 9;
      continue;
    }else if(s[1][4*i-3]=='.'&&s[1][4*i-2]=='.'&&s[1][4*i-1]=='#'){
      num[i-1] = 3;
      continue;
    }else if(s[1][4*i-3]=='#'&&s[1][4*i-2]=='.'&&s[1][4*i-1]=='.'){
      num[i-1] = 5;
      continue;
    }
  }
  for(int i=0;i<n;i++) cout << num[i];
}
