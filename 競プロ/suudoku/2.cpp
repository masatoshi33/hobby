#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> m(9,vector<char>(9)); //入力するためのchar型のベクトル
vector<vector<int>> s(9,vector<int>(9)); //int型に変換するため
vector<vector<vector<int>>> probable(9, vector<vector<int>>(9, vector<int>(9)));
//0<=x<=8,0<=y<=8
void check(int x, int y){
  for(int i=0;i<9;i++){
    probable[x][y][i]=1;
  }
  //縦成分が一緒のものを排除
  int a = s[x][y]-1;
  for(int i=0;i<9;i++){
    if(s[i][y]==0){
      probable[i][y][a]=1;
    }
  }
  //横
  for(int i=0;i<9;i++){
    if(s[x][i]==0){
      probable[x][i][a]=1;
    }
  }
  //3*3の四角内
  int x_3 = x/3;
  int y_3 = y/3;
  for(int i=x_3*3;i<x_3*3+3;i++){
    for(int j=y_3*3;j<y_3*3+3;j++){
      if(s[i][j]==0){
        probable[i][j][a]=1;
      }
    }
  }
}

int fill_1(int x,int n){
  int ans;
  bool judge=true;
  for(int i=0;i<9;i++){
    if(probable[x][i][n]==0&&judge){
      ans = i;
      judge=false;
    }else if(probable[x][i][n]==0){
    return 0;
    }
  }
  if(!judge){
    s[x][ans] = n+1;
    check(x,ans);
  }
  return 0;
}

int fill_2(int y,int n){
  int ans;
  bool judge=true;
  for(int i=0;i<9;i++){
    if(probable[i][y][n]==0&&judge){
      ans = i;
      judge=false;
    }else if(probable[i][y][n]==0){
    return 0;
    }
  }
  if(!judge){
    s[ans][y] = n+1;
    check(ans,y);
  }
  return 0;
}

int fill_3(int x, int n){
  int x_0,y_0;
  x_0 = x/3;
  y_0 = x%3;
  int ans_1,ans_2;
  bool judge=true;
  for(int i=x_0*3;i<x_0*3+3;i++){
    for(int j=y_0*3;j<y_0*3+3;j++){
      if(probable[i][j][n]==0&&judge){
        ans_1 = i;
        ans_2 = j;
        judge=false;
      }else if(probable[i][j][n]==0){
      return 0;
      }
    }
  }
  if(!judge){
    s[ans_1][ans_2] = n+1;
    check(ans_1,ans_2);
  }
  return 0;
}

int fill(int x, int y){
  int ans=0;
  bool judge=true;
  for(int i=0;i<9;i++){
    if(probable[x][y][i]==0&&judge){
      ans = i+1;
      judge=false;
    }else if(probable[x][y][i]==0){
      return 0;
    }
  }
  if(!judge){
    s[x][y] = ans;
    check[x][y];
  }
  return 0;
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
  //条件確認
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
      if(s[i][j]!=0){
        check(i,j);
      }
    }
  }
  //埋める
  int count=100;
  //while(count>0){
  for(int k=0;k<10000;k++){
    count = 0;
    for(int i=0;i<9;i++){
      for(int j=0;j<9;j++){
        fill_1(i,j);
        fill_2(i,j);
        fill_3(i,j);
        fill(i,j);
      }
    }
  }
  //答え出力
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
      cout << s[i][j];
    }
    cout << endl;
  }
}

/*test_case
300408600
040390050
001050000
030000008
010000005
620000013
900820006
002035070
000700100
*/
