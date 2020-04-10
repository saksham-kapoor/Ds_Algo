// Assuming elements are the priority itself.
// lower number, higher priority
// In priority queues, element with higher priority is dequeued first

#include <stdio.h>
#include <stdlib.h>

struct P_Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void enqueue(struct P_Queue *q, int val)
{
    int temp, i;
    if (q->rear == q->size - 1)
        printf("Queue Is Full");
    else
    {
        q->rear++;
        q->Q[q->rear] = val;

        i = q->rear;
        while (q->Q[i - 1] > q->Q[i] && i >= 1)
        {
            temp = q->Q[i];
            q->Q[i] = q->Q[i - 1];
            q->Q[i - 1] = temp;
            i--;
        }
    }
}

int dequeue(struct P_Queue *q)
{
    int x = -1;
    if (q->front == q->rear)
    {
        printf("Underflow \n");
        return x;
    }
    q->front++;
    x = q->Q[q->front];
    return x;
}

void display(struct P_Queue q)
{
    int i = q.front + 1;
    for (i; i <= q.rear; i++)
    {
        printf("%d ", q.Q[i]);
    }
    printf("\n");
}

int main()
{
    struct P_Queue q;
    printf("Enter Max Size Of Queue - ");
    scanf("%d", &q.size);
    q.Q = (int *)malloc(q.size * sizeof(int));
    q.front = q.rear = -1;

    enqueue(&q, 5);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 8);
    enqueue(&q, 4);
    printf("Queue Elements : ");
    display(q);

    printf("Item Deleted : %d \n", dequeue(&q));
    printf("Item Deleted : %d \n", dequeue(&q));
    printf("Item Deleted : %d \n", dequeue(&q));
    printf("Queue Elements : ");
    display(q);
}