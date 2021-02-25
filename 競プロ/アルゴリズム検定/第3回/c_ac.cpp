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
  int a, r, n;
  cin >> a >> r >> n;
  n--;
  ll sum = a;
  bool judge=false;
  if(r==1){
    cout << a;
    return 0;
  }
  while(sum<=1000000000&&n>0){
    sum *= r;
    n--;
    if(sum>1000000000) judge=true;
  }
  if(judge){
    cout << "large";
  }else{
    cout << sum;
  }
}
