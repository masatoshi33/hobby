#include <bits/stdc++.h>
#include <math.h>
#include <vector>
#include <queue>
#include <iomanip>
#include <string>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep_1 (i,j,n) for(int i=j;i<n;i++)
typedef long long ll;
typedef long l;
const ll l_INF = 101010101000;
const int INF = 1010101010;
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;

int k(int x){
  int ans=1;
  rep(i,x) ans*=(i+1);
  return ans;
}
int main(){
  int n;
  cin >> n;
  vector<int> p(n);
  vector<int> q(n);
  int sum_p=0,sum_q=0;
  vector<bool> nokori_p(n),nokori_q(n);
  rep(i,n){
    nokori_p[i]=false;
    nokori_q[i]=false;
  }
  rep(i,n) cin >> p[i];
  rep(i,n) cin >> q[i];
  int count;
  rep(i,n){
    count=0;
    rep(j,n){
      if(nokori_p[j]) continue;
      if(p[i]==j+1){
        nokori_p[j]=true;
        sum_p+=k(n-i-1)*count;
        break;
      }
      count++;
    }
  }
  rep(i,n){
    count=0;
    rep(j,n){
      if(nokori_q[j]) continue;
      if(q[i]==j+1){
        nokori_q[j]=true;
        sum_q+=k(n-i-1)*count;
        break;
      }
      count++;
    }
  }
  //cout << sum_p << endl;
  //cout << sum_q << endl;
  cout << abs(sum_q-sum_p) << endl;
}
