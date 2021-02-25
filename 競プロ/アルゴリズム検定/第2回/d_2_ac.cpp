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
  vector<string> ans_2,ans_3,ans_4,ans_5;
  vector<char> ans_1;
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
    int l_ans = ans_3.size();
    int judge=0;
    rep(j,l_ans){
      if(s_3==ans_3[j]) judge=1;
    }
    if(judge==0) ans_3.push_back(s_3);
  }
  rep(i,l-2){
    string s_3;
    s_3 += s[i];
    s_3 += ".";
    s_3 += s[i+2];
    int l_ans = ans_3.size();
    int judge=0;
    rep(j,l_ans){
      if(s_3==ans_3[j]) judge=1;
    }
    if(judge==0) ans_3.push_back(s_3);
  }
  rep(i,l-2){
    string s_3;
    s_3 += s[i];
    s_3 +=s[i+1];
    s_3 += ".";
    int l_ans = ans_3.size();
    int judge=0;
    rep(j,l_ans){
      if(s_3==ans_3[j]) judge=1;
    }
    if(judge==0) ans_3.push_back(s_3);
  }
  rep(i,l-2){
    string s_3;
    s_3 += ".";
    s_3 += s[i+1];
    s_3 += s[i+2];
    int l_ans = ans_3.size();
    int judge=0;
    rep(j,l_ans){
      if(s_3==ans_3[j]) judge=1;
    }
    if(judge==0) ans_3.push_back(s_3);
  }
  rep(i,l-2){
    string s_3;
    s_3 += ".";
    s_3 += ".";
    s_3 += s[i+2];
    int l_ans = ans_3.size();
    int judge=0;
    rep(j,l_ans){
      if(s_3==ans_3[j]) judge=1;
    }
    if(judge==0) ans_3.push_back(s_3);
  }
  rep(i,l-2){
    string s_3;
    s_3 += ".";
    s_3 += s[i+1];
    s_3 += ".";
    int l_ans = ans_3.size();
    int judge=0;
    rep(j,l_ans){
      if(s_3==ans_3[j]) judge=1;
    }
    if(judge==0) ans_3.push_back(s_3);
  }
  rep(i,l-2){
    string s_3;
    s_3 += s[i];
    s_3 += ".";
    s_3 += ".";
    int l_ans = ans_3.size();
    int judge=0;
    rep(j,l_ans){
      if(s_3==ans_3[j]) judge=1;
    }
    if(judge==0) ans_3.push_back(s_3);
  }
  rep(i,l-1){
    string s_2;
    s_2 += s[i];
    s_2 += s[i+1];
    int l_ans = ans_2.size();
    int judge=0;
    rep(j,l_ans){
      if(s_2==ans_2[j]) judge=1;
    }
    if(judge==0) ans_2.push_back(s_2);
  }
  rep(i,l-1){
    string s_2;
    s_2 += '.';
    s_2 += s[i+1];
    int l_ans = ans_2.size();
    int judge=0;
    rep(j,l_ans){
      if(s_2==ans_2[j]) judge=1;
    }
    if(judge==0) ans_2.push_back(s_2);
  }
  rep(i,l-1){
    string s_2;
    s_2 += s[i];
    s_2 += '.';
    int l_ans = ans_2.size();
    int judge=0;
    rep(j,l_ans){
      if(s_2==ans_2[j]) judge=1;
    }
    if(judge==0) ans_2.push_back(s_2);
  }
  rep(i,l){
    char s_1 = s[i];
    int l_ans = ans_1.size();
    int judge=0;
    rep(j,l_ans){
      if(s_1==ans_1[j]) judge=1;
    }
    if(judge==0) ans_1.push_back(s_1);
  }
  int ans;
  ans += ans_3.size()+ans_2.size()+ans_1.size();
  ans += 3;
  cout << ans << endl;
}
