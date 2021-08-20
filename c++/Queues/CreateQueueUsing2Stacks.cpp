#include <bits/stdc++.h>
using namespace std;

class Node{
public:
  int data;
  Node* next;
};

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
  delete ptr;
  return val;
}

void enqueue(Node** head,int data){
  push(head,data);
}

int dequeue(Node** head,Node** head2){
  while(*head){
    push(head2,pop(head));
  }
  int val = pop(head2);
  while(*head2){
    push(head,pop(head2));
  }
  return val;
}

void display(Node* head){
  while(head){
    cout<<head->data<<" ";
    head = head->next;
  }
  cout<<"[NULL]";
  return;
}

int main(){
  Node* head = NULL;
  Node* head2 = NULL;
  enqueue(&head,1);
  enqueue(&head,2);
  enqueue(&head,3);
  dequeue(&head,&head2);
  enqueue(&head,4);
  enqueue(&head,5);
  dequeue(&head,&head2);

  display(head);
}
