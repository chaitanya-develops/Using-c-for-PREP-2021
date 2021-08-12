#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* next;
};

struct node* head = NULL;
struct node* current = NULL;

void insert_at_end(int data) {
  struct node* new = (struct node*)malloc(sizeof(struct node));
  new->data = data;
  new->next = NULL;

  if (head==NULL){
    head = new;
    return;
  }

  current = head;

  while(current->next){
    current = current->next;
  }
  current->next = new;
}

void find_data(int value) {
  if (head==NULL) {
    printf("The list is empty!");
    return;
  }
  int pos = 0;
  current = head;
  while(current){
    if(current->data == value){
      printf("The value is present at %d\n",pos);
      return;
    current = current->next;
    ++pos;
    }
  }
  printf("The value is not present in the list");
}


int main(){
  insert_at_end(90);
  insert_at_end(43);
  insert_at_end(54);
  insert_at_end(32);
  insert_at_end(65);

  find_data(3);
  find_data(43);
}
