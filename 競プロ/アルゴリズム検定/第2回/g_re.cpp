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
vector<char> alpha = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

int main(){
  int q;
  cin >> q;
  deque<pair<char,ll>> s;
  /*pair<char,int> po;
  char xo='1';
  int yo=1;
  po = {xo,yo};
  cout << po.first;*/
  vector<ll> deleted(26);
  rep(i,q){
    int type,y;
    char z;
    cin >> type;
    if(type==1){
      cin >> z >> y;
      s.push_back({z,y});
    }else{
      cin >> y;
      if(!s.empty()){
        char a = s.front().first;
        int b = s.front().second;
        s.pop_front();
      }
      while(y>=b||!s.empty()){
        y-=b;
        a = s.front().first;
        b = s.front().second;
        rep(k,26){
          if(a == alpha[k]){
            deleted[k]+=b;
          }
        }
        s.pop_front();
      }
      b-=y;
      if(b>=0) s.push_front({a,b});
      cout << s.front().first << " " << s.front().second << endl;
      rep(k,26){
        if(a == alpha[k]){
          deleted[k]+=y;
        }
      }
      ll ans=0;
      rep(i,26){
        ans += deleted[i]*deleted[i];
        if(deleted[i]>0) cout << i+1 << ' ' << deleted[i] << endl;
      }
      cout << ans << endl;
      rep(i,26) deleted[i]=0;
    }
  }
}
