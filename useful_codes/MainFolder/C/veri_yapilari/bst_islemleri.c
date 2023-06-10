#include <stdio.h>
#include <stdlib.h>

#define SN struct node
// Bst islemleri Tanimlama
SN {
  int key;
  SN *left;
  SN *right;
};

// Arama
SN *search(SN *root, int key) {
  if (root == NULL || root->key == key)
    return root;
  else if (key > (root->key))
    return search(root->right, key);
  else
    return search(root->left, key);
}

// Get Min Value

SN *min_value_node(SN *node) {
  SN *current = node;
  while (current && current->left != NULL)
    current = current->left;
  return current;
}

// Get Max Value

SN *max_value_node(SN *node) {
  SN *current = node;
  while (current && current->right != NULL)
    current = current->right;
  return current;
}

// Create New Node
SN *new_node(int item) {
  SN *temp = malloc(sizeof(SN));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

// Insert Node

SN *insert(SN *node, int key) {
  if (node == NULL)
    return new_node(key);
  if (key < node->key)
    node->left = insert(node->left, key);
  else if (key > node->key)
    node->right = insert(node->right, key);
}

// inorder
void inorder(SN *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
  }
}

SN *delete_node(SN *root, int key) {
  if (root == NULL)
    return root;
  if (key < (root->key))
    root->left = delete_node(root->left, key);
  else if (key > (root->key))
    root->right = delete_node(root->right, key);
  else {
    if (root->left == NULL) {
      SN *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      SN *temp = root->left;
      free(root);
      return temp;
    }

    SN *temp = min_value_node(root->right);
    root->key = temp->key;
    root->right = delete_node(root->right, temp->key);
  }
  return root;
}

int main() {
  //      70
  //    /   \
   //   40    82
  //  / \   /  \
   // 15 50 75   90
  SN *root = NULL;
  root = insert(root, 70);
  insert(root, 40);
  insert(root, 15);
  insert(root, 50);
  insert(root, 82);
  insert(root, 75);
  insert(root, 90);

  inorder(root);
  printf("\n");
  delete_node(root, 70);
  inorder(root);

  return 1;
}
