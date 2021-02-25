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
  int n,m;
  cin>>n;
  vector<deque<pair<int,int>>> t(n); //first:賞味期限,second:棚の位置
  set<int> sold; //売却済みのものの賞味期限
  rep(i,n){
    int k;
    cin>>k;
    rep(j,k){
      int x;
      cin>>x;
      t[i].push_back({x,i});
    }
  }
  priority_queue<pair<int,int>> good_1,good_2; //最前列の商品、二番目の商品
  rep(i,n){
    if(!t[i].empty()){
      good_1.push(t[i].front());
      t[i].pop_front();
    }
  }
  rep(i,n){
    if(!t[i].empty()){
      good_2.push(t[i].front());
    }
  }
  good_1.push({-1,-1});
  good_2.push({-1,-1});
  cin>>m;
  rep(i,m){
    int a;
    cin>>a;
    if(a==1){
      pair<int,int> good;
      //まず一番手前を取り出す
      good = good_1.top();
      good_1.pop();
      while(sold.count(good.first)){ //既に売ってるやつは無視
        good = good_1.top(); //商品を棚から取り出す
        good_1.pop(); //取り出した商品を消す
      }
      //売却済みの列に追加
      sold.insert(good.first);
      //最前列に補充
      if(!t[good.second].empty()){
        good_1.push(t[good.second].front());
        t[good.second].pop_front();
      }
      //二列目に補充
      if(!t[good.second].empty()){
        good_2.push(t[good.second].front());
      }
      cout << good.first << endl;
    }else{
      pair<int,int> good_f; //最前列の中で高いもの
      do{
        good_f = good_1.top();
        good_1.pop();
      }while(sold.count(good_f.first));
      pair<int,int> good_s; //二列目の中で高いもの
      do{
        good_s = good_2.top();
        good_2.pop();
      }while(sold.count(good_s.first));
      pair<int,int> good; //最前列、二列目合わせて高いもの
      //最前列の方が大きければ、さっきとおんなじこと
      if(good_f.first>=good_s.first){
        good = good_f;
        good_2.push(good_s);
        sold.insert(good.first);
        if(!t[good.second].empty()){
          good_1.push(t[good.second].front());
          t[good.second].pop_front();
        }
        if(!t[good.second].empty()){
          good_2.push(t[good.second].front());
        }
        cout << good.first << endl;
      }else{ //
        good = good_s;
        good_1.push(good_f); //消したものを戻す
        sold.insert(good.first);
        //二列目を補充
        if(!t[good.second].empty()){
          t[good.second].pop_front(); //取り出すもの確定したので、棚の先頭を消す
          good_2.push(t[good.second].front());
        }
        cout << good.first << endl;
      }
    }
  }
}
