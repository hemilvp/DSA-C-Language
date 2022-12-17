#include <stdio.h>
#include <stdlib.h>
#include<string.h>
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
        return -1;
    }
    else
    {
        return 0;
    }
}

int isFull(S *s)
{
    if (s->top == 9)
    {
        return -1;
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

void pop(S *s)
{
    if (isEmpty(s))
    {
        printf("Stack is Empty\n");
    }
    else
    {
        s->top--;
    }
}

void paranthesis_match(S *s, char exp[])
{
    for (int i = 0; i < strlen(exp); i++)
    {
        if (exp[i] == '(')
        {
            push(s,'(');
        }
        else if(exp[i] == ')')
        {
            pop(s);
        }
    }
    if (isEmpty(s))
    {
        printf("paranthesis match!\n");
    }
    else 
    {
        printf("paranthesis not match!\n");
    }
    
}

int main ()
{
    S *s = (S *)malloc(sizeof(S));
    char exp[100];
    scanf("%s",exp);
    createstack(s);
    paranthesis_match(s,exp);
}