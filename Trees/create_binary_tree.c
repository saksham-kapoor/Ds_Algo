#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} *root = NULL;

struct Queue
{
    int size;
    int rear;
    int front;
    struct Node **Q; // ARRAY TO STORE ADDRESSES OF NODES ==> *A where A = *Q
};

void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = -1;
    q->rear = -1;
    q->Q = (struct Node **)malloc(q->size * sizeof(struct Node *));
}

void push(struct Queue *q, struct Node *x)
{
    if (q->rear == q->size - 1)
    {
        printf("Overflow");
        return;
    }
    else
    {
        if (q->rear == -1)
        {
            q->rear = q->front = 0;
            q->Q[q->rear] = x;
            return;
        }
        q->rear++;
        q->Q[q->rear] = x;
    }
}

struct Node *pop(struct Queue *q)
{
    struct Node *x = NULL;
    if (q->front == -1)
    {
        printf("Underflow");
        return x;
    }
    else
    {
        x = q->Q[q->front];
        if (q->front == q->rear)
        {
            q->front = q->rear = -1;
        }
        else
        {
            q->front++;
        }
        return x;
    }
}

void display(struct Queue *q)
{
    int i;
    i = q->front;
    while (i <= q->rear)
    {
        printf("%d ", q->Q[i]);
        i++;
    }
}

void create_binary_tree()
{
    struct Node *t, *p;
    int x;
    printf("Enter Value for Root Node = ");
    scanf("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    struct Queue q;
    create(&q, 100);
    push(&q, root);
    while (q.front != -1)
    {
        p = pop(&q);
        printf("Enter value for Left Child = ");
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            push(&q, t);
        }
        printf("Enter value for Right Child = ");
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            push(&q, t);
        }
    }
}

void Preorder(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

int main(int argc, char const *argv[])
{
    create_binary_tree();
    Preorder(root);
    return 0;
}
