#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* next;
};

struct node* head = NULL;
struct node* current = NULL;

void insert_end(int data) {
  struct node* new = (struct node*)malloc(sizeof(struct node));
  new->data = data;
  new->next = NULL;

  if(head==NULL) {
    head = new;
    return;
  }

  current = head;

  while(current->next){
    current = current->next;
  }
  current->next = new;
}

void reverse_print(struct node* list){
  if (list == NULL) {
    printf("[NULL] \n");
    return;
  }
  reverse_print(list->next);
  printf("%d\n",list->data );
}

int main() {
  insert_end(20);
  insert_end(45);
  insert_end(93);
  insert_end(43);

  reverse_print(head);
}
