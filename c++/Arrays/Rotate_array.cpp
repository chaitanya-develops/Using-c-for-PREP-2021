#include<bits/stdc++.h>
using namespace std;

void rotate_by_one(int arr[],int n){
  int temp = arr[0];
  for(int i = 0;i<n-1;i++){
    arr[i] = arr[i+1];
  }
  arr[n-1] = temp;
}

void rotate_by_d(int arr[],int n,int d){
  for(int i = 0;i<d;i++){
    rotate_by_one(arr,n);
  }
}

void display_array(int arr[],int n){
  for(int i =0;i<n;i++){
    cout<<arr[i]<<" ";
  }

}

int main(){
  int arr[] = {1,2,3,4,5};
  int n = 5;
  int d = 2;
  display_array(arr,n);
  rotate_by_d(arr,n,d);
  display_array(arr,n);
}
