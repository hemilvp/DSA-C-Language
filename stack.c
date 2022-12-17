#include <stdio.h>
#include <stdlib.h>
#define size 100

typedef struct stack
{
    int arr[size];
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

void push(S *s, int element)
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
        printf("Poped element is %d : \n", s->arr[s->top]);
        // free(s->top);
        s->top--;
    }
}

void printstack(S *s)
{
    printf("Stack: ");
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int main()
{
    S *s;
    int element, num;
    s = (S *)malloc(sizeof(S));
    createstack(s);

    printf("[1] for push.\n");
    printf("[2] for pop.\n");
    printf("[3] for display the stack.\n");
    scanf("%d", &num);

    while (num != 0)
    {
        switch (num)
        {
        case 1:
            printf("Enter the element that you want to push.\n");
            scanf("%d", &element);
            push(s, element);
            break;

        case 2:
            pop(s);
            break;

        case 3:
            printstack(s);
            break;
        }

        printf("If you want to continue than type \n");
        printf("[1] for push.\n");
        printf("[2] for pop.\n");
        printf("[3] for display the stack.\n");
        printf("[0] for close the program.\n");
        scanf("%d", &num);
    }
    free(s);
    // push(s,2); // push(s,3); // push(s,4); // push(s,5); // printstack(s); // pop(s); // pop(s); // printstack(s);
    return 0;
}
