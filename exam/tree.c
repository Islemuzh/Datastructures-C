#include <stdlib.h>
#include <stdio.h>

struct tree {
  struct node* root;
};

struct node {
  int val;
  struct node* left;
  struct node* right;
};

struct tree* init() {
  struct tree* t = malloc(sizeof(struct tree));
  t->root = NULL;
  return t;
}

void insert(struct tree* t, int val) {
  struct node* new;
  struct node* prev;
  struct node* curr;

  new = malloc(sizeof(struct node));
  new->val = val;
  new->left = NULL;
  new->right = NULL;
  prev = NULL;
  curr = t->root;
  while (curr != NULL) {
    prev = curr;
    if (val < curr->val)
      curr = curr->left;
    else
      curr = curr->right;
  }
  if (prev == NULL) {
    t->root = new;
  } else if (val < prev->val) {
    prev->left = new;
  } else {
    prev->right = new;
  }
}

struct node* search(struct tree* t, int val) {
  struct node* curr = t->root;
  while (curr != NULL && curr->val != val) {
    if (val < curr->val)
      curr = curr->left;
    else
      curr = curr->right;
  }
  return curr;
}

void delete(struct tree* t, int val) {
  struct node* x = search(t, val);
  if (x == NULL)
    return;
  struct node* u = t->root;
  struct node* v = NULL;
  while (u != x) {
    v = u;
    if (x->val < u->val)
      u = u->left;
    else
      u = u->right;
  }
  if (u->right == NULL) {
    if (v == NULL)
      t->root = u->left;
    else if (v->left == u)
      v->left = u->left;
    else
      v->right = u->right;
  } else if (u->left == NULL) {
    if (v == NULL)
      t->root = u->right;
    else if (v->left == NULL)
      v->left = u->right;
    else
      v->right = u->right;
  } else {
    struct node* p = x->left;
    struct node* q = p;
    while (p->right != NULL) {
      q = p;
      p = p->right;
    }
    if (v == NULL)
      t->root = p;
    else if (v->left == u)
      v->left = p;
    else
      v->right = p;
    p->right = u->right;
    if (q != p) {
      q->right = p->left;
      p->left = u->left;
    }
  }
}

void print_inorder(struct node* x) {
  if (x != NULL) {
    print_inorder(x->left);
    printf("%d ", x->val);
    print_inorder(x->right);
  }
}

void print(struct tree* t) {
  print_inorder(t->root);
  printf("\n");
}

void main() {
  int r1, r2;
  struct tree* t = init();
  printf("Inserting: 4, 2, 3, 8, 6, 7, 9, 12, 1\n");
  insert(t, 4);
  insert(t, 2);
  insert(t, 3);
  insert(t, 8);
  insert(t, 6);
  insert(t, 7);
  insert(t, 9);
  insert(t, 12);
  insert(t, 1);
  print(t);
  printf("Deleting: 4, 7, 2\n");
  delete(t, 4);
  delete(t, 7);
  delete(t, 2);
  print(t);
}