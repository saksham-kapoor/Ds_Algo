#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    struct Node *prev;
    int data;
    struct Node *next;
} *first;


void create(int *A, int size)
{
    int i;
    struct Node *t,*last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->prev = NULL;
    first->data = A[0];
    first->next = NULL;
    last = first;
    for(i=1; i<size;i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->prev = last;
        t->next = NULL;
        last -> next = t;
        last = t;
    }
}

int length(struct Node *p)
{
    int count = 0;
    while(p)
    {
        count ++;
        p = p->next;
    }
    return count;
}

void display(struct Node *p)
{
    while(p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}


void insert(int val, int pos)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = first;
    int i;
    t->data = val;
    if(pos == 0) //insert before first
    {
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    } else 
    {
        if(!(pos <= length(first)))
        {   
            printf("Invalid Position \n");
            return;
        }
    
        for(i=0;i<pos-1;i++)
            p = p->next;
        t->next = p->next;
        t->prev = p;
        p->next = t;
        if(t->next)
            t->next->prev = t;
    }
}

int main()
{
    int A[] = {2,3,5,4,6,7,3,5,1,5};
    int size = 10;
    create(A,size);
    display(first);
    printf("Length of LL = %d\n", length(first));
    insert(100,4);
    display(first);
    printf("Length of LL = %d\n", length(first));
    return 0;
}