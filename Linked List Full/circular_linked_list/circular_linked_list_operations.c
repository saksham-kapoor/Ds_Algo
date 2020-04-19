#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *head = NULL;

void insert(int pos, int val)
{
    struct Node *t, *p;
    int i;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = val;
    if (pos == 0) //Inserting Before Head
    {
        if (head == NULL)
        {
            printf("k");
            head = t;
            head = head->next;
        }
        else
        {
            printf("b");
            p = head;
            t->next = head;
            while (p->next != head)
                p = p->next;
            p->next = t;
            head = t;
        }
    }
    else
    {
        for (i = 0; i < pos - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

int delete (int pos)
{
    int x, i;
    struct Node *p, *q;
    if (pos == 1)
    {
        if (head->next == head)
        {
            x = head->data;
            free(head);
            head = NULL;
        }
        else
        {
            p = head;
            while (p->next != head)
                p = p->next;
            p->next = head->next;
            x = head->data;
            free(head);
            head = p->next;
        }
    }
    else
    {
        p = head;
        for (i = 0; i < pos - 2; i++)
        {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        x = q->data;
        free(q);
    }
    return x;
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

    insert(0, 5);
    insert(0, 10);

    display();

    return 0;
}