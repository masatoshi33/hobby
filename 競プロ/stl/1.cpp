#include <bits/stdc++.h>
#include <math.h>
#include <vector>
#include <queue>
#include <iomanip>
#include <string>
#include <algorithm>
#include <functional>
#include <bitset>
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

int main(){
  //string
  S.substr(l); //Sのl文字目から最後の文字までの部分文字列を返す関数。
  S.substr(l,r); //Sのi文字目からl+r-1文字目まで(r文字分ということ)の部分文字列を返す関数。

  //min,max
  min({a1,a2,...,an}); //{a1,a2,...,an}の中で最小のものを返す。
  max({a1,a2,...,an}); //{a1,a2,...,an}の中で最大のものを返す。
  *min_element(c+l,c+r); //{c[l],c[l+1],...,c[r-1]}の中で最小のものを返す。
  *max_element(c+l,c+r); //{c[l],c[l+1],...,c[r-1]}の中で最大のものを返す。

  //__gcd
  __gcd(a,b); //最大公約数
  a/ __gcd(a,b) * b; //最小公倍数

  //rand
  rand(); //0~2^31-1のランダムな整数を返す関数
  srand((unsigned)time(NULL)); //おまじない。main関数の冒頭にこれをつけると、
  //実行ごとに乱数生成結果が変わる。

  //clock
  clock(); //プログラム実行開始から何単位時間経過したかを整数で返す。
  CLOCKS_PER_SEC; //定数。環境によって1秒が何単位時間か異なるので、
  //秒数を知りたいときに使える。
  clock()/CLOCKS_PER_SEC; //ジック開始からの秒数

  //reverse
  reverse(a+l,a+r) //a[l],a[1],..a[r-1]を逆順に並び替える。

  //sort
  sort(a+l,a+r); //a[l],a[l+1],..a[r-1]を小さい順に並び替える。
  sort(a,a+n,greater<int>()); //a[0],a[1],..a[n-1]を大きい順に並び替える。

  //vector
  sort(a.betin()+l,a.begin()+r); //l番目からr番目までソートする場合

  //stack
  a.empty(); //スタックaの要素数が0である場合true、1以上である場合falseを返す

  //queue
  a.empty(); //キューaの要素数が0である場合true、1以上である場合falseを返す

  //priority_queue
  a.pop(); //a内の最も小さい要素（設定によっては、最も大きい要素）を取り除きます。
  a.top(); //a内の最も小さい要素（設定によっては、最も大きい要素）を返す。
  // int型の要素を持ち、最も小さい値を取り出す形の priority_queue を定義する場合
  priority_queue<int, vector<int>, greater<int>> Q1;
  // int 型の要素を持ち、最も大きい値を取り出す形の priority_queue を定義する場合
  priority_queue<int, vector<int>, less<int>> Q3;

  //map
  a.clear(); //マップaを初期化。

  //lower_bound
  lower_bound(a, a + N, x) - a; //x<=a[i]となるような最小のiの値を返す。

  //multiset
  a.insert(x); //集合aに要素xを追加する
  a.erase(x); //要素xをすべて消去する
  a.erase(y); //集合aからイテレータ〜yの要素を一つ消去する。
  a.lower_bound(x) //集合aの中でx以上である最小の要素を指すイテレーターを返す。

  //tuple:三つ以上の要素を持てる型
  //型 v1, 型 v2, ..., 型 vn を持つ tuple
  tuple< v1,v2,...,vn > a;
  //tuple 型変数 a の i 個目の要素にアクセスしたい場合。(0個目の要素から始まることに注意してください。)
  get<i>(a);
  //引数のコピーから tuple を生成することができます。
  make_tuple(a1,a2,...,an);
  //a,s,fにdataのそれぞれの要素を代入
  data = make_tuple(2,"world",true);
  tie(a,s,f)=data;

  //assert
  //条件を満たさないときランタイムエラーを出す
  assert("条件");

  //count
  count(a*l,a+r,x); //配列aに対して、a[l],a[l+1],..,a[r-1]の中でxとなるものの個数
  count(v.begin(),v.end().x); //vector vの場合

  //find:計算量:O(n)
  find(a+l,a+r,x) //a[l],.a[r-1]の中にxが含まれない場合はa+rのイテレーター
  //そうでない場合はa[l]から見て行ったときにa[i]=xとなるa[i]のイテレーター
  find(a.begin(), a.end(), x); //vector の場合

  //next_permutation:計算量最大O(n)
  //配列aの0番目からn-1番目までを並び替える
  //while 文は、次の順列が存在しないときに抜けます
  do {
    for (int i = 0; i < n; i++) {
        if (i) cout << ",";
        cout << a[i];
    }
    cout << endl;
  } while(next_permutation(a, a + n));

  //__builtin_popcount
  __builtin_popcount(x); //int xを二進数で表した時の1の数を数える
  __builtin_popcountll(x); //ll xを二進数で表した時の1の数を数える

  //bitset:ビット集合を表す型。n肩の2進数とみなせる。ビット演算を高速に行う時使う。
  // 例 1: A or B を計算します。なお、A と B は string 型で 2 進数で与えられます。
  //A,Bをstringとして入力してから、それをbitの集合に変換している。
  string A, B; cin >> A >> B;
  bitset<2000> A1(A);bitset<2000> B1(B);
  bitset<2000> ans = (A1 | B1);
  a.set(x); //aのx桁目(2^xの位)を1に変更
  a.reset(x); //aのx桁目(2^xの位)を1に変更
}
