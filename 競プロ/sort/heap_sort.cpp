#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

void swap(int *x, int *y){
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

void pushdown(int array[], int first, int last){
  int parent = first; //firstを親として考える
  int child = 2*parent; //子要素のうち左のもの
  //lastに到達するまで逆さのものをひっくり返す
  while(child<=last){ //一番下まで
    //右の方が大きければ右の子を比較対象に設定
    if(child<last&&array[child]<array[child+1]) child++;
    if(array[child]<=array[parent]) break; //ヒープ済み
    swap(&array[child],&array[parent]);
    //親の位置の更新
    parent = child;
    child = 2*parent;
  }
}

void heap_sort(int array[], int array_size){
  for(int i=array_size/2;i>=1;i--){
    pushdown(array,i,array_size); //全体をヒープ化
  }
  for(int i=array_size;i>=2;i--){
    swap(&array[1], &array[i]); //最大のものを最後に
    pushdown(array,1,i-1); //ヒープ再構築
  }
}

int main(){
  int array[11] = {0, 2, 1, 8, 5, 4, 7, 9, 6, 3 ,10};
  heap_sort(array,10);
  for(int i=0;i<11;i++) cout << array[i] << " ";
}
