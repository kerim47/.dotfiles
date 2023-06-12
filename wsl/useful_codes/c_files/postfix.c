#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

int stack[MAX_STACK_SIZE];
int top = -1;

void push(int value) {
  if (top >= MAX_STACK_SIZE - 1) {
    printf("Stack overflow\n");
    exit(EXIT_FAILURE);
  }
  stack[++top] = value;
}

int pop() {
  if (top < 0) {
    printf("Stack underflow\n");
    exit(EXIT_FAILURE);
  }
  return stack[top--];
}

int evaluate_postfix(char *expression) {
  int i = 0;
  while (expression[i] != '\0') {
    if (isdigit(expression[i])) {
      int operand = 0;
      while (isdigit(expression[i])) {
        operand = operand * 10 + (expression[i] - '0');
        i++;
      }
      push(operand);
    } else if (expression[i] == '+' || expression[i] == '-' ||
               expression[i] == '*' || expression[i] == '/') {
      int operand1 = pop();
      int operand2 = pop();
      switch (expression[i]) {
      case '+':
        push(operand2 + operand1);
        break;
      case '-':
        push(operand2 - operand1);
        break;
      case '*':
        push(operand2 * operand1);
        break;
      case '/':
        push(operand2 / operand1);
        break;
      }
      i++;
    } else {
      i++;
    }
  }
  int result = pop();
  if (top != -1) {
    printf("Invalid expression\n");
    exit(EXIT_FAILURE);
  }
  return result;
}

int main() {
  char expression[100];
  printf("Enter postfix expression: ");
  fgets(expression, 100, stdin);
  int result = evaluate_postfix(expression);
  printf("Result: %d\n", result);
  return 0;
}

// aşağıdaki ağaç yapısını oluşturacak kodu yaz.
// ├──  7 3 2
// ├── +
// │   └── 3  2
// │          ├── 5
// ├── *
// │   └── 7 5
// │         └── 35
// ├── +
// │   └── 35 2
// │          └── 37
