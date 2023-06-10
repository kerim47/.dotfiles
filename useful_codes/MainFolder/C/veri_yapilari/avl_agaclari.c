#include <stdio.h>
#include <stdlib.h>
#define SN struct node

SN {
  SN *left;
  SN *right;
  int data;
  int height;
};

// Max
int max(int a, int b) { return (a > b) ? a : b; }

// Height Files
int height(SN *N) {
  if (N == NULL)
    return 0;
  return (1 + max(height(N->left), height(N->right)));
}

// Create new node
SN *new_node(int data) {
  SN *node = malloc(sizeof(SN));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  node->height = 0;
  return node;
}

// Right rotate
SN *right_rotate(SN *y) {
  SN *x = y->left;
  SN *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = height(y);
  x->height = height(x);
  return x;
}

// Left Rotate
SN *left_rotate(SN *y) {
  SN *x = y->right;
  SN *T2 = x->left;

  y->left = x;
  x->right = T2;

  x->height = height(x);
  y->height = height(y);
  return y;
}

// get balance
int get_balance(SN *N) {
  if (N == NULL)
    return 0;
  return height(N->left) - height(N->right);
}

// insert node
SN *insert(SN *node, int data) {
  if (node == NULL)
    return new_node(data);
  if (data < node->data)
    node->left = insert(node->left, data);
  else if (data > node->data)
    node->right = insert(node->right, data);
  else
    return node;
  node->height = height(node);

  int balance = get_balance(node);
  if (balance > 1 && data < node->left->data)
    return right_rotate(node);
  if (balance < -1 && data > node->right->data)
    return left_rotate(node);

  if (balance > 1 && data > node->left->data) {
    node->left = left_rotate(node->left);
    return right_rotate(node);
  }
  if (balance < -1 && data > node->right->data) {
    node->left = left_rotate(node->right);
    return left_rotate(node);
  }
  return node;
}

// Delete node
SN *delete_node(SN *root, int data) {
  if (root == NULL)
    return root;
  if (data < root->data)
    root->left = delete_node(root->left, data);
  else if (data > root->data)
    root->right = delete_node(root->right, data);
  else {
    root->height = 1 + max(height(root->left), height(root->right));
    int balance = get_balance(root);
    if (balance > 1 && get_balance(root->left) >= 0)
      return right_rotate(root);
    if (balance > 1 && get_balance(root->left) < 0) {
      root->left = left_rotate(root->left);
      return right_rotate(root);
    }

    if (balance > -1 && get_balance(root->right) <= 0)
      return left_rotate(root);
    if (balance > 1 && get_balance(root->right) < 0) {
      root->right = right_rotate(root->right);
      return left_rotate(root);
    }
    return root;
  }
}

// Pre order function
void pre_order(SN *root) {
  if (root) {
    printf("%d ", root->data);
    pre_order(root->left);
    pre_order(root->right);
  }
}

int main() {

  SN *root = NULL;
  while (1) {
    int secim, data;
    printf(
        "\n1-Agaca Veri Ekle\n2-Veri Sil\n3-Verileri preorder sekilde goster");
    printf("\nSecim Yapiniz : ");
    scanf("%d", &secim);
    switch (secim) {
    case 1:
      printf("Veriyi Girin : ");
      scanf("%d", &data);
      root = insert(root, data);
      break;
    case 2:
      printf("Silinecek veriyi Girin : ");
      scanf("%d", &data);
      delete_node(root, data);
      if (root) {
        root = NULL;
      }
      break;
    case 3:
      if (root) {
        printf("Olusturulan AVL agacinin preorder dolasimi \n");
        pre_order(root);
      } else
        printf("Agac Bos");
      break;
    }
    printf("\n");
    getchar();
  }
  return 1;
}
