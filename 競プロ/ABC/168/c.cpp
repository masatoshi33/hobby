#include <bits/stdc++.h>
#include <iomanip>
#include <math.h>
#include <iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
const double PI=3.14159265358979323846;

int main(){
  double a,b,h,m;
  cin >> a >> b>> h >> m;
  double a_2=a*a,b_2=b*b;
  double a_b = 2*a*b;
  double theta = (60*h-11*m)*PI/360;
  double cos_t = cos(theta);
  double ans = a_2+b_2-a_b*cos_t;
  ans = sqrt(ans);
  cout << setprecision(20);
  cout << ans << endl;
}
