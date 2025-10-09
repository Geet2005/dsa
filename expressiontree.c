#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Structure for tree node
typedef struct node {
    char data;
    struct node *left, *right;
} Node;

// Stack for tree nodes
Node* stack[MAX];
int top = -1;

// Stack operations
void push(Node* n) {
    stack[++top] = n;
}

Node* pop() {
    return stack[top--];
}

// Create a new node
Node* newNode(char data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

// Check if operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Build expression tree from postfix expression
Node* constructTree(char postfix[]) {
    Node *t, *t1, *t2;
    for (int i = 0; postfix[i] != '\0'; i++) {
        // If operand, create node and push
        if (isalnum(postfix[i])) {
            t = newNode(postfix[i]);
            push(t);
        }
        // If operator, pop two nodes, make them children
        else if (isOperator(postfix[i])) {
            t = newNode(postfix[i]);
            t1 = pop();
            t2 = pop();
            t->right = t1;
            t->left = t2;
            push(t);
        }
    }
    // Final node is root
    t = pop();
    return t;
}

// Recursive traversals
void prefix(Node* root) {
    if (root) {
        printf("%c", root->data);
        prefix(root->left);
        prefix(root->right);
    }
}

void postfix(Node* root) {
    if (root) {
        postfix(root->left);
        postfix(root->right);
        printf("%c", root->data);
    }
}

// Function to convert infix to postfix (for simplicity)
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    char stack[MAX];
    int top = -1, k = 0;
    for (int i = 0; infix[i]; i++) {
        if (isalnum(infix[i])) {
            postfix[k++] = infix[i];
        } else if (infix[i] == '(') {
            stack[++top] = infix[i];
        } else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[k++] = stack[top--];
            top--;
        } else { // operator
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i]))
                postfix[k++] = stack[top--];
            stack[++top] = infix[i];
        }
    }
    while (top != -1)
        postfix[k++] = stack[top--];
    postfix[k] = '\0';
}

int main() {
    char infix[MAX], postfixExp[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfixExp);
    printf("Postfix Expression: %s\n", postfixExp);

    Node* root = constructTree(postfixExp);

    printf("Prefix Expression: ");
    prefix(root);
    printf("\n");

    printf("Postfix Expression: ");
    postfix(root);
    printf("\n");

    return 0;
}