#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *top = NULL;

void push(int val)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
        printf("Heap/Stack is full \n");
    else
    {
        t->data = val;
        t->next = top;
        top = t;
    }
}

int pop()
{
    int x = -1;
    struct Node *p = top;
    if (top == NULL)
        printf("Stack is Empty \n");
    else
    {
        top = top->next;
        x = p->data;
        p->next = NULL;
        free(p);
    }
    return x;
}

int peek(int pos)
{
    struct Node *p = top;
    int i;
    for (i = 0; i < pos - 1 && p != NULL; i++)
        p = p->next;
    if (p != NULL)
        return p->data;
    return -1;
}

int isFull()
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
        return 1;
    return 0;
}

int isEmpty()
{
    return top == NULL ? 1 : 0;
}

int stackTop()
{
    if (top == NULL)
    {
        return -1;
    }
    return top->data;
}

void display()
{
    struct Node *p = top;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    push(5);
    push(10);
    push(15);
    push(1);
    push(20);
    display();

    printf("Element at position 2 : %d\n", peek(2));
}