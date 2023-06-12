#include <stdio.h>

int findPrimes(int num1, int num2) {
  printf("The Prime Numbers in (%d,%d) are:\n", num1, num2);

  for (int i = num1 + 1; i < num2; ++i) {
    int isPrime = 1;

    for (int j = 2; j <= i / 2; ++j) {
      if (i % j == 0) {
        isPrime = 0;
        break;
      }
    }

    if (isPrime == 1) {
      printf("%d\n", i);
    }
  }

  return 0;
}

int main(int argc, char *argv[]) {
  findPrimes(0, 50000);
  return 1;
}
