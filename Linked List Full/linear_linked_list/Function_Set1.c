// ####################

// Functions Covered -
// 1. create_linked_list
// 2. display_linked_list
// 3. recursive_display_linked_list
// 4. recursive_display_linked_list_reverse
// 5. count_nodes
// 6. recursion_count_nodes
// 7. sum_linked_list
// 8. recursive_sum_linked_list
// 9. find_max_linked_list
// 10. recursive_find_max_linked_list ---------------!!!!!!!!!!!!!!!!!!!!!!!!!IMPORTANT

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

void recursive_display_linked_list(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        recursive_display_linked_list(p->next);
    }
}

void recursive_display_linked_list_reverse(struct Node *p)
{
    if (p)
    {
        recursive_display_linked_list_reverse(p->next);
        printf("%d ", p->data);
    }
}

int count_nodes(struct Node *p)
{
    int count = 0;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}

int recursion_count_nodes(struct Node *p)
{
    if (p)
        return recursion_count_nodes(p->next) + 1;
    return 0;
}

int sum_linked_list(struct Node *p)
{
    int sum = 0;
    while (p)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int recursive_sum_linked_list(struct Node *p)
{
    if (p)
        return recursive_sum_linked_list(p->next) + p->data;

    return 0;
}

int find_max_linked_list(struct Node *p)
{
    int max = p->data;
    while (p)
    {
        if (max < p->data)
            max = p->data;
        p = p->next;
    }
    return max;
}

// Good Problem
int recursive_find_max_linked_list(struct Node *p)
{
    int x;
    if (p)
    {
        x = recursive_find_max_linked_list(p->next);
        return (x > p->data) ? x : p->data;
    }
    return INT_MIN;
}

int main()
{
    int A[] = {1, 5, 2, -6, 14, 15};
    create_linked_list(A, 6);
    printf("Display Linked List = ");
    display_linked_list(first);
    printf("\n");
    printf("Recursive Display Of Linked List = ");
    recursive_display_linked_list(first);
    printf("\n");
    printf("Recursive Display of Linked List in Reverse order = ");
    recursive_display_linked_list_reverse(first);
    printf("\n");
    printf("No. of nodes = %d", count_nodes(first));
    printf("\n");
    printf("No. of nodes using recursion = %d", recursion_count_nodes(first));
    printf("\n");
    printf("Sum of all elements = %d", sum_linked_list(first));
    printf("\n");
    printf("Sum of all elements using recursion = %d", recursive_sum_linked_list(first));
    printf("\n");
    printf("Max element = %d", find_max_linked_list(first));
    printf("\n");
    printf("Recursive Find Max = %d", recursive_find_max_linked_list(first));
    return 0;
}