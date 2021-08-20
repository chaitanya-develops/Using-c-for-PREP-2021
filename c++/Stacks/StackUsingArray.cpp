#include<bits/stdc++.h>
using namespace std;
int arr[100];
int top = -1;

void push(int data){
  // top++;
  arr[++top] = data;
}

int pop(){
  return arr[top--];
}

void displayStack(int top){
  cout<<"[";
  while(top>=0){
    cout<<arr[top]<<" ";
    top--;
  }
  cout<<"]\n";
}

int main(){
  push(4);
  push(3);
  push(2);
  push(1);
  displayStack(top);
  cout<<" "<<pop()<<" is popped.\n";

  displayStack(top);

}
