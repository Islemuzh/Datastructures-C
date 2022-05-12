#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode* left;
  struct TreeNode* right;
};

struct TreeNode *insert(struct TreeNode *root, int val) {
  struct TreeNode* newTreeNode = NULL;
  struct TreeNode* current = root;
  if (root == NULL) {
    newTreeNode = malloc(sizeof(struct TreeNode));
    newTreeNode ->val = val;
    newTreeNode ->left = NULL;
    newTreeNode ->right = NULL;
    return newTreeNode;
  }
  if (val > root->val) {
    root->right = insert(root->right, val);
  } else {
    root->left = insert(root->left, val);
  }
  return root;
}


void printTreeRecursive(struct TreeNode* root) {
  if (root == NULL) return;
  if (root->left != NULL) {
    printf("  %d -- %d\n", root->val, root->left->val);
    printTreeRecursive(root->left);
  }
  if (root->right != NULL) {
    printf("  %d -- %d\n", root->val, root->right->val);
    printTreeRecursive(root->right);
  }
}

void printTree(struct TreeNode* root) {
  printf("graph g {\n");
  printTreeRecursive(root);
  printf("}\n");
}

struct TreeNode* TrimBST(struct TreeNode* root, int low, int high) {
  if (root==NULL) {
    return NULL;
  }
  if (root->val > high) {
    return TrimBST(root->left, low, high);
  }
  if (root->val < low) {
    return TrimBST(root->right, low, high);
  }
  root->left = TrimBST(root->left, low, high);
  root->right = TrimBST(root->right, low, high);
  return root;
}

int main() {
  struct TreeNode* root = NULL;
  printf("Inserting: 4, 2, 3, 8, 6, 7, 9, 12, 1\n");
  root = insert(root, 4);
  root = insert(root, 2);
  root = insert(root, 3);
  root = insert(root, 8);
  root = insert(root, 6);
  root = insert(root, 7);
  root = insert(root, 9);
  root = insert(root, 12);
  root = insert(root, 1);
  printTree(root);
  struct TreeNode* trimmedRoot = TrimBST(root, 3, 8);
  printTree(trimmedRoot);
  return 0;
}