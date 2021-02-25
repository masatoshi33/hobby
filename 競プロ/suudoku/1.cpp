#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> m(9,vector<char>(9)); //入力するためのchar型のベクトル
vector<vector<int>> s(9,vector<int>(9)); //int型に変換するため
vector<vector<vector<int>>> probable(9, vector<vector<int>>(9, vector<int>(9)));
//0<=x<=8,0<=y<=8
void check(int x, int y){
  ////縦成分が一緒のものを排除
  for(int i=0;i<9;i++){
    int a;
    if(s[i][y]!=0){
      a = s[i][y]-1;
      probable[x][y][a]=1;
    }
  }
  //横
  for(int i=0;i<9;i++){
    int a;
    if(s[x][i]!=0){
      a = s[x][i]-1;
      probable[x][y][a]=1;
    }
  }
  //3*3の四角内
  int x_3 = x/3;
  int y_3 = y/3;
  for(int i=x_3*3;i<x_3*3+3;i++){
    for(int j=y_3*3;j<y_3*3+3;j++){
      int a;
      if(s[i][j]!=0){
        a = s[i][j]-1;
        probable[x][y][a]=1;
      }
    }
  }
  int ans=0;
  bool judge=true;
  for(int i=0;i<9;i++){
    if(probable[x][y][i]==0&&judge){
      ans = i+1;
      judge=false;
    }else if(probable[x][y][i]==0){
      ans = 0;
      break;
    }
  }
  s[x][y] = ans;
}

int main(){
  //表作成
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
      cin >> m[i][j];
    }
  }
  //int型に変換したもの
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
      int x = m[i][j] - '0'; //'7'-'0' = 7
      s[i][j] = x;
    }
  }
  //確認
  /*for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
      cout << s[i][j];
    }
    cout << endl;
  }*/
  int count=100;
  while(count>0){
    count=0;
    for(int i=0;i<9;i++){
      for(int j=0;j<9;j++){
        if(s[i][j]!=0) continue;
        check(i,j);
        if(s[i][j]==0) count += 1;
      }
    }
  }
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
      cout << s[i][j];
    }
    cout << endl;
  }
}
