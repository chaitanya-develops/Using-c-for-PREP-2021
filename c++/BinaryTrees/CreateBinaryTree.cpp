#include <bits/stdc++.h>
#include <queue>
using namespace std;


class Node{
public:
  int data;
  Node* left;
  Node* right;

  Node(int val)
  {
    data = val;
    left = NULL;
    right = NULL;
  }
  // Node* parent;
};

//
// class QNode{
// public:
//   Node* treeNode;
//   QNode* next;
// };
//
// void add(Node* root,QNode** head){
//   QNode* newNode = new QNode();
//   newNode->treeNode = root;
//   newNode->next = NULL;
//   if (*head == NULL){
//     *head = newNode;
//     return;
//   }
//   QNode* last = *head;
//   while(last->next){
//     last = last->next;
//   }
//   last->next = newNode;
//   break;
// }
//
// void remove(QNode** head){
//   QNode* first = *head;
//   *head = (*head)->next;
//   delete first;
// }
//
// void displayLevelOrder(Node* root,QNode** head){
//   add(root,head);
//   while(*head){
//     cout<<(*head)->treeNode->data;
//     add(root->left,head);
//     add(root->right,head);
//     remove(head);
//   }
// }


void displayLevelOrder(Node* root){
  if (root == NULL){
    return;
  }

  queue<Node*> q;
  q.push(root);

  while(!q.empty()){
    Node* temp = q.front();
    q.pop();
    cout<<temp->data<<" ";

    if (temp->left != NULL){
      q.push(temp->left);
    }

    if (temp->right != NULL){
      q.push(temp->right);
    }
  }

}



void displayPreOrder(Node* root){
  if (root == NULL){
    return;
  }
  cout<<root->data<<" ";
  displayPreOrder(root->left);
  displayPreOrder(root->right);
}

void displayInOrder(Node* root) {
  if (root == NULL){
    return;
  }
  displayInOrder(root->left);
  cout<<root->data<<" ";
  displayInOrder(root->right);
}

void displayPostOrder(Node* root){
  if (root == NULL){
    return;
  }
  displayPostOrder(root->left);
  displayPostOrder(root->right);
  cout<<root->data<<" ";
}

int main(){
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  cout<<"Pre order traversal of the given Tree is : ";
  displayPreOrder(root);
  cout<<endl;
  cout<<"In order traversal of the given Tree is : ";
  displayInOrder(root);
  cout<<endl;
  cout<<"Post order traversal of the given Tree is : ";
  displayPostOrder(root);
  cout<<endl;
  displayLevelOrder(root);
}
