#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstdio>
using namespace std;
//英大文字の配列
vector<char> cap = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
//英小文字の配列
vector<char> s_cap = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
//大文字かどうか判定
bool judge(char x){
  for(int i=0;i<26;i++){
    if(cap[i]==x){
      return true;
    }
  }
  return false;
}

int main(){
  string s;
  cin >> s;
  vector<string> ans;
  int l = s.size();
  int x = 0,count = 0;
  string s_2;
  while(x<l){
    s_2 += s[x];
    if(count==0&&judge(s[x])){
      count += 1;
    }else if(judge(s[x])){
      count = 0;
      ans.push_back(s_2);
      s_2 = "";
    }
    x+=1;
  }
  int len = ans.size();
  for(int i=0;i<len;i++){
    int length = ans[i].size();
    for(int j=0;j<26;j++){
      if(cap[j]==ans[i][length-1]){
        ans[i][length-1] = s_cap[j];
      }
    }
  }
  sort(ans.begin(), ans.end());
  for(int i=0;i<len;i++){
    int length = ans[i].size();
    for(int j=0;j<26;j++){
      if(s_cap[j]==ans[i][length-1]){
        ans[i][length-1] = cap[j];
      }
    }
  }
  for(int i=0;i<len;i++){
    cout << ans[i];
  }
}
