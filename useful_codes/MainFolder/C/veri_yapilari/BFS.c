#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 6

struct node {
  int data;
  struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

struct node *createNode(int data) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

bool isEmpty() { return (front == NULL); }

void enqueue(int data) {
  struct node *newNode = createNode(data);

  if (isEmpty()) {
    front = rear = newNode;
  } else {
    rear->next = newNode;
    rear = newNode;
  }
}

int dequeue() {
  if (isEmpty()) {
    printf("Queue is empty!\n");
    return -1;
  }

  struct node *temp = front;
  int data = temp->data;

  front = front->next;
  if (front == NULL)
    rear = NULL;

  free(temp);

  return data;
}

void bfs(int startNode, int adjacencyList[MAX_NODES][MAX_NODES], int numNodes) {
  bool visited[MAX_NODES] = {false};

  visited[startNode] = true;
  enqueue(startNode);

  printf("BFS traversal: ");

  while (!isEmpty()) {
    int currentNode = dequeue();
    printf("%d ", currentNode);

    for (int i = 0; i < numNodes; i++) {
      if (adjacencyList[currentNode][i] == 1 && !visited[i]) {
        visited[i] = true;
        enqueue(i);
      }
    }
  }
}

int main() {
  int adjacencyList[6][6] = {
      {0, 1, 1, 0, 0, 0}, {1, 0, 0, 1, 0, 0}, {1, 0, 0, 1, 0, 0},
      {0, 1, 1, 0, 1, 0}, {0, 0, 0, 1, 0, 1}, {0, 0, 0, 0, 1, 0},
  };
  int startNode = 2;
  int numNodes = 6;

  bfs(startNode, adjacencyList, numNodes);

  return 0;
}
