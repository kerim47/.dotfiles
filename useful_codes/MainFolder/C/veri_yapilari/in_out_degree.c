#include <math.h>
#include <stdio.h>

#define boyut 4

int M[boyut][boyut];

int in_degree(int index) {
  int i = 0;
  int count = 0;
  for (; i < boyut; i++)
    if (M[i][index] == 1)
      count++;
  return count;
}

int out_degree(int index) {
  int i = 0;
  int count = 0;
  for (; i < boyut; i++)
    if (M[index][i] == 1)
      count++;
  return count;
}

int main() {

  int node_number[boyut];
  int i, j;

  i = j = 0;

  for (; i < boyut; i++) {
    printf("%d. dugum numarasini giriniz : ", i + 1);
    scanf("%d", &node_number[i]);
  }
  printf("\n");

  for (i = 0; i < boyut; i++) {
    for (j = 0; j < boyut; j++) {
      printf("%d numarali dugum ile %d numarali dugum arasinda kenar var mi "
             "(1|0) : ",
             node_number[i], node_number[j]);
      scanf("%d", &M[i][j]);
    }
    printf("\n");
  }

  printf("Komsu Matrisi : \n");

  for (i = 0; i < boyut; i++) {
    for (j = 0; j < boyut; j++) {
      printf("%d", M[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  for (i = 0; i < boyut; i++) {
    printf("\n%d. numarali dugum InDegree sayisi: %d\n", node_number[i],
           in_degree(i));
  }

  printf("\n");

  for (i = 0; i < boyut; i++) {
    printf("\n%d. numarali dugum OutDegree sayisi: %d\n", node_number[i],
           out_degree(i));
  }
  return 0;
}
