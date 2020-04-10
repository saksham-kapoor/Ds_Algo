#include <stdio.h>
#include <stdlib.h>

struct DEQueue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void insert_at_front(struct DEQueue *q, int val)
{
    if (q->front == -1)
        printf("Cannot insert at front, Overflow \n");
    else
    {
        q->Q[q->front] = val;
        q->front--;
        printf("Element %d has been inserted at the front \n", val);
    }
}

void insert_at_rear(struct DEQueue *q, int val)
{
    if (q->rear == q->size - 1)
        printf("Overflow \n");
    else
    {
        q->rear++;
        q->Q[q->rear] = val;
        printf("Element %d has been inserted at the rear \n", val);
    }
}

void delete_from_front(struct DEQueue *q)
{
    if (q->front == q->rear)
        printf("Cannot delete from front, Underflow. \n");
    else
    {
        q->front++;
        printf("Element %d has been deleted from the front\n", q->Q[q->front]);
        if (q->front == q->rear)
            q->front = q->rear = -1;
    }
}

void delete_from_rear(struct DEQueue *q)
{
    if (q->front == q->rear)
        printf("Cannot delete from rear, Underflow. \n");
    else
    {
        printf("Element %d has been deleted from the rear\n", q->Q[q->rear]);
        q->rear--;
        if (q->front == q->rear)
            q->front = q->rear = -1;
    }
}

void display(struct DEQueue q)
{
    int i;
    printf("Elements of DEQueue are : ");
    for (i = q.front + 1; i <= q.rear; i++)
    {
        printf("%d ", q.Q[i]);
    }
    printf("\n");
}

int main()
{
    struct DEQueue q;
    printf("Enter Max Size : ");
    scanf("%d", &q.size);
    q.front = q.rear = -1;
    q.Q = (int *)malloc(q.size * sizeof(int));

    insert_at_rear(&q, 5);
    insert_at_rear(&q, 10);
    insert_at_rear(&q, 15);
    insert_at_rear(&q, 20);

    display(q);

    delete_from_front(&q);
    delete_from_front(&q);

    display(q);

    delete_from_rear(&q);

    display(q);

    insert_at_front(&q, 80);
    insert_at_front(&q, 90);

    display(q);
}