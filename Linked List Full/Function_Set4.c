// ####################

// Functions Covered -
// 1. create_linked_list
// 2. recursive_display_linked_list
// 3. delete_value_linked_list
// 4. delete_index_linked_list
// 5. check_sorted_linked_list
// 6. remove_duplicates_linked_list

// ####################

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} * first;

void create_linked_list(int A[], int n)
{
    int i;
    first = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = first;
    first->data = A[0];
    first->next = NULL;
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

void delete_value_linked_list(struct Node *p, int val)
{
    struct Node *t = p;
    if (val == first->data)
    {
        first = first->next;
        p->next = NULL;
        free(p);
        printf("Element Deleted. \n");
        return;
    }
    while (p)
    {
        if (p->data == val)
        {
            t->next = p->next;
            p->next = NULL;
            free(p);
            printf("Element Deleted. \n");
            return;
        }
        t = p;
        p = p->next;
    }
    printf("Element Not Found. \n");
}

void delete_index_linked_list(struct Node *p, int index)
{
    int i;
    struct Node *t = p;
    if (index == 1)
    {
        first = first->next;
        free(p);
        printf("Element Deleted. \n");
        return;
    }
    for (i = 1; i < index; i++)
    {
        t = p;
        p = p->next;
    }
    t->next = p->next;
    p->next = NULL;
    free(p);
    printf("Element Deleted. \n");
    return;
}

void check_sorted_linked_list(struct Node *p)
{
    struct Node *t = p;
    while (p)
    {
        if (p->data < t->data)
        {
            printf("Not Sorted. \n");
            return;
        }
        t = p;
        p = p->next;
    }
    printf("Sorted. \n");
}

// Assuming List Is Sorted
void remove_duplicates_linked_list(struct Node *p)
{
    struct Node *t = p;
    p = p->next;
    while (p)
    {
        if (p->data == t->data)
        {
            t->next = p->next;
            p = p->next;
        }
        else
        {
            t = p;
            p = p->next;
        }
    }
}

int main()
{
    int A[10] = {1, 1, 2, 2, 2, 2, 3, 4, 4, 7};
    create_linked_list(A, 10);
    recursive_display_linked_list(first);
    check_sorted_linked_list(first);
    remove_duplicates_linked_list(first);
    // delete_index_linked_list(first, 6);
    recursive_display_linked_list(first);
}