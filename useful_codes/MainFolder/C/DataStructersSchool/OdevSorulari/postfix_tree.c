#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
};

void printTree(struct Node* root, int space)
{
    if (root == NULL)
        return;
    space += 10;
    printTree(root->right, space);
    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
    printTree(root->left, space);
}

int isOperator(char x)
{
    switch (x)
    {
    case '+':
    case '-':
    case '*':
    case '/':
        return 1;
    }
    return 0;
}

int evaluatePostfix(char* exp)
{
    int i;
    struct Node* t, * t1, * t2;
    int val;
    int len = strlen(exp);

    struct Stack* stack = createStack(len);

    for (i = 0; exp[i]; ++i)
    {
        if (isdigit(exp[i]))
            push(stack, exp[i] - '0');
        else if (isOperator(exp[i]))
        {
            t = newNode(exp[i]);
            t1 = pop(stack);
            t2 = pop(stack);

            t->right = t1;
            t->left = t2;

            val = evaluate(t);

            push(stack, val);
        }
    }
    return pop(stack);
}

struct Node* construct_tree(char* postfix)
{
    int i;
    struct Node* t, * t1, * t2;
    int len = strlen(postfix);
    struct Stack* stack = createStack(len);

    for (i = 0; postfix[i]; ++i)
    {
        if (isdigit(postfix[i]))
        {
            t = newNode(postfix[i] - '0');
            push(stack, t);
        }
        else if (isOperator(postfix[i]))
        {
            t = newNode(postfix[i]);
            t1 = pop(stack);
            t2 = pop(stack);

            t->right = t1;
            t->left = t2;

            push(stack, t);
        }
    }
    t = pop(stack);
    return t;
}

int main()
{
    char exp[] = "73+2*2+";
    struct Node* root = construct_tree(exp);
    printf("Ağaç Yapısı:\n\n");
    printTree(root, 0);
    printf("Sonuç: %d", evaluatePostfix(exp));
    return 0;
}
