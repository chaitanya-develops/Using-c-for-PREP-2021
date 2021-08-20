#include <bits/stdc++.h>
using namespace std;

class Node{
public:
  int data;
  Node* next;
};

void push(Node** top,int data){
  Node* newElement = new Node();
  newElement->data = data;
  newElement->next = *top;
  *top = newElement;
}

int pop(Node** top){
  Node* popper = *top;
  int val = (*top)->data;
  *top = (*top)->next;
  free(popper);
  return val;
}

void display(Node* top){
  while(top){
    cout<<top->data<<" => ";
    top = top->next;
  }
  cout<<"[NULL]\n";
  return;
}

int main(){
  Node* top = NULL;
  push(&top,4);
  push(&top,3);
  push(&top,2);
  push(&top,1);

  display(top);

  cout<<pop(&top)<<" is popped\n";

  display(top);

}
