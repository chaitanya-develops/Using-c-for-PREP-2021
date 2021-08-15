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

void find_middle(Node* head){
  Node* fast = head;
  Node* slow = head;
  while(fast->next && fast->next->next){
    slow = slow->next;
    fast = fast->next->next;
  }
  cout<<slow->data<<" is the data in the middle node";
}

int main(){
  Node* head = NULL;
  insert_at_end(&head,1);
  insert_at_end(&head,2);
  insert_at_end(&head,3);
  insert_at_end(&head,4);

  display_list(head);

  find_middle(head);
}
