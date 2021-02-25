#include <bits/stdc++.h>
#include <math.h>
#include <vector>
#include <queue>
#include <iomanip>
#include <string>
#include <algorithm>
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
using vl = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int,int>;

int f(string s){
  int l=s.length();
  int ans=0;
  rep(i,l){
    if(s[i]=='1') ans+=pow(2,i);
  }
  return ans;
}
int f_2(int x){
  int ans=1;
  while(x>1){
    x/=2;
    ans++;
  }
  return ans;
}
int main(){
  int n; cin>>n;
  vector<char> x(n);
  rep(i,n) cin>>x[i];
  reverse(x.begin(),x.end());
  rep(i_2,n){
    if(x[n-i_2-1]=='1') x[n-i_2-1]='0';
    else if(x[n-i_2-1]=='0') x[n-i_2-1]='1';
    int count=0;
    rep(i,n){
      if(x[i]=='1') count++;
    }
    int count_c=f_2(count);
    int n_0=(n/count_c)+1;
    vector<vector<char>> y(n_0);
    for(int i=0;i<n;i+=count_c){
      rep(j,count_c){
        if(i+j>n) break;
        y[i].push_back(x[i+j]);
      }
    }
    vector<string> y_2(n_0);
    rep(i,n_0){
      for(auto x_1 : y[i]){
        y_2[i]+=x_1;
      }
    }
    ll n_x=0;
    rep(i,n_0){
      ll a = f(y_2[i])%count;
      ll b = (1<<(i*count_c))%count;
      n_x+=a*b;
      n_x%=count;
    }
    int count_a=1;
    while(n_x>0){
      count_a++;
      int c_nx = __builtin_popcount(n_x);
      n_x%=c_nx;
    }
    cout<<count_a<<endl;
    if(x[n-i_2-1]=='1') x[n-i_2-1]='0';
    else x[n-i_2-1]='1';
  }
}
