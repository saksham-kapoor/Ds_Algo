#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} * head;

void create(int *elements, int size)
{
    head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *t, *p;
    int i;
    head->data = elements[0];
    head->next = head;
    p = head;
    for (i = 1; i < size; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = elements[i];
        t->next = head;
        p->next = t;
        p = t;
    }
    printf("Created \n");
}

void display()
{
    struct Node *p = head;
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != head);
}

void recursive_display(struct Node *p)
{
    static int flag = 0;
    if (flag == 0 || p != head)
    {
        flag = 1;
        printf("%d ", p->data);
        recursive_display(p->next);
    }
    flag = 0;
}

int main()
{
    int elements[] = {5, 10, 15, 20, 25};
    int size = 5;
    create(elements, size);
    // display();
    recursive_display(head);
    return 0;
}