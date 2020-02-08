// ####################

// Functions Covered -
// 1. create_linked_list
// 2. recursive_display_linked_list
// 3. reverse_elements_linked_list
// 4. reverse_links_linked_list
// 5. recursive_reverse_links_linked_list  --------------------!!!! IMPORTANT

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

void recursive_display_linked_list(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        recursive_display_linked_list(p->next);
    }
}

void reverse_elements_linked_list(struct Node *p)
{
    int A[20], n = 0;
    while (p)
    {
        A[n] = p->data;
        n++;
        p = p->next;
    }
    p = first;
    while (p)
    {
        n--;
        p->data = A[n];
        p = p->next;
    }
}

void reverse_links_linked_list(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;
    while (p)
    {
        r = q;
        q = p;
        p = p->next; // sliding pointers
        q->next = r;
    }
    first = q;
}

void recursive_reverse_links_linked_list(struct Node *q, struct Node *p)
{
    if (p != NULL)
    {
        recursive_reverse_links_linked_list(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

int main()
{
    int A[8] = {1, 2, 3, 5, 6, 7, 8, 9};
    create_linked_list(A, 8);
    recursive_display_linked_list(first);
    // reverse_elements_linked_list(first);
    // reverse_links_linked_list(first);
    recursive_reverse_links_linked_list(NULL, first);
    printf("\n");
    recursive_display_linked_list(first);
    return 0;
}