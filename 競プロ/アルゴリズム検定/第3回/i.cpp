#include <bits/stdc++.h>
#include <math.h>
#include <vector>
#include <queue>
#include <iomanip>
#include <string>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
typedef long long ll;
const ll INF = 101010101000;

int main(){
  int n, q;
  cin >> n >> q;
  int r_count=0;
  map<int,int> gyou;
  map<int,int> retsu;
  rep(i,n){
    gyou[i]=i;
    retsu[i]=i;
  }
  rep(i,q){
    int x,y,z;
    cin >> x;
    if(x==3){
      r_count++;
    }else if(x==4){
      cin >> y >> z;
      y--;z--;
      int s=gyou[y],t=retsu[z];
      if(r_count%2==0){
        cout << n*s+t << endl;
      }else{
        cout << n*t+s << endl;
      }
    }else if(x==2){
      cin >> y >> z;
      y--;z--;
      if(r_count%2==0){
        swap(retsu[y],retsu[z]);
        /*int n_retsu=retsu[y];
        retsu[y] = retsu[z];
        retsu[z] = n_retsu;*/
      }else{
        swap(gyou[y],gyou[z]);
        /*int n_gyou=gyou[y];
        gyou[y] = gyou[z];
        gyou[z] = n_gyou;*/
      }
    }else{
      cin >> y >> z;
      y--;z--;
      if(r_count%2==1){
        swap(retsu[y],retsu[z]);
        /*int n_retsu=retsu[y];
        retsu[y] = retsu[z];
        retsu[z] = n_retsu;*/
      }else{
        swap(gyou[y],gyou[z]);
        /*int n_gyou=gyou[y];
        gyou[y] = gyou[z];
        gyou[z] = n_gyou;*/
      }
    }
    rep(i,n){
      rep(j,n){
        int s=gyou[i],t=retsu[j];
        cout << n*s+t;
      }
      cout << endl;
    }
  }
}
