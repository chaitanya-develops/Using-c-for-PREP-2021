#include <bits/stdc++.h>
using namespace std;

class Node{
public:
  int data;
  Node* next;
};

void display_list(Node* temp){
  while(temp){
    cout<<temp->data<<" => ";
    temp = temp->next;
  }
  cout<<"[null]";
}

void insert_at_end(Node** head,int data){
  Node* new_node = new Node();
  new_node->data = data;
  new_node->next = NULL;

  if (*head == NULL){
    *head = new_node;
    return;
  }

  Node* last = *head;

  while(last->next){
    last = last->next;

  }
  last->next = new_node;
  return;
}

// work on freeing the space and pointers
void delete_last(Node* head){
  while(head->next->next){
    head = head->next;
  }
  head->next = NULL;
  return;
}

void delete_head(Node** head){
  *head = (*head)->next;
  return;
}

int main(){

  Node* head = NULL;

  insert_at_end(&head,1);
  insert_at_end(&head,2);
  insert_at_end(&head,3);
  insert_at_end(&head,4);

  delete_last(head);
  delete_head(&head);

  display_list(head);
}
