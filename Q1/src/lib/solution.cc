#include "solution.h"
#include <iostream>
#include <queue>



BST::BST(){
  this->root_ =  nullptr;
}

BST::BST(std::vector<int> initial_values){
  this->root_ = nullptr;
  for(int i = 0; i < initial_values.size(); i++){
    insert(root_, initial_values[i]);
  }
}

void BST::DestroyRecursive(TreeNode *&root){
  if (root != nullptr){
  DestroyRecursive(root->left);
  DestroyRecursive(root->right);
  delete root;
  }
}

BST::~BST(){
  DestroyRecursive(root_);
  std::cout << "destructor" << std::endl;
}

void BST::push(int key){
  insert(this->root_, key);
}

bool BST::find(int key){
  TreeNode* temp = root_;
  while (temp != nullptr) {
    if (temp->val == key) {
      return true;
    }else {
      if (key > temp->val) {
        temp = temp->right;
      }else {
        temp = temp->left;
      }
    }
  }
  return false;
}

bool BST::erase(int key){
  if(find(key) == true){
    deleteNode(root_, key);
    std::cout << std::endl;
    return true;
  }else{
    return false;
  }
}

void BST::insert(TreeNode *&root, int key){
  if (root == nullptr) {
    root = new TreeNode(key); 
  } else if (key < root->val) {
    insert(root->left, key);
  } else if (key > root->val) {
    insert(root->right, key); 
  }
}

void BST::preorder(TreeNode *&root){ 
    if (root != nullptr) 
    { 
      std::cout << root->val <<" ";
      preorder(root->left); 
      preorder(root->right); 
    } 
} 
void BST::print(){
  // preorder(root_);
  // LevelOrder(root_);
  std::cout << height(root_)<< std::endl;
}

TreeNode* BST::deleteNode(TreeNode *&root, int key){ 
  if (root == NULL){
    return root; 
  } 
  if (key < root->val){
    root->left = deleteNode(root->left, key); 
  }else if(key > root->val){
    root->right = deleteNode(root->right, key); 
  }else{
    if (root->left == nullptr){ 
      TreeNode *temp = root->right; 
      delete root; 
      return temp; 
    }else if(root->right == nullptr){ 
      TreeNode *temp = root->left; 
      delete root; 
      return temp; 
    } 
    TreeNode *temp = root->right;
    while (temp && temp->left != nullptr){
      temp = temp->left;
    }
    root->val = temp->val; 
    root->right = deleteNode(root->right, temp->val); 
  } 
  return root; 
} 

void BST::LevelOrder(TreeNode *&root){
  if(root == nullptr){
    return ;
  }
  std::queue<TreeNode*> q;
  q.push(root);

  while(q.size() != 0){
    TreeNode *temp = q.front(); 
    std::cout << temp->val << " ";
    q.pop();
    if (temp->left != nullptr) {
      q.push(temp->left); 
    }
    if (temp->right != nullptr) {
      q.push(temp->right); 
    }
  }
}

int BST::height(TreeNode *&root){
  if (root == nullptr){
    return 0;
  }else{
    int lh = height(root->left);
    int rh = height(root->right);
    if (lh > rh) {
      return(lh + 1);
    }else{
      return(rh + 1);
    }
  }
}