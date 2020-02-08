// ####################

// Functions Covered -
// 1. create_linked_list
// 2. recursive_display_linked_list
// 3. merge_linked_lists
// 4. concat_linked_lists

// ####################

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

void create_linked_list1(int A[], int n)
{
    int i;
    first = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = first, *t;
    first->data = A[0];
    first->next = NULL;
    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void create_linked_list2(int A[], int n)
{
    int i;
    second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = second, *t;
    second->data = A[0];
    second->next = NULL;
    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
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

void merge_linked_lists(struct Node *f, struct Node *s)
{
    struct Node *last;
    if (f->data < s->data)
    {
        third = last = f;
        f = f->next;
        last->next = NULL;
    }
    else
    {
        third = last = s;
        s = s->next;
        last->next = NULL;
    }
    while (f && s)
    {
        if (f->data < s->data)
        {
            last->next = f;
            last = f;
            f = f->next;
            last->next = NULL;
        }
        else
        {
            last->next = s;
            last = s;
            s = s->next;
            last->next = NULL;
        }
    }
    if (f != NULL)
    {
        last->next = f;
    }
    else
    {
        last->next = s;
    }
}

void concat_linked_lists(struct Node *f, struct Node *s)
{
    third = first;
    struct Node *p = first;
    while (p->next)
    {
        p = p->next;
    }
    p->next = second;
    second = NULL;
}

int main()
{
    int A[5] = {2, 4, 6, 8, 10};
    int B[5] = {1, 3, 5, 7, 9};
    create_linked_list1(A, 5);
    create_linked_list2(B, 5);
    recursive_display_linked_list(first);
    printf("\n");
    recursive_display_linked_list(second);
    printf("\n");
    // merge_linked_lists(first, second);
    concat_linked_lists(first, second);
    recursive_display_linked_list(third);
    printf("\n");
    return 0;
}