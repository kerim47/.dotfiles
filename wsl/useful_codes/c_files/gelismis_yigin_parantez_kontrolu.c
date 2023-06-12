#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define STACK_INCREMENT 10
#define MAX_SIZE 100

struct Stack {
    char *data;
    int size;
    int top;
};

void initialize_stack(struct Stack *stack) {
    stack->size = STACK_INCREMENT;
    stack->data = (char *) malloc(stack->size * sizeof(char));
    stack->top = -1;
}

void resize_stack(struct Stack *stack) {
    stack->size += STACK_INCREMENT;
    stack->data = (char *) realloc(stack->data, stack->size * sizeof(char));
}

void push(struct Stack *stack, char item) {
    if(stack->top >= stack->size-1) {
        resize_stack(stack);
    }
    stack->top++;
    stack->data[stack->top] = item;
}

char pop(struct Stack *stack) {
    char item;
    if(stack->top < 0) {
        printf("\nHata: Yigin bos!");
        exit(1);
    }
    else {
        item = stack->data[stack->top];
        stack->top--;
        return item;
    }
}

int is_opening_symbol(char symbol) {
    if(symbol == '(' || symbol == '[' || symbol == '{') {
        return 1;
    }
    else {
        return 0;
    }
}

int is_closing_symbol(char symbol) {
    if(symbol == ')' || symbol == ']' || symbol == '}') {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    char expression[MAX_SIZE];
    int i, len, error_flag = 0;
    struct Stack stack;
    initialize_stack(&stack);
    printf("Lutfen bir ifade girin: ");
    scanf("%s", expression);
    len = strlen(expression);
    for(i=0; i<len; i++) {
        if(is_opening_symbol(expression[i])) {
            push(&stack, expression[i]);
        }
        else if(is_closing_symbol(expression[i])) {
            if(stack.top < 0) {
                printf("\nHata: Yigin bos!");
                error_flag = 1;
                break;
            }
            else {
                char popped_item = pop(&stack);
                if(expression[i] == ')' && popped_item != '(') {
                    printf("\nHata: Parantez kapatma hatasi!");
                    error_flag = 1;
                    break;
                }
                else if(expression[i] == ']' && popped_item != '[') {
                    printf("\nHata: Koseli parantez kapatma hatasi!");
                    error_flag = 1;
                    break;
                }
                else if(expression[i] == '}' && popped_item != '{') {
                    printf("\nHata: Suslu parantez kapatma hatasi!");
                    error_flag = 1;
                    break;
                }
            }
        }
    }
    if(stack.top >= 0 && error_flag == 0) {
        printf("\nHata: Parantez acilma hatasi!");
    }
    else if(stack.top < 0 && error_flag == 0) {
        printf("\nParantezler dengeli.");
    }
    return 0;
}

