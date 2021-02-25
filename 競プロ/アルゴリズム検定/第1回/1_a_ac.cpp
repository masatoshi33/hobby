#include <bits/stdc++.h>
using namespace std;

bool check(char x){
  for(int i=0;i<10;i++){
    if(x-'0'==i) return true;
  }
  return false;
}

int main(){
  vector<char> s(3);
  for(int i=0;i<3;i++){
    cin >> s[i];
    if(!check(s[i])){
      cout << "error" << endl;
      return 0;
    }
  }
  int ans = (s[2]-'0')+(s[1]-'0')*10+(s[0]-'0')*100;
  cout << ans*2 << endl;
}
