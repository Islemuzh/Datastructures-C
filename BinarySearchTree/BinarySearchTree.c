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

struct TreeNode* search(struct TreeNode* root, int val) {
    struct TreeNode* current = root;
    while (current != NULL && current->val != val) {
        if (val < current->val) {
        current = current->left;
        } else {
        current = current->right;
        }
    }
    return current;
}

struct TreeNode* delete(struct TreeNode* root, int val) {
    struct TreeNode* x = search(root, val);
    if (x == NULL) {  // search did not find an element, hence do nothing, just simply return the root.
        return root;
    }
    struct TreeNode* u = root;
    struct TreeNode* parent = NULL;  // parent of tree node with value = val
    while (u != x) {
        parent = u;
        if (x->val < u->val) {
        u = u->left;
        } else {
        u = u->right;
        }
    }
    // Leaf and root case also handled in the no right or left branch. Since if
    // it's leaf, its null anyway.
    if (u->right == NULL) {  // there is no right branch
        if (parent == NULL) {    // delete root
        root = u->left;
        } else if (parent->left == u) {  // if it's a left child, make left the new child
        parent->left = u->left;
        } else {
        parent->right = u->left;
        }
    } else if (u->left == NULL) {  // there is no left branch
        if (parent == NULL) {          // delete root
        root = u->right;
        } else if (parent->left == u) {  // if it's a left child, make right the new child
        parent->left = u->right;
        } else {
        parent->right = u->right;
        }
    } else {
        struct TreeNode* p = x->left;
        struct TreeNode* q = p;
        while (p->right != NULL) {  // whilst right is null
        q = p;
        p = p->right;
        }
        if (parent == NULL) {  // if we are at root
        root = p;
        } else if (parent->left == u) {  // if its a left child
        parent->left = p;
        } else {  // if its a right child
        parent->right = p;
        }
        p->right = u->right;
        if (q != p) {
        q->right = p->left;
        p->left = u->left;
        }
    }
    free(u);
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
    printf("Deleting: 4, 12, 2\n");
    root = delete (root, 4);
    root = delete (root, 12);
    root = delete (root, 2);
    printTree(root);

    return 0;
}