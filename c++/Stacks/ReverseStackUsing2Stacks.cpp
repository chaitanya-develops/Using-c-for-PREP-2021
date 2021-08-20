#include<bits/stdc++.h>
using namespace std;

class Node{
public:
  int data;
  Node* next;
};

void display(Node* head){
  while(head){
    cout<<head->data<<" ";
    head = head->next;
  }
  cout<<"[NULL]";
  return;
}

void push(Node** head,int data){
  Node* newNode = new Node();
  newNode->data = data;
  newNode->next = *head;
  *head = newNode;
}

int pop(Node** head){
  Node* ptr = *head;
  *head = (*head)->next;
  int val = ptr->data;
  delete(ptr);
  return val;
}

bool IsEmpty(Node* head){
  if (head = NULL){
    return true;
  }
  else{
    return false;
  }
}

int top(Node* head){
  return head->data;
}

int main(){
  Node* head = NULL;
  Node* stck2 = NULL;
  push(&head,0);
  push(&head,1);
  push(&head,2);
  push(&head,3);
  push(&head,4);
  push(&head,5);
  push(&head,6);
  while(head){
    push(&stck2,pop(&head));
  }

  // display(head);
  display(stck2);
}
