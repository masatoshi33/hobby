#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
  int n;
  cin >> n;
  n %= 10;
  if(n==2||n==4||n==5||n==7||n==9) cout << "hon" << endl;
  else if(n==0||n==1||n==6||n==8) cout << "pon" << endl;
  else cout << "bon" <<endl;
}
