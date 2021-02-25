#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  vector<bool> ok(n);
  int ans=-1;
  for(int i=0;i<n;i++){
    int x = a[i]-1;
    if(ok[x]==0) ok[x] = true;
    else if(ok[x]) ans = x;
  }
  if(ans>=0) cout << ans+1 << " ";
  for(int i=0;i<n;i++){
    if(ok[i]) continue;
    cout << i+1;
    return 0;
  }
  cout << "Correct" << endl;
}
