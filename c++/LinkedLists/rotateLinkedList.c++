#include <bits/stdc++.h>
using namespace std;

class Node{
public:
  int data;
  Node* next;
};

void displayList(Node* head){
  while(head){
    cout<<head->data<<" => ";
    head = head->next;
  }
  cout<<"[NULL]\n";
}

void insertAtEnd(Node** head,int data){
  Node* newNode = new Node();
  newNode->data = data;
  newNode->next = NULL;

  if (*head == NULL){
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

void RotateArray(Node**head,int ShiftValue){
  Node* last = *head;
  while(last->next){
    last = last->next;
  }
  last->next = *head;
  while(ShiftValue){
    last = last->next;
    --ShiftValue;
  }
  *head = last->next;
  last->next = NULL;
}

int main(){
  Node* head = NULL;
  insertAtEnd(&head,1);
  insertAtEnd(&head,2);
  insertAtEnd(&head,3);
  insertAtEnd(&head,4);
  insertAtEnd(&head,5);
  insertAtEnd(&head,6);

  displayList(head);

  RotateArray(&head,3);

  displayList(head);
}
