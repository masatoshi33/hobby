#include <bits/stdc++.h>
#include <queue>
using namespace std;

int main(){
  int n, q;
  cin >> n >> q;
  vector<vector<char>> f(n,vector<char>(n)); //フォロワーかを表す二次元配列
  vector<vector<int>> s_f(n,vector<int>(n)); //フォローするひとのフォローが1、それ以外0
  for(int i=0;i<q;i++){
    int x, y, z;
    cin >> x;
    cin >> y;
    y-=1;
    if(x==1){
      cin >> z;
      z-=1;
      f[y][z]='Y';
    }else if(x==2){
      for(int j=0;j<n;j++){
        if(f[j][y]=='Y'){
          f[y][j] = 'Y';
        }
      }
    }else{
      for(int j=0;j<n;j++){
        if(f[y][j]=='Y'){
          for(int k=0;k<n;k++){
            if(f[j][k]=='Y'){
              s_f[y][k]=1;
            }
          }
        }
      }
      for(int j=0;j<n;j++){
        if(j!=y&&s_f[y][j]==1) f[y][j]='Y';
      }
    }
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(f[i][j]!='Y') f[i][j] = 'N';
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout << f[i][j];
    }
    cout << endl;
  }
}
