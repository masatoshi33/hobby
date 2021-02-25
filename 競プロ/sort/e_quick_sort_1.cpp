//何がダメかわからん

#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int max(int x, int y){
  if(x>=y) return x;
  else return y;
}

int quick_sort(vector<int> array){
  int pivot = max(array[0],array[1]);
  vector<int> left,right;
  if(array.size()<=1) return 0;
  for(auto i : array){
    if(pivot>=i) left.push_back(i);
    else right.push_back(i);
  }
  quick_sort(left);
  quick_sort(right);
  rep(i,array.size()){
    array.pop():
  }
  for(auto i : right){
    array.push_back(i);
  }
  for(auto i : left){
    array.push_back(i);
  }
  return 0;
}

int main{
  vector<int> vec;
  vec = {5,3,6,7,8,2,9,1,4};
  quick_sort(vec);
  int l = vec.size();
  rep(i,l) cout << vec[i] << " ";
}
