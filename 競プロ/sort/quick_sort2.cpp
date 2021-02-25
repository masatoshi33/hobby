#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

void swap(int *x, int *y){
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}
int partition(int array[],int left,int right){
  int i,j,pivot;
  i = left;
  j = right+1;
  pivot = left;
  do{
    do {i++;} while(array[i]<array[pivot]);
    do {j--;} while(array[pivot]<array[j]);
    if(i<j) swap(array[i],array[j]);
  }while(i<j);
  //pivotを更新
  swap(&array[pivot],&array[j]); //pivotは動かしてないのでjの後(iの前)に持っていきたい
  return j;
}
void quick_sort(int array[],int left,int right){
  int pivot;
  if(left<right){
    pivot = partition(array,left,right);
    quick_sort(array,left,pivot-1);
    quick_sort(array,pivot+1,right);
  }
}
int main(){
  //確認用
  /*int a=0,b=1;
  swap(a,b);
  cout << a << " " << b;
  */
  int array[10] = { 2, 1, 8, 5, 4, 7, 9, 0, 6, 3 };
  quick_sort(array,0,9);
  for(int i=0;i<10;i++) cout << array[i] << " ";
}
