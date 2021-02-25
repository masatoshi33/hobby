#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int work[10000000];//データを保管する配列を用意

void merge_sort(int array[], int left, int right){
  int k, middle;
  int len = right - left + 1;
  if(left<right){
    middle = (left+right)/2; //中間値を取る
    merge_sort(array,left,middle); //左半分をソート
    merge_sort(array,middle+1,right); //右半分をソート
    for(int i=middle;i>=left;i--) work[i] = array[i]; //workに並べる対象を入れる
    //賢い方法(左右から追い込むことによって左右どちらかの要素を使い切ることを考慮しなくていい)
    /*for(int i=middle;i<=right;i++){
      work[right-(i-(middle+1))] = array[i];
    }
    int l=left,r=right;
    for(k=left;k<=right;k++){
      if(work[l]<work[r]) array[k] = work[l++];
      else array[k] = work[r--];
    }*/
    //賢くない方法(my way)
    for(int i=middle+1;i<=right;i++) work[i] = array[i]; //workに並べる対象を入れる
    int l=left,r=middle+1; //workのうち[left,middle],[middle,right]のそれぞれは既に並んでいる
    for(k=left;k<=right;k++){
      if(work[l]<=work[r]&&l<middle+1) array[k] = work[l++];
      else if(work[l]>work[r]&&r<=right) array[k] = work[r++];
      else if(l<middle+1) array[k] = work[l++];
      else array[k] = work[r++];
    }
  }
}
int main(){
  int array[10] = { 2, 1, 8, 5, 4, 7, 9, 0, 6, 3 };
  merge_sort(array,0,9);
  for(int i=0;i<10;i++) cout << array[i] << " ";
}
