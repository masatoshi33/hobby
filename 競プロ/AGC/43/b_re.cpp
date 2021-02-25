#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <iomanip>
#include <string>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
const ll INF = 101010101000;

int count_2(int x){
  int ans=0;
  while(x%2==0&&x!=0){
    x /= 2;
    ans++;
  }
  return ans;
}

int main(){
  int n;
  cin >> n;
  vector<char> a(n);
  vector<int> a_1(n-1), a_2(n-2);
  rep(i,n) cin >> a[i];
  int x=0;
  rep(i,n) if(a[i]=='2') x=1;
  rep(i,n-1) a_1[i] = abs(a[i]-a[i+1]);
  rep(i,n-2) a_2[i] = abs(a_1[i]-a_1[i+1]);
  vector<int> comb(n-2);
  comb[0] = 0;
  rep(i,n-3){
    int x = count_2(n-3-i);
    int y= count_2(i+1);
    comb[i+1] = comb[i] + x - y;
  }
  int count = 0;
  rep(i,n-2){
    if(comb[i]==0&&a_2[i]==1) count++;
  }
  if(x==1) cout << count%2 << endl;
  else cout << count%2 *1 << endl;
  //rep(i,n-2) cout << comb[i] << endl;
  //cout << count_2(1);
}
