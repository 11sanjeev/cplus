/*#include<stdio.h>
#include<stdlib.h>

// Function to check if the given character is an operator
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// Function to convert infix expression to postfix
void infixToPostfix(char* infix, char* postfix) {
    char stack[100];
    int top = -1;
    int j = 0;

    for(int i = 0; infix[i] != '\0'; i++) {
        if(isOperator(infix[i])) {
            while(top != -1 && isOperator(stack[top]) && stack[top] >= infix[i]) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        } else {
            postfix[j++] = infix[i];
        }
    }

    while(top != -1) {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0';
}

int main() {
    char infix[100], postfix[100];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("The postfix expression is: %s\n", postfix);

    return 0;
}*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char item) {
    if(top >= MAX-1) {
        printf("\nStack Overflow.");
    } else {
        stack[++top] = item;
    }
}

char pop() {
    char item;
    if(top < 0) {
        printf("Stack Underflow.");
        exit(1);
    } else {
        item = stack[top--];
        return(item);
    }
}

int is_operator(char symbol) {
    if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-') {
        return 1;
    } else {
        return 0;
    }
}

void infix_to_prefix(char infix_exp[], char prefix_exp[]) {
    int i, j, k, pos;
    char item, x;
    push(')');
    strcat(infix_exp,"(");
    i=0;
    j=0;
    item=infix_exp[i];
    while(item != '\0') {
        if(item == ')') {
            pop();
            while((x = pop()) != '(') {
                prefix_exp[j] = x;
                j++;
            }
        } else if(is_operator(item) == 1) {
            x=pop();
            while(is_operator(x) == 1 && x!='(') {
                prefix_exp[j] = x;
                j++;
                x = pop();
            }
            push(x);
            push(item);
        } else if(item == '(') {
            push(item);
        } else { 
            prefix_exp[j++] = item;
        }
        i++;
        item = infix_exp[i];
    }
    
    prefix_exp[j]='\0';
    
    for(i=0,j=strlen(prefix_exp)-1;i<j;i++,j--) {
        pos=prefix_exp[i];
        prefix_exp[i]=prefix_exp[j];
        prefix_exp[j]=pos;
    }
}

int main() {
   char infix[MAX], prefix[MAX];
   printf("\nEnter Infix expression : ");
   gets(infix);
   infix_to_prefix(infix,prefix);
   printf("Prefix Expression: ");
   puts(prefix);
   return 0;
}

