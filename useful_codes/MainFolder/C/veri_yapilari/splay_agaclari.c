#include <stdio.h>
#include <stdlib.h>

#define SN struct node

SN {
  int data;
  SN *left;
  SN *right;
};

// Alinan veri ile yeni bir dugum olusturma
SN *new_node(int data) {
  SN *node = malloc(sizeof(SN));
  node->data = data;
  node->left = node->right = NULL;
  return node;
}

SN *insert(SN *node, int data) {
  if (node == NULL)
    return new_node(data);
  if (data < node->data)
    node->left = insert(node->left, data);
  else if (data > node->data)
    node->right = insert(node->right, data);
  return node;
}

// Right rotate
SN *right_rotate(SN *x) {
  SN *y = x->left;

  x->left = y->right;
  y->right = x;
  return y;
}

// Left Rotate
SN *left_rotate(SN *x) {
  SN *y = x->right;

  x->right = y->left;
  y->left = x;
  return y;
}

// Splay işlemi
SN *splay(SN *root, int data) {
  if (root == NULL || root->data == data)
    return root;

  if (root->data > data) {
    // Aranan veri sola kayıyor
    if (root->left == NULL)
      return root;

    if (root->left->data > data) {
      // Zig-Zig dönüşü
      root->left->left = splay(root->left->left, data);
      root = right_rotate(root);
    } else if (root->left->data < data) {
      // Zig-Zag dönüşü
      root->left->right = splay(root->left->right, data);
      if (root->left->right != NULL)
        root->left = left_rotate(root->left);
    }

    return (root->left == NULL) ? root : right_rotate(root);
  } else {
    // Aranan veri sağa kayıyor
    if (root->right == NULL)
      return root;

    if (root->right->data > data) {
      // Zag-Zig dönüşü
      root->right->left = splay(root->right->left, data);
      if (root->right->left != NULL)
        root->right = right_rotate(root->right);
    } else if (root->right->data < data) {
      // Zag-Zag dönüşü
      root->right->right = splay(root->right->right, data);
      root = left_rotate(root);
    }

    return (root->right == NULL) ? root : left_rotate(root);
  }
}
