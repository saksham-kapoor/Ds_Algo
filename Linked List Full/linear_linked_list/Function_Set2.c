// ####################

// Functions Covered -
// 1. create_linked_list
// 2. display_linked_list
// 3. linear_search_linked_list
// 4. recursive_linear_search_linked_list
// 5. linear_search_linked_list_move_to_head
// 6. insert_in_linked_list

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
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display_linked_list(struct Node *p)
{
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void linear_search_linked_list(struct Node *p, int key)
{
    int node_num = 0;
    while (p)
    {
        node_num++;
        if (key == p->data)
        {
            printf("Element found at node number %d", node_num);
            return;
        }
        p = p->next;
    }
    printf("Element Not Found");
    return;
}

struct Node *recursive_linear_search_linked_list(struct Node *p, int key)
{
    if (p == 0)
        return 0;

    if (key != p->data)
    {
        return recursive_linear_search_linked_list(p->next, key);
    }

    return p;
}

void linear_search_linked_list_move_to_head(struct Node *p, int key)
{
    int node_num = 0;
    struct Node *t;
    t = p;
    while (p)
    {
        node_num++;
        if (p->data == key)
        {
            t->next = p->next;
            p->next = first;
            first = p;
            printf("Found at node number %d but is now shifted to first position. New List is as follows.", node_num);
            return;
        }
        t = p;
        p = p->next;
    }
    printf("Element not found.");
}

void insert_in_linked_list(int pos, int val)
{
    if (pos == 0)
    {
        struct Node *t = (struct Node *)malloc(sizeof(struct Node));
        t->data = val;
        t->next = first;
        first = t;
    }
    if (pos > 0)
    {
        int i;
        struct Node *p = first;
        struct Node *t = (struct Node *)malloc(sizeof(struct Node));
        for (i = 0; i < pos - 1 && p; i++)
            p = p->next;
        if (p)
        {
            t->data = val;
            t->next = p->next;
            p->next = t;
        }
    }
}

int main()
{
    int A[] = {1, 5, 2, -6, 14, 15};
    struct Node *result;
    create_linked_list(A, 6);
    printf("Display Linked List = ");
    display_linked_list(first);
    // printf("\n");
    // printf("Linear Search Result = ");
    // linear_search_linked_list(first, 14);
    // printf("\n");
    // printf("Recursive Linear Search Result = ");
    // result = recursive_linear_search_linked_list(first, 14);
    // if (result)
    // {
    //     printf("Found at address = %d", result);
    // }
    // else
    // {
    //     printf("Not Found");
    // }
    // printf("\n");
    // printf("Linear Search With Move to Head Result = ");
    // linear_search_linked_list_move_to_head(first, 133);
    // printf("\n");
    // printf("Display Linked List = ");
    // display_linked_list(first);
    printf("\n");
    insert_in_linked_list(1, 305);
    printf("Display Linked List = ");
    display_linked_list(first);
    return 0;
}