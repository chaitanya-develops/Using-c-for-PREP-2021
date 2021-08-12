#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node *next;
};

struct node* head = NULL;
struct node* temp = NULL;

// DISPLAY THE LIST FROM HEAD TO LAST NODE
void display(){
  printf("[head] => ");
  while(temp){
    printf("%d => ",temp->data);
    temp = temp->next;

  }
  printf("[null]\n");
}

// INSERT AT THE BEGINNING
void insert(int data){
  struct node* new = (struct node*)malloc(sizeof(struct node));
  new->data = data;
  new->next = head;
  head = new;
}

int main(){
  insert(10);
  insert(45);
  insert(56);
  temp = head;
  display();
}
