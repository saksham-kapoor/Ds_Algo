#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int rear;
    int front;
    int *Q;
};

void create(struct Queue *q, int size)
{
    q->size = size;
    q->Q = (int *)malloc(q->size * sizeof(int));
    q->front = q->rear = -1;
}

void enqueue(struct Queue *q, int val)
{
    if (q->rear == q->size - 1)
    {
        printf("Overflow.");
        return;
    }
    q->rear++;
    q->Q[q->rear] = val;
}

int dequeue(struct Queue *q)
{
    int x = -1;
    if (q->front == q->rear)
    {
        printf("Queue is empty.");
    }
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

void display(struct Queue q)
{
    int i;
    for (i = q.front + 1; i <= q.rear; i++)
    {
        printf("%d  ", q.Q[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int size;
    // begin initialization
    struct Queue q;
    printf("Enter size : ");
    scanf("%d", &size);
    create(&q, size);
    // end initialization

    enqueue(&q, 5);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    enqueue(&q, 3);
    enqueue(&q, 3);
    printf("Elements in queue : ");
    display(q);
    printf("Element Deleted : %d \n", dequeue(&q));
    printf("Elements in queue : ");
    display(q);
    return 0;
}
