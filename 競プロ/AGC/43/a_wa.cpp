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
  vector<char> a(n);
  rep(i,n) cin >> a[i];
  vector<int> a_1(n-1),a_2(n-2);
  rep(i,n-1) a_1[i] = a[i+1]-a[i];
  rep(i,n-2) a_2[i] = a_1[i+1]-a_1[i];

}
