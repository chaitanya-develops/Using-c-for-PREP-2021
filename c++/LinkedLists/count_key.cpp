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

void count_key(Node* head,int key){
  int count = 0;
  while(head){
    if(head->data == key){
      count++;
    }
    head = head->next;
  }
  cout<<"The key "<<key<<" is repeated "<<count<<" times.";
}


int main(){
  Node* head = NULL;

  insert_at_end(&head,1);
  insert_at_end(&head,2);
  insert_at_end(&head,1);
  insert_at_end(&head,3);
  insert_at_end(&head,1);
  insert_at_end(&head,3);
  insert_at_end(&head,1);
  insert_at_end(&head,3);

  display_list(head);

  count_key(head,1);
}
