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
  char s_0,s_1,t_0,t_1;
  cin >> s_0 >> s_1 >> t_0 >> t_1;
  int x, y;
  if(s_0=='B'&&t_0=='B'){
    x = s_1 - '0';
    y = t_1 - '0';
    cout << abs(x-y) << endl;
  }else if(s_0!='B'&&t_0=='B'){
    x = s_0 - '0';
    y = t_1 - '0';
    cout << abs(x+y)-1 << endl;
  }else if(s_0=='B'&&t_0!='B'){
    x = s_1 - '0';
    y = t_0 - '0';
    cout << abs(x+y)-1 << endl;
  }else{
    x = s_0 - '0';
    y = t_0 - '0';
    cout << abs(x-y) << endl;
  }
}
