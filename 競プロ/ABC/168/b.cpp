#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
  int k;
  string s;
  cin >> k >> s;
  int l = s.size();
  if(l<=k){
    cout << s;
    return 0;
  }
  for(int i=0;i<k;i++) cout << s[i];
  cout << "...";
}
