#include<bits/stdc++.h>
#include<queue>
using namespace std;

class Node{
public:
  int data;
  Node* left;
  Node* right;

  Node(int val){
    data = val;
    left = NULL;
    right = NULL;
  }
};

void insertNode(int data,Node** root){
  Node* temp = new Node(data);
  if (*root == NULL){
    *root = temp;
    return;
  }

  queue<Node*> q;
  q.push(*root);

  while(!q.empty()){
    Node* first = q.front();
    q.pop();


    if (first->left){
      q.push(first->left);
    }
    else {
      first->left = temp;
      return;
    }

    if (first->right){
      q.push(first->right);
    }
    else {
      first->right = temp;
      return;
    }
  }
}

void LevelOrderTraversal(Node* root){
  if (root == NULL){
    return;
  }

  queue<Node*> q;
  q.push(root);

  while(!q.empty()){
    Node* temp = q.front();
    cout<<temp->data<<" ";
    q.pop();

    if (temp->left){
      q.push(temp->left);
    }

    if (temp->right){
      q.push(temp->right);
    }
  }
}

void PreOrderTraversal(Node* root){
  if (root){
    std::cout << root->data << " ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
  }
}

int main(){
  Node* root = NULL;
  insertNode(1,&root);
  insertNode(2,&root);
  insertNode(3,&root);
  insertNode(4,&root);
  insertNode(5,&root);
  insertNode(6,&root);
  insertNode(7,&root);
  LevelOrderTraversal(root);
  PreOrderTraversal(root);
}
