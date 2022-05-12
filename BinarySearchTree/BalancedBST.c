#include <stdlib.h>
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* insert(struct TreeNode* root, int val) {
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


int inorder_array[100];
int inorder_id = 0;

void InorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    InorderTraversal(root->left);
    inorder_array[inorder_id] = root->val;
    inorder_id++;
    InorderTraversal(root->right);
}
struct TreeNode* ConstructBSTFromArray(int start, int end) {
    if (start > end) {
        return NULL;
    }
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    int mid = (start + end) / 2;
    root->val = inorder_array[mid];
    root->left = ConstructBSTFromArray(start, mid - 1);
    root->right = ConstructBSTFromArray(mid + 1, end);
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
    InorderTraversal(root);
    struct TreeNode* newRoot = ConstructBSTFromArray(0, inorder_id);
    printTree(newRoot);
    return 0;
}