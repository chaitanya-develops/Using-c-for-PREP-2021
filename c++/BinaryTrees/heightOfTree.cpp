#include<bits/stdc++.h>
using namespace std;
#include<queue>

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

    if (temp->left){
      q.push(temp->left);
    }

    if (temp->right){
      q.push(temp->right);
    }
  }
}

void InsertLevelOrder(int data, Node** root){
  if (*root == NULL){
    *root = new Node(data);
    return;
  }

  queue<Node*> q;
  q.push(*root);

  while(!q.empty()){
    Node* temp = q.front();
    q.pop();

    if (temp->left){
      q.push(temp->left);
    }
    else{
      temp->left = new Node(data);
      return;
    }

    if (temp->right){
      q.push(temp->right);
    }
    else{
      temp->right = new Node(data);
      return;
    }
  }
}

int heightOfTree(Node* root){
  if (root == NULL){
    return 0;
  }
  if (!root->left && !root->right){
    return 0;
  }

  int l,r;

  l = heightOfTree(root->left);
  r = heightOfTree(root->right);
  int max;
  if (l>r){
    max = l;
  }
  else{
    max = r;
  }
  return 1+max;

}

int main(){
  Node* root = NULL;
  InsertLevelOrder(1,&root);
  InsertLevelOrder(2,&root);
  InsertLevelOrder(3,&root);
  InsertLevelOrder(4,&root);
  InsertLevelOrder(5,&root);
  InsertLevelOrder(6,&root);
  InsertLevelOrder(7,&root);
  InsertLevelOrder(8,&root);
  InsertLevelOrder(9,&root);
  InsertLevelOrder(10,&root);
  displayLevelOrder(root);
  cout<<endl;
  cout<<"Height of the tree is : ";
  cout<<heightOfTree(root);
}
