#include<bits/stdc++.h>
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
  cout<<"[NULL]";
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

void delete_with_given_pointer(Node* ptr){
  while(ptr->next->next){
    ptr->data = ptr->next->data;
    ptr = ptr->next;
  }
  ptr->data = ptr->next->data;
  ptr->next = NULL;
}

int main(){
  Node* head = NULL;
  insert_at_end(&head,1);
  insert_at_end(&head,2);
  insert_at_end(&head,3);
  insert_at_end(&head,4);

  display_list(head);

  delete_with_given_pointer(head);

  display_list(head);
}
