#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* next;
};

struct node* head = NULL;
struct node* current = NULL;

void insert_at_end(int data){
  struct node* new = (struct node*) malloc(sizeof(struct node));
  new->data = data;
  new->next = NULL;

  if (head == NULL){
    head = new;
    return;
  }

  current = head;

  while(current->next){
    current = current->next;
  }
  current->next = new;

}

void count_list() {
  int count = 0;

  if (head == NULL){
    printf("The size of the list is %d\n",count);
    return;
  }
  current = head;
  while (current) {
    current = current->next;
    count++;

  }
  printf("List size is : %d\n",count);
}

int main() {
  insert_at_end(90);
  insert_at_end(23);
  insert_at_end(45);
  insert_at_end(34);
  count_list();
}
