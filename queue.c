#include<stdio.h>
#include<stdlib.h>
#define size 100

struct queue
{
    int arr[size];
    int r;
    int f;
};

int isEmpty(struct queue * q)
{
    if (q->f==-1 && q->r==-1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct queue * q)
{
    if (q->r == size-1)
    {
        return 1;
    }
    return 0;
}

void create_queue(struct queue * q)
{
    q->r = -1;
    q->f = -1;
}

void enqueue(struct queue * q)
{
    int element;
    scanf("%d",&element);   
    if(isFull(q))
    { 
        printf("The queue is Full.\n");
    }
    else if (q->r == -1 && q->f == -1)
    {
        q->r++;
        q->f++;
        q->arr[q->r] = element;
    }
    
    else
    {
        q->r++;
        q->arr[q->r] = element;
    }
}

void deuqueue(struct queue * q)
{
    if (isEmpty(q))
    {
        printf("The queue is Empty.\n");
    }
    else
    {
        printf("The deleted element is %d.\n",q->arr[q->f]);
        q->f++;
    }
}

void display(struct queue * q)
{
    printf("The queue is : ");
    for (int i = q->f; i <= q->r; i++)
    {
        printf("%d ",q->arr[i]);
    }
    printf("\n");
}
int main()
{
    struct queue * q = (struct queue *)malloc(sizeof(struct queue));
    create_queue(q);
    int n = 1;
    while (n != 4)
    {
        
        printf("Enter any number from below list to perform any operation on queue.\n");
        printf("[1] for enqueue\n");
        printf("[2] for dequeue.\n");
        printf("[3] for display.\n"); 
        printf("[4] for exit.\n");
        scanf("%d",&n);

        switch (n)
        {
        case 1:
            enqueue(q);
            break;
        
        case 2:
            deuqueue(q);
            break;

        case 3: 
            display(q);
            break;
        }  
    }
return 0;
}