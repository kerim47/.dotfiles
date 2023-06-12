#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char item) {
    if(top >= MAX_SIZE-1) {
        printf("\nHata: Yigin dolu!");
        exit(1);
    }
    else {
        top = top+1;
        stack[top] = item;
    }
}

char pop() {
    char item;
    if(top < 0) {
        printf("\nHata: Yigin bos!");
        exit(1);
    }
    else {
        item = stack[top];
        top = top-1;
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
    printf("Lutfen bir ifade girin: ");
    scanf("%s", expression);
    len = strlen(expression);
    for(i=0; i<len; i++) {
        if(is_opening_symbol(expression[i])) {
            push(expression[i]);
        }
        else if(is_closing_symbol(expression[i])) {
            if(top < 0) {
                printf("\nHata: Yigin bos!");
                error_flag = 1;
                break;
            }
            else {
                char popped_item = pop();
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
    if(top >= 0 && error_flag == 0) {
        printf("\nHata: Parantez acilma hatasi!");
    }
    else if(top < 0 && error_flag == 0) {
        printf("\nParantezler dengeli.");
    }
    return 0;
}

