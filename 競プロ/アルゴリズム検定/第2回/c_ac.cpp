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
  char t[n+2][2*n+2];
  for(int i=1;i<n+1;i++){
    for(int j=1;j<2*n;j++){
      cin >> t[i][j];
    }
  }
  for(int i=n-1;i>0;i--){
    for(int j=1;j<2*n;j++){
      if(t[i+1][j-1]=='X'||t[i+1][j]=='X'||t[i+1][j+1]=='X'){
        if(t[i][j]=='#') t[i][j] = 'X';
      }
    }
  }
  for(int i=1;i<n+1;i++){
    for(int j=1;j<2*n;j++){
      cout << t[i][j];
    }
    cout << endl;
  }
}
