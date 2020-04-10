#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} * first;

void create_linear_linked_list(int A[], int n)
{
    int i;
    struct Node *p;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    p = first;
    for (i = 1; i < n; i++)
    {
        struct Node *t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        p->next = t;
        p = t;
    }
}

void display_linear_linked_list(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        display_linear_linked_list(p->next);
    }
}

void create_circular_linked_list(int A[], int n)
{
    int i;
    struct Node *p;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = first;
    p = first;
    for (i = 1; i < n; i++)
    {
        struct Node *t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = first;
        p->next = t;
        p = t;
    }
}

void recursive_display_circular_linked_list(struct Node *p)
{
    static int flag = 0;
    if (flag == 0)
    {
        if (p->next == first)
            flag = 1;
        printf("%d ", p->data);
        recursive_display_circular_linked_list(p->next);
    }
}

void display_circular_linked_list(struct Node *p)
{
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != first);
}

int main()
{
    int A[] = {3, 5, 8, 9};
    // create_linked_list(A, 4);
    create_circular_linked_list(A, 4);
    // first->next->next->next->next = first;
    recursive_display_circular_linked_list(first);
    // display_circular_linked_list(first);
    // display_linear_linked_list(first);
}