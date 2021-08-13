#include <bits/stdc++.h>
using namespace std;

class Node{
public:
  int data;
  Node* next;
};

void display_list(Node* temp){
  while(temp){
    cout << temp->data<<" => ";
    temp = temp->next;
  }
  cout<<"[NULL]";
}

void insert_at_head(Node** head,int data){
  Node* new_node = new Node();
  new_node->data = data;
  new_node->next = *head;
  *head = new_node;
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

int main(){
  Node* head  = NULL;

  insert_at_head(&head,1);
  insert_at_head(&head,2);
  insert_at_head(&head,3);
  insert_at_head(&head,4);

  insert_at_end(&head,1);
  insert_at_end(&head,2);
  insert_at_end(&head,3);
  insert_at_end(&head,4);

  display_list(head);

}
