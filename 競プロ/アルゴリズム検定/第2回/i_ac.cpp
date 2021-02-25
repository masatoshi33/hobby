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
  int n;
  cin >> n;
  ll n_2 = pow(2,n);
  vector<pair<int,int>> victory(n_2*2-1);
  rep(i,n_2){
    int x;
    cin >> x;
    victory[i].first = x;
    victory[i].second = i+1;
  }
  rep(i,n_2-1){
    if(victory[i*2].first<victory[i*2+1].first){
      victory[n_2+i].first=victory[i*2+1].first;
      victory[n_2+i].second=victory[i*2+1].second;
    }else{
      victory[n_2+i].first=victory[i*2].first;
      victory[n_2+i].second=victory[i*2].second;
    }
  }
  vector<int> ans(n_2);
  rep(i,n_2) ans[i] = -1;
  for(int i=1;i<n_2;i++){
    int x = victory[n_2*2-2-i].second-1;
    int a;
    rep(j,n){
      if(((i+1)>>(j+1))==1) a = j;
    }
    if(ans[x]==-1) ans[x] = n-a;
  }
  rep(i,n_2){
    if(ans[i]==n) n-=1;
    cout << ans[i] << endl;
  }
}
