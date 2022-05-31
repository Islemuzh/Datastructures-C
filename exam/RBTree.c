#include <stdlib.h>
#include <stdio.h>

#define black 0
#define red 1

struct rb_node {
  int key;
  int color;
  struct rb_node* left;
  struct rb_node* right;
  struct rb_node* parent;
};

struct rb_tree {
  int bh;
  struct rb_node *root;
  struct rb_node *nil;
};

struct rb_tree* rb_initialize() {
  struct rb_tree* tree;
  struct rb_node* node;

  tree = (struct rb_tree*) malloc(sizeof(struct rb_tree));

  tree->nil = (struct rb_node*) malloc(sizeof(struct rb_node));
  tree->nil->parent = tree->nil;
  tree->nil->left = tree->nil;
  tree->nil->right = tree->nil;
  tree->nil->color = black;
  tree->nil->key = -2;

  tree->root = tree->nil;
  tree->bh = 0;

  return tree;
}

void rb_leftRotate(struct rb_tree* T, struct rb_node* x) {
  struct rb_node* y;
  if(x->right == T->nil) return; 
  y = x->right;
  x->right = y->left;
  y->parent = x->parent;
  if (y->left != T->nil) {
    y->left->parent = x;
  }
  if(x->parent == T->nil){
  	T->root = y;
  }else{
   if (x == x->parent->left) {
    x->parent->left = y;
  } 
  else {
    x->parent->right = y;
  }
  }
  y->left = x;
  x->parent = y;
}

void rb_rightRotate(struct rb_tree* T, struct rb_node* x) {
  struct rb_node* y;
  if(x->left == T->nil) return;
  y = x->left;
  x->left = y->right;
  y->parent = x->parent;
  
  if(y->right!= T->nil){
  	y->right->parent =x;
  }
  if (x->parent == T->nil) {
    T->root = y;
  }else{
	if (x == x->parent->right) {
    	x->parent->right = y;
  	}
  	else {
    	x->parent->left = y;
  	}
  }
  y->right = x;
  x->parent = y;
}

struct rb_node* rb_insertFixup(struct rb_tree* T, struct rb_node* z) {
  struct rb_node* y;
  while (z->parent->color == red) {
    if (z->parent == z->parent->parent->left) { /* non-mirrored cases */
      y = z->parent->parent->right;
      if (y->color == red) {                    /* case 1 */
        z->parent->color = black;
        y->color = black;
        z->parent->parent->color = red;
        z = z->parent->parent;
      } else {
        if (z == z->parent->right) {            /* case 2 */
          z = z->parent;
          rb_leftRotate(T, z);
        }
        z->parent->color = black;               /* case 3 */
        z->parent->parent->color = red;
        rb_rightRotate(T, z->parent->parent);
      }
    } else {                                    /* mirrored cases */
      y = z->parent->parent->left;
      if (y->color == red) {                    /* case 1m */
        z->parent->color = black;
        y->color = black;
        z->parent->parent->color = red;
        z = z->parent->parent;
      } else {
        if (z == z->parent->left) {             /* case 2m */
          z = z->parent;
          rb_rightRotate(T, z);
        }
        z->parent->color = black;               /* case 3m */
        z->parent->parent->color = red;
        rb_leftRotate(T, z->parent->parent);
      }
    }
  }
  if (T->root->color == red) {
    T->bh += 1;
  }
  T->root->color = black;
}

void rb_insert(struct rb_tree* T, int key) {
  struct rb_node *oneDelayed = T->nil;
  struct rb_node *insertPlace = T->root;
  struct rb_node *nodeToInsert =
    (struct rb_node*) malloc(sizeof(struct rb_node));
  nodeToInsert->key = key;
  nodeToInsert->color = red;

  nodeToInsert->left= T->nil;
  nodeToInsert->right= T->nil;
  nodeToInsert->parent= T->nil;
  while (insertPlace != T->nil) {
    oneDelayed = insertPlace;
    if (nodeToInsert->key < insertPlace->key) {
      insertPlace = insertPlace->left;
    }
    else {
      insertPlace = insertPlace->right;
    }
  }

  if (oneDelayed == T->nil) {
    T->root = nodeToInsert;
  }
  else if (oneDelayed->key < nodeToInsert->key) {
    oneDelayed->right = nodeToInsert;
    nodeToInsert->parent = oneDelayed;
  }
  else {
    oneDelayed->left = nodeToInsert;
    nodeToInsert->parent = oneDelayed;
  }
  rb_insertFixup(T, nodeToInsert);
}

struct rb_node* rb_search(struct rb_tree* tree, int q) {
    struct rb_node* x = tree->root;

    if (x == tree->nil)
        return x;
    while (x->key != q) {
        if (q < x->key)
            x = x->left;
        else
            x = x->right;
        if (x == tree->nil)
            return x;
    }
    return x;
}

void rb_printRecursive(struct rb_node *root, struct rb_tree *tree) {
  if (root == tree->nil) {
    return;
  }
  rb_printRecursive(root->left, tree);
  if (root->left != tree->nil) {
    printf(" \"%d (%s)\" -- \"%d (%s)\"\n", root->key,
           (root->color==red?"RED":"BLACK"),
           root->left->key, (root->left->color==red?"RED":"BLACK"));
  }
  rb_printRecursive(root->right, tree);
  if (root->right != tree->nil) {
    printf(" \"%d (%s)\" -- \"%d (%s)\"\n", root->key,
           (root->color==red?"RED":"BLACK"),
           root->right->key, (root->right->color==red?"RED":"BLACK"));
  }
}

void rb_print(struct rb_tree *tree) {
  printf("graph g {\n");
  rb_printRecursive(tree->root, tree);
  printf("}\n");
}

int main(int argc, char **argv) {
  struct rb_tree *T;
  T = rb_initialize();

  rb_insert(T, 5);
  rb_insert(T, 90);
  rb_insert(T, 20);
  rb_print(T);
  rb_rightRotate(T, rb_search(T, 20));
  rb_print(T);
  rb_leftRotate(T, rb_search(T, 5));
  rb_print(T); 
  rb_insert(T, 60);
  rb_insert(T, 30);
  rb_print(T);
  rb_rightRotate(T, rb_search(T, 90));
  rb_print(T);
  return 0;
}