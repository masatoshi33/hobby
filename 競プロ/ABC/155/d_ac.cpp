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

int main(){
  ll n, k;
  cin >> n >> k;
  vector<ll> pos,neg,zero;
  ll pos_num=0,neg_num=0,zero_num=0;
  rep(i,n){
    ll x;
    cin >> x;
    if(x>0){
      pos.push_back(x);
      pos_num++;
    }else if(x==0){
      zero.push_back(x);
      zero_num++;
    }else{
      neg.push_back(x);
      neg_num++;
    }
  }
  ll ans=-1e18;
  sort(pos.begin(),pos.end());
  sort(neg.begin(),neg.end());
  if(k<=pos_num*neg_num){
    ll l = -1e18, r = -1;
    while(l<=r){
      ll mid = (l+r)/2;
      ll delta = 0;
      ll lw_num = 0;
      /*for(ll i=0;i<neg_num;i++){
        for(ll j=0;j>=0;j--){
          if(mid>neg[i]*pos[j]){
            lw_num+=neg_num-j;
            break;
          }
        }
      }*/
      for(delta=0;delta<pos_num;delta++){
        if(mid>neg[0]*pos[pos_num-delta-1]) lw_num++;
        else break;
      }
      for(ll j=1;j<neg_num;j++){
        for(delta;delta>0;delta--){
          if(mid>neg[j]*pos[pos_num-delta]){
            lw_num+=delta;
            break;
          }
        }
      }
      if(k>lw_num){
        ans=max(ans,mid);
        l=mid+1;
      }else{
        r=mid-1;
      }
    }
  }else if(k<=pos_num*neg_num+zero_num*(pos_num+neg_num)+zero_num*(zero_num-1)/2){
    ans=0;
  }else{
    ll l = 1, r = 1e18;
    while(l<=r){
      ll mid = (l+r)/2;
      ll lw_num=0;
      ll delta=0;

      for(delta = 1; delta < pos_num; delta++){
        if(mid > pos[0] * pos[delta]) lw_num++;
        else break;
      }
      for(long long j = 1; j < pos_num; j++){
        for(delta; delta > j; delta--){
          if(mid > pos[j] * pos[delta-1]){
            lw_num += delta - 1 - j;
            break;
          }
        }
      }
      for(delta = 1; delta < neg_num; delta++){
        if(mid > neg[neg_num - 1] * neg[neg_num - 1 - delta]) lw_num++;
        else break;
      }
      for(long long j = 1; j < neg_num; j++){
        for(delta; delta > j; delta--){
          if(mid > neg[neg_num - 1 - j] * neg[neg_num - delta]){
            lw_num += delta - 1 - j;
            break;
          }
        }
      }
      /*
      for(ll i=0;i<pos_num;i++){
        for(ll j=i+1;j<pos_num;j++){
          //if(pos[i]*pos[j]<mid) lw_num+=pos_num-j-1;
          if(pos[i]*pos[j]<mid) lw_num++;
          //break;
        }
      }
      for(ll i=neg_num-1;i>=0;i--){
        for(ll j=i-1;j>=0;j--){
          //if(neg[i]*neg[j]<mid) lw_num+=j+1;
          //break;
          if(neg[i]*neg[j]<mid) lw_num++;
        }
      }
      */
      lw_num+=pos_num*neg_num+zero_num*(2*n-zero_num-1)/2;
      //cout << lw_num << "," << l << "," << mid << "," << r << endl;
      if(k>lw_num){
        ans=max(ans,mid);
        l=mid+1;
      }else{
        r=mid-1;
      }
    }
  }
  cout << ans << endl;
}
