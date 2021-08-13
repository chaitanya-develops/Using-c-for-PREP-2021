#include <bits/stdc++.h>
using namespace std;

class Node{
public:
  int data;
  Node* next;
};

void display_list(Node* head){
  while(head){
    cout<<head->data<<" => ";
    head = head->next;
  }
  cout<<"[NULL]\n";
}

Node* find_last(Node* head){
  while(head->next){
     head = head->next;
  }
  return head;
}

void insert_at_end(Node** head,int data){
  Node* new_node = new Node();
  new_node->data = data;
  new_node->next = NULL;

  if (*head == NULL){
    *head = new_node;
    return;
  }

  Node* last = find_last(*head);
  last->next = new_node;
  return;
}

void reverse_list(Node** head){
  Node* prev = NULL;
  Node* curr = *head;
  Node* nxt = curr->next;

  while(curr->next){
    curr->next = prev;
    prev = curr;
    curr = nxt;
    nxt = curr->next;
  }
  curr->next = prev;
  *head = curr;
  return;
}

int main(){
  Node* head = NULL;

  insert_at_end(&head,0);
  insert_at_end(&head,1);
  insert_at_end(&head,2);
  insert_at_end(&head,3);

  display_list(head);

  reverse_list(&head);

  display_list(head);
}
