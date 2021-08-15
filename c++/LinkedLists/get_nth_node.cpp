#include<bits/stdc++.h>
using namespace std;

class Node{
public:
  int data;
  Node* next;
};

void nthnode(Node* head,int n){
  for(int i =0;i<n-1;i++){
    head = head->next;
  }
  cout<<head->data<<" is the "<<n<<" th node";
  return;
}

void insert_at_the_end(Node** head,int data){
  Node* new_node = new Node();
  new_node->data = data;
  new_node->next = NULL;

  if (*head == NULL){
    *head = new_node;
    return;
  }

  Node* last = *head;

  while (last->next) {
    last = last->next;
  }
  last->next = new_node;
  return;
}

void display_list(Node* temp){
  while(temp){
    cout << temp->data<<" => ";
    temp = temp->next;
  }
  cout<<"[NULL]";
}

int main(){
  Node* head = NULL;
  insert_at_the_end(&head,1);
  insert_at_the_end(&head,2);
  insert_at_the_end(&head,3);
  insert_at_the_end(&head,4);

  display_list(head);

  nthnode(head,2);
}
