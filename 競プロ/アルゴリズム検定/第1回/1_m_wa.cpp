#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
vector<int> e(5),f(5);
double sum_a(){
  double x=0;
  for(int i=0;i<5;i++){
    x+=e[i];
  }
  return x;
}
double sum_b(){
  double y=0;
  for(int i=0;i<5;i++){
    y+=f[i];
  }
  return y;
}
double p(){
  double x=0,y=0;
  for(int i=0;i<5;i++){
    x+=e[i];
    y+=f[i];
  }
  return y/x;
}
int main(){
  int n,m;
  cin >> n >> m;
  vector<int> a(n),b(n),c(m),d(m);
  for(int i=0;i<n;i++) cin >> a[i] >> b[i];
  for(int i=0;i<m;i++) cin >> c[i] >> d[i];
  for(int i=0;i<5;i++){
    e[i]=a[i];
    f[i]=b[i];
  }
  //cout << p() << endl;
  for(int i=5;i<n;i++){
      double ans = p();
      int ans_0 = -1;
      for(int j=0;j<5;j++){
        double y = sum_b()-f[j]+b[i];
        double z = sum_a()-e[j]+a[i];
        y = y/z;
        if(y>ans){
          ans = y;
          ans_0 = j;
        }
      }
      if(ans_0!=-1){
        e[ans_0]=a[i];
      	f[ans_0]=b[i];
        //cout << e[ans_0] << ' ' << f[ans_0] << endl;
      }
  }
  //for(int i=0;i<5;i++) cout << e[i] << ' ' << f[i] << endl;
  int ans_1=-1,ans_2=-1;
  double ans_3 = p();
  for(int i=0;i<m;i++){
      for(int j=0;j<5;j++){
        double y = sum_b()-f[j]+d[i];
        double z = sum_a()-e[j]+c[i];
        if(y>ans_3*z){
          ans_3 = y/z;
          ans_1 = j;
          ans_2 = i;
        }
      }
  }
  if(ans_1>-1&&ans_2>-1){
    e[ans_1] = c[ans_2];
    f[ans_1] = d[ans_2];
  }
  //for(int i=0;i<5;i++) cout << e[i] << ' ' << f[i] << endl;
  cout << setprecision(25);
  cout << p() << endl;
}
