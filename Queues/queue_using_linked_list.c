#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} * front, *rear;

void enqueue(int x)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
    {
        printf("Heap/Queue is full");
    }
    else
    {
        t->data = x;
        t->next = NULL;
        if (front == NULL)
        {
            front = rear = t;
        }
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue()
{
    int x = -1;
    struct Node *t;
    if (front == NULL)
    {
        printf("Queue is Empty.");
    }
    else
    {
        t = front;
        front = front->next;
        t->next = NULL;
        x = t->data;
        free(t);
    }
    return x;
}

void Display()
{
    struct Node *p = front;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    enqueue(5);
    enqueue(15);
    enqueue(25);
    enqueue(35);
    Display();
    printf("Element deleted : %d \n", dequeue());
    Display();
    printf("Element deleted : %d \n", dequeue());
    printf("Element deleted : %d \n", dequeue());
    printf("Element deleted : %d \n", dequeue());
    printf("Element deleted : %d \n", dequeue());
}