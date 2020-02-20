#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <vector>
#include <algorithm>

struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BST {
public:
BST();

// Inserts elements of initial_values
// one by one into the Tree
BST(std::vector<int> initial_values);
~BST();

void push(int key); // **GT** Inserts a key inside Tree
bool find(int key); // **GT** Returns true of key is in the tree
bool erase(int key); // **GT** Removes the key from the tree. If not successful, returns false.
void print();
void LevelOrder(TreeNode *&root);
void InorderRecursive(TreeNode *&root);
void Inorder(TreeNode *&root);
private:
TreeNode *root_;
void insert(TreeNode *&root, int v);
bool remove(TreeNode *&root, int key);
void preorder(TreeNode *&root);
TreeNode* deleteNode(TreeNode *&root, int key);
void DestroyRecursive(TreeNode *&root);

};

#endif