#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q, int size)
{
    q->size = size;
    q->Q = (int *)malloc(q->size * sizeof(int));
    q->front = q->rear = 0;
}

void enqueue(struct Queue *q, int val)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        printf("Overflow \n");
        return;
    }
    q->rear = (q->rear + 1) % q->size;
    q->Q[q->rear] = val;
}

int dequeue(struct Queue *q)
{
    int x = -1;
    if (q->rear == q->front)
        printf("Underflow \n");
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

void Display(struct Queue q)
{
    int i = q.front + 1;
    do
    {
        printf("%d ", q.Q[i]);
        i = (i + 1) % q.size;
    } while (i != (q.rear + 1) % q.size);
    printf("\n");
}

int main(int argc, char const *argv[])
{
    struct Queue q;
    create(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 30);
    printf("Elemets are : ");
    Display(q);
    printf("Element Removed : %d\n", dequeue(&q));
    printf("Elemets are : ");
    Display(q);

    return 0;
}
