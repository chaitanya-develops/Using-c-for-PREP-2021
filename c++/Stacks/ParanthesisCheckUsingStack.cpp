#include <bits/stdc++.h>
using namespace std;
#include<iostream>

class Node{
public:
  char data;
  Node* next;
};

bool Isempty(Node* top){
  if (top == NULL){
    return true;
  }
  else{
    return false;
  }
}

void push(Node** top,char data){
  Node* newElement = new Node();
  newElement->data = data;
  newElement->next = *top;
  *top = newElement;
}

void pop(Node** top){
  if (*top == NULL){
    cout<<"Stack Underflow";
    return;
  }
  Node* ptr = *top;
  *top = (*top)->next;
  delete ptr;
}

char TopElement(Node* top){
  return top->data;
}

void display(Node* top){
  while(top){
    cout<<top->data<<" => ";
    top = top->next;
  }
  cout<<"[NULL]\n";
  return;
}

bool IsBalanced(Node** top,string data){
  char val;
  for (int i =0;i<data.length();i++){
    if (data[i] == '[' || data[i] == '{' || data[i] == '('){
      push(top,data[i]);
      continue;
    }// end of push if;

    if (Isempty(*top)){
      return false;
    }// end of first isempty check;
    switch (data[i]) {
      case ')':
        val = TopElement(*top);
        pop(top);
        if (val == '}' || val == ']'){
          return false;
        }
        break;
      case '}':
        val = TopElement(*top);
        pop(top);
        if (val == ')' || val == ']'){
          return false;
        }
        break;
      case ']':
        val = TopElement(*top);
        pop(top);
        if (val == ')' || val == '}'){
          return false;
        }
        break;

    }// end of switch;



  }//end of for loop;
  return Isempty(*top);

}//end of function;



int main(){
  string data = "";
  Node* top = NULL;

  if (IsBalanced(&top,data)){
    cout<<"It is balanced";
  }
  else{
    cout<<"It is not balanced";
  }
}
