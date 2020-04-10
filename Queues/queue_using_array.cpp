#include <iostream>
using namespace std;

class Queue
{
    int size;
    int front;
    int rear;
    int *Q;

public:
    Queue(int size)
    {
        this->size = size;
        front = rear = -1;
        Q = new int[this->size];
    }
    void enqueue(int val);
    int dequeue();
    void display();
};

void Queue::enqueue(int val)
{
    if (rear == size - 1)
    {
        printf("Overflow \n");
        return;
    }
    rear++;
    Q[rear] = val;
}

int Queue::dequeue()
{
    int x = -1;
    if (front == rear)
    {
        printf("Underflow \n");
    }
    else
    {
        front++;
        x = Q[front];
    }
    return x;
}

void Queue::display()
{
    int i;
    for (i = front + 1; i <= rear; i++)
    {
        printf("%d ", Q[i]);
    }
    printf("\n");
}

int main()
{
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    q.enqueue(50);
    printf("Item Deleted : %d \n", q.dequeue());
    q.display();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
}