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
  cout<<"[null]";
}

void extend_list(Node** head,int data){
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

void insert_after_key(Node* head,int key,int data){
  Node* new_node = new Node();
  new_node->data = data;

  while(head){
    if(head->data == key){
      new_node->next = head->next;
      head->next = new_node;
      return;
    }
    head = head->next;
  }
  cout<<"Key is not in the list\n";
}

void update_key(Node* head,int key,int data){
  while(head){
    if (head->data == key){
      head->data = data;
      return;
    }
    head = head->next;
  }
  cout<<"Key is not in the listen\n";
}

void list_length(Node* head){
  int length = 0;
  while(head){
    length++;
    head = head->next;
  }
  cout<<"The length of list is "<<length<<endl;
}

void detect_loop(Node* head){
  Node* t1 = head;
  Node* t2 = head;
  while(t2){
    t1 = t1->next;
    t2 = t2->next->next;
    if(t2 == t1){
      cout<<"Loop detected";
      int loop_len = 1;
      t2 = t2->next;
      while(t2 == t1){
        loop_len++;
        t2 = t2->next;
      }
      cout<<"length of loop is "<< ++len;
      return;
    }
  }
  cout<<"No Loop detected";
  return;
}

int main(){
  Node* head = NULL;

  extend_list(&head,1);
  extend_list(&head,2);
  extend_list(&head,3);
  extend_list(&head,4);
  list_length(head);

  insert_after_key(head,2,1);
  update_key(head,5,1);

  cout<<"updated list is : ";
  display_list(head);
  cout<<"\n";
}
