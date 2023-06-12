#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Ağaç düğümünün yapısı
typedef struct Node {
  int data;
  struct Node *left;
  struct Node *right;
} Node;

// Yeni bir ağaç düğümü oluşturma
Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

// Ağaca yeni bir düğüm ekleme
Node *insert(Node *root, int data) {
  if (root == NULL) {
    return createNode(data);
  }

  if (data < root->data) {
    root->left = insert(root->left, data);
  } else if (data > root->data) {
    root->right = insert(root->right, data);
  }

  return root;
}

// Ağaçta arama işlemi
Node *search(Node *root, int key) {
  if (root == NULL || root->data == key) {
    return root;
  }

  if (key < root->data) {
    return search(root->left, key);
  } else {
    return search(root->right, key);
  }
}

// Ağacı inorder (LNR) şeklinde gezerek yazdırma
void inorderTraversal(Node *root) {
  if (root != NULL) {
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
  }
}

int main() {
  Node *root = NULL;
  int i, data;

  srand(time(NULL));
  // Rastgele 1000 değerli bir ağaç oluşturma
  for (i = 0; i < 1000; i++) {
    data = rand() % 1000; // 0-9999 arası rastgele değer
    root = insert(root, data);
  }

  printf("Agaçtaki elemanlar: ");
  inorderTraversal(root);
  printf("\n");

  int searchKey = 42;
  Node *result = search(root, searchKey);

  if (result == NULL) {
    printf("%d degeri agacda bulunamadi.\n", searchKey);
  } else {
    printf("%d degeri agacta bulundu.\n", searchKey);
  }

  return 0;
}

