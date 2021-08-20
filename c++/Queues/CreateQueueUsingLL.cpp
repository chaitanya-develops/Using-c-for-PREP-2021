#include <bits/stdc++.h>
using namespace std;

class Node{
public:
  int data;
  Node* next;
};

void enqueue(Node** head,int data){
  Node* newNode = new Node();
  newNode->data = data;
  newNode->next = NULL;

  if (*head==NULL){
    *head = newNode;
    return;
  }
  Node* last = *head;
  while(last->next){
    last = last->next;
  }
  last->next = newNode;
  return;
}

int dequeue(Node** head){
  Node* ptr = *head;
  *head = (*head)->next;
  int val = ptr->data;
  delete ptr;
  return val;
}

void DisplayQueue(Node* head){
  while(head){
    cout<<head->data<<" ";
    head = head->next;
  }
  cout<<"[NULL]";
  return;
}

int main(){
  Node* head = NULL;
  enqueue(&head,0);
  enqueue(&head,1);
  enqueue(&head,2);
  enqueue(&head,3);
  enqueue(&head,4);
  enqueue(&head,5);
  enqueue(&head,6);
  int val = dequeue(&head);
  DisplayQueue(head);
}
