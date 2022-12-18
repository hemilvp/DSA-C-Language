#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define size 100

typedef struct stack
{
    char arr[size];
    int top;
} S;

void createstack(S *s)
{
    s->top = -1;
}

int isEmpty(S *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(S *s)
{
    if (s->top == size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(S *s, char element)
{
    if (isFull(s))
    {
        printf("Stack is Full\n");
    }
    else
    {
        s->top++;
        s->arr[s->top] = element;
    }
}

char pop(S *s)
{
    char x;
    if (isEmpty(s))
    {
        printf("Stack is Empty\n");
    }
    else
    {
        x = s->arr[s->top];
        s->top--;
    }
    return x;
}

int priority_input(char x)
{
    if (x == '+' ||x == '-')
        return 1;
    else if (x == '*' ||x == '/')
        return 2;
    // else if (x == '#')
    //     return 0;
    else if (isalnum(x))
        return 4;
    return 0;
}

char * postfix(S *s,char * infix)
{
    int n = strlen(infix);
    int j = 0;
    char * postfix = (char *)malloc((n)*sizeof(char));
    for (int i = 0; i < n; i++)
    {
        if (priority_input(infix[i]) > priority_input(s->arr[s->top]))
        {
            push(s,infix[i]);
        }
        else if (priority_input(infix[i]) <= priority_input(s->arr[s->top]))
        {
        while(priority_input(infix[i]) <= priority_input(s->arr[s->top]))
        {
            postfix[j++] = pop(s);
        }
        push(s,infix[i]);
        }


    }
    while (s->top != 0)
    {
        postfix[j++] = pop(s);
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    S *s;
    s = (S *)malloc(sizeof(S));
    createstack(s);
    push(s,'#');

    char *infix = (char *)malloc(size*sizeof(char));
    scanf("%s",infix);
    char *postfi = postfix(s,infix);
    printf("%s",postfi);

    return 0;
}