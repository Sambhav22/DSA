#include<iostream>
#include "./../helpers/array_helpers.cpp"
#include "./../helpers/operations_helpers.cpp"
using namespace std;

template<typename T>
void merge(T arr[], int left, int mid, int right){
  int n1 = mid - left + 1;
  int n2 = right - mid;
  T L[n1], R[n2];
  for(int i=0;i<n1;i++){
    L[i] = arr[left+i];
  }
  for(int j=0;j<n2;j++){
    R[j] = arr[mid+1+j];
  }
  int i=0, j=0, k=left;
  while(i < n1 && j < n2){
    if(L[i] <= R[j]){
      arr[k] = L[i];
      i++;
    }
    else{
      arr[k] = R[j];
      j++;
    }
    k++;
  }
  while(i < n1){
    arr[k] = L[i];
    k++;
    i++;
  }
  while(j < n2){
    arr[k++] = R[j++];
    k++;
    j++;
  }
}

template<typename T>
void merge_sort(T arr[], int left,int right){
  if(left >= right){
    return;
  }
  int mid = left + (right-left)/2;
  merge_sort(arr, left, mid);
  merge_sort(arr, mid+1, right);
  merge(arr, left, mid, right);
}

int main() {
  int arr[] = {3, 1, 4, 2, 5};
  int l = sizeof(arr)/sizeof(arr[0]);
  Array<int> a(l, arr);
  cout<<"input array: \n";
  a.print_array(l, arr);

  merge_sort<int>(arr, 0, l-1);
  
  cout<<"output array: \n";
  a.print_array(l, arr);
  return 0;
}