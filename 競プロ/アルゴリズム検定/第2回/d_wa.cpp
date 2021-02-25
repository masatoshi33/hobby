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
  vector<string> ans_1,ans_2,ans_3,ans_4,ans_5;
  if(l==1){
    cout << 2 << endl;
    return 0;
  }
  if(l==2){
    if(s[0]==s[1]) cout << 6 << endl;
    else cout << 7 << endl;
    return 0;
  }
  rep(i,l-2){
    string s_3;
    s_3 += s[i];
    s_3 += s[i+1];
    s_3 += s[i+2];
    int l_ans = ans_1.size();
    int judge=0;
    rep(j,l_ans){
      if(s_3==ans_1[j]) judge=1;
    }
    if(judge==0) ans_1.push_back(s_3);
  }
  rep(i,l-2){
    string s_3;
    s_3 += s[i];
    s_3 += ".";
    s_3 += s[i+2];
    int l_ans = ans_2.size();
    int judge=0;
    rep(j,l_ans){
      if(s_3==ans_2[j]) judge=1;
    }
    if(judge==0) ans_2.push_back(s_3);
  }
  rep(i,l-2){
    string s_3;
    s_3 += s[i];
    s_3 +=s[i+1];
    s_3 += ".";
    int l_ans = ans_2.size();
    int judge=0;
    rep(j,l_ans){
      if(s_3==ans_2[j]) judge=1;
    }
    if(judge==0) ans_2.push_back(s_3);
  }
  rep(i,l-2){
    string s_3;
    s_3 += ".";
    s_3 += s[i+1];
    s_3 += s[i+2];
    int l_ans = ans_2.size();
    int judge=0;
    rep(j,l_ans){
      if(s_3==ans_2[j]) judge=1;
    }
    if(judge==0) ans_2.push_back(s_3);
  }
  rep(i,l-2){
    string s_3;
    s_3 += ".";
    s_3 += ".";
    s_3 += s[i+2];
    int l_ans = ans_2.size();
    int judge=0;
    rep(j,l_ans){
      if(s_3==ans_2[j]) judge=1;
    }
    if(judge==0) ans_2.push_back(s_3);
  }
  rep(i,l-2){
    string s_3;
    s_3 += ".";
    s_3 += s[i+1];
    s_3 += ".";
    int l_ans = ans_2.size();
    int judge=0;
    rep(j,l_ans){
      if(s_3==ans_2[j]) judge=1;
    }
    if(judge==0) ans_2.push_back(s_3);
  }
  rep(i,l-2){
    string s_3;
    s_3 += s[i];
    s_3 += ".";
    s_3 += ".";
    int l_ans = ans_2.size();
    int judge=0;
    rep(j,l_ans){
      if(s_3==ans_2[j]) judge=1;
    }
    if(judge==0) ans_2.push_back(s_3);
  }
  rep(i,l-1){
    string s_2;
    s_2 += s[i];
    s_2 += s[i+1];
    int l_ans = ans_3.size();
    int judge=0;
    rep(j,l_ans){
      if(s_2==ans_3[j]) judge=1;
    }
    if(judge==0) ans_3.push_back(s_2);
  }
  for(int i=1;i<l-1;i++){
    string s_1;
    s_1 += s[i];
    int l_ans = ans_4.size();
    int judge=0;
    rep(j,l_ans){
      if(s_1==ans_4[j]) judge=1;
    }
    if(judge==0) ans_4.push_back(s_1);
  }
  int judge=0;
  int l_ans_4 = ans_4.size();
  rep(j,l_ans_4){
    if(s[0]==ans_4[j]) judge=1;
  }
  if(judge==0) ans_5.push_back(s[0]);
  int judge=0;
  rep(j,l_ans_4){
    if(s[l-1]==ans_4[j]) judge=1;
  }
  if(judge==0) ans_5.push_back(s[l-1]);
  int f_ans = 0;
  f_ans += ans_1.size()+ans_2.size()+ans_3.size()+2*ans_4.size();
  f_ans += ans_5;
  f_ans += 3;
  cout << f_ans << endl;
}
