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

void InsertLevelOrder(int data,Node** root){
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
    else{
      first->left = temp;
      break;
    }

    if (first->right){
      q.push(first->right);
    }
    else{
      first->right = temp;
      break;
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
    Node* first = q.front();
    cout<<first->data<<" ";
    q.pop();

    if (first->left){
      q.push(first->left);
    }
    if (first->right){
      q.push(first->right);
    }
  }
}

void LeftView(Node* root){
  if (root == NULL){
    return;
  }

  queue<Node*> q;
  q.push(root);

  while(!q.empty()){


    int val = q.size();

    for (int i = 1;i<=val;i++){

      Node* first = q.front();
      q.pop();
      if (i == 1){
        cout<<first->data;
      }

      if (first->left){
        q.push(first->left);
      }
      if (first->right){
        q.push(first->right);
      }
    }
  }
}

int main(){
  Node* root = NULL;
  root = new Node(4);
  root->left = new Node(5);
  root->right = new Node(2);
  root->right->left = new Node(3);
  root->right->right = new Node(1);
  root->right->left->left = new Node(6);
  root->right->left->right = new Node(7);
  // InsertLevelOrder(1,&root);
  // InsertLevelOrder(2,&root);
  // InsertLevelOrder(3,&root);
  // InsertLevelOrder(4,&root);
  // InsertLevelOrder(5,&root);
  // InsertLevelOrder(6,&root);
  // InsertLevelOrder(7,&root);
  // InsertLevelOrder(8,&root);
  LevelOrderTraversal(root);
  LeftView(root);
}
