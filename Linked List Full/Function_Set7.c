// ####################

// Functions Covered -
// 1. create_linked_list
// 2. recursive_display_linked_list
// 3. check_loop_linked_list

// ####################

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create_linked_list(int A[], int n)
{
    int i;
    struct Node *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    last = first;
    for (i = 1; i < n; i++)
    {
        struct Node *t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void recursive_display_linked_list(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        recursive_display_linked_list(p->next);
    }
}

int loop_check_linked_list(struct Node *p)
{
    struct Node *q = p;
    do
    {
        p = p->next;
        q = q->next;
        q = (q != NULL) ? q->next : NULL;

    } while (p && q && p != q);
    return (q == NULL) ? 0 : 1;
}

int main()
{
    int A[5] = {1, 2, 3, 4, 5};
    struct Node *w, *x;
    create_linked_list(A, 5);
    w = first->next->next;
    x = first->next->next->next->next;
    x->next = w;
    printf("is loop %d", loop_check_linked_list(first));
    // recursive_display_linked_list(first);
}