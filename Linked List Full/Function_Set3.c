// ####################

// Functions Covered -
// 1. insert_at_last_linked_list
// 2. recursive_display_linked_list
// 3. insert_in_sorted_linked_list ---------------!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!IMPORTANT

// ####################

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *last = NULL;

void insert_at_last_linked_list(int val)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = val;
    t->next = NULL;
    if (first == NULL)
    {
        first = t;
        last = t;
    }
    else
    {
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

void insert_in_sorted_linked_list(int val)
{
    struct Node *p = first, *q = NULL;
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = val;
    if (val < first->data)
    {
        t->next = first;
        first = t;
    }
    else
    {
        while (p)
        {
            if (val < p->data)
            {
                break;
            }
            q = p;
            p = p->next;
        }
        t->next = p;
        q->next = t;
    }
}

int main()
{
    int A[6] = {1, 2, 3, 4, 6, 7};
    int B[8] = {9, 5, 7, 4, 5, 8, 9, 2};
    int i, j;
    for (i = 0; i < 6; i++)
    {
        insert_at_last_linked_list(A[i]);
    }
    for (i = 0; i < 8; i++)
    {
        insert_in_sorted_linked_list(B[i]);
    }
    recursive_display_linked_list(first);

    return 0;
}