#include <stdbool.h>
#include <stdio.h>

#define MAX_NODES 9

struct Node {
  char label;
  int degree;
  int color;
};

void welshPowellColoring(struct Node nodes[MAX_NODES],
                         int adjacencyMatrix[MAX_NODES][MAX_NODES],
                         int numNodes) {
  bool availableColors[MAX_NODES];
  for (int i = 0; i < numNodes; i++) {
    nodes[i].color = 0;
    availableColors[i] = true;
  }

  nodes[0].color = 1;

  for (int i = 1; i < numNodes; i++) {
    struct Node currentNode = nodes[i];

    for (int j = 0; j < numNodes; j++) {
      if (adjacencyMatrix[i][j] && nodes[j].color != 0) {
        availableColors[nodes[j].color - 1] = false;
      }
    }

    int color;
    for (color = 0; color < numNodes; color++) {
      if (availableColors[color]) {
        break;
      }
    }

    currentNode.color = color + 1;

    for (int j = 0; j < numNodes; j++) {
      if (adjacencyMatrix[i][j] && nodes[j].color != 0) {
        availableColors[nodes[j].color - 1] = true;
      }
    }
  }
}

int main() {
  struct Node nodes[MAX_NODES] = {
      {'D', 6, 0}, {'H', 4, 0}, {'G', 3, 0}, {'F', 3, 0}, {'C', 3, 0},
      {'A', 2, 0}, {'B', 2, 0}, {'E', 2, 0}, {'I', 1, 0},
  };

  int adjacencyMatrix[MAX_NODES][MAX_NODES] = {
      {0, 0, 0, 1, 1, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0, 0},
      {0, 0, 0, 1, 0, 0, 0, 0, 0}, {1, 1, 1, 0, 0, 0, 0, 0, 0},
      {1, 0, 0, 0, 0, 1, 1, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 1, 0},
      {0, 0, 0, 0, 1, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 1, 1, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0},
  };

  int numNodes = MAX_NODES;

  welshPowellColoring(nodes, adjacencyMatrix, numNodes);

  printf("Renklendirme:\n");
  for (int i = 0; i < numNodes; i++) {
    printf("%c -> Renk: %d\n", nodes[i].label, nodes[i].color);
  }

  int chromaticNumber = 0;
  for (int i = 0; i < numNodes; i++) {
    if (nodes[i].color > chromaticNumber) {
      chromaticNumber = nodes[i].color;
    }
  }

  printf("Kromatik Sayısı: %d\n", chromaticNumber);

  return 0;
}

