#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node *left;
  struct node *right;
};
int dizi[100];
struct node *createNode(int key) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  if (newNode == NULL) {
    printf("Bellek tahsisi basarisiz.\n");
    exit(1);
  }
  newNode->key = key;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

void preorder(struct node *root) {
  if (root != NULL) {
    printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
  }
}

void inorder(struct node *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
  }
}

void postorder(struct node *root) {
  if (root != NULL) {
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->key);
  }
}

void levelOrder(struct node *root) {
  if (root == NULL)
    return;

  struct node **queue = (struct node **)malloc(100 * sizeof(struct node *));
  int front = 0, rear = 0;
  queue[rear] = root;
  while (front <= rear) {
    struct node *current = queue[front++];
    printf("%d ", current->key);
    if (current->left != NULL)
      queue[++rear] = current->left;
    if (current->right != NULL)
      queue[++rear] = current->right;
  }
  free(queue);
}

int main() {
  struct node *root = createNode(1);
  root->left = createNode(2);
  root->right = createNode(3);
  root->left->left = createNode(4);
  root->left->right = createNode(5);
  root->right->left = createNode(6);
  root->right->right = createNode(7);

  printf("Preorder Dolaşma: ");
  preorder(root);
  printf("\n");

  printf("Inorder Dolaşma: ");
  inorder(root);
  printf("\n");

  printf("Postorder Dolaşma: ");
  postorder(root);
  printf("\n");

  printf("Level Order Dolaşma: ");
  levelOrder(root);
  printf("\n");

  return 0;
}
