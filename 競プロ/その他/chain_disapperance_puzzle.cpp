#include <bits/stdc++.h>
#include <math.h>
#include <vector>
#include <queue>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep_1 (i,j,n) for(int i=j;i<n;i++)
typedef long long ll;
typedef long l;
const ll l_INF = 1010101010101010;
const int INF = 1010101010;
const int dx[] = {-1,0,1,0,-1,-1,1,1};
const int dy[] = {0,-1,0,1,1,-1,1,-1};

int main(){
  while(true){
    int h; cin>>h;
    int ans=0;
    if(h==0) return 0;
    vector<vector<int>> s(h+1,vector<int>(5));
    rep(i,h)rep(j,5) cin>>s[h-1-i][j];
    bool judge=true;
    while(judge){
      judge=false;
      rep(i,h){
        int cnt=0;
        vector<int> x;
        rep(j,4){
          if(s[i][j]==s[i][j+1]&&s[i][j]!=0){
            cnt++;
            //cout<<cnt<<endl;
            x.push_back(j);
          }else{
            if(cnt>=2) break;
            cnt=0;
          }
        }
        if(cnt>=2){
          ans+=(cnt+1)*s[i][x[0]];
          cout<<s[i][x[0]]<<" ";
          for(auto y:x) s[i][y]=0;
          int l=x.size();
          cout<<ans<<" ";
          rep(j,l) x.pop_back();
        }
      }
      rep(i,h-1)rep(j,5){
        if(s[h-i-2][j]==0&&s[h-i-1][j]!=0){
          s[h-i-2][j]=s[h-i-1][j];
          s[h-i-1][j]=0;
          judge=true;
        }
      }
    }
    cout<<ans<<endl;
  }
}
