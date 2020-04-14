#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *S;
};

void create(struct Stack *st)
{
    printf("Enter Max Size Of Stack: ");
    scanf("%d", &st->size);
    st->S = (int *)malloc(st->size * sizeof(int));
    st->top = -1;
}

void push(struct Stack *st, int val)
{
    if (st->top == st->size - 1)
        printf("Overflow\n");
    else
    {
        st->top++;
        st->S[st->top] = val;
    }
}

int pop(struct Stack *st)
{
    int x = -1;
    if (st->top == -1)
        printf("Underflow\n");
    else
    {
        x = st->S[st->top];
        st->top--;
    }
    return x;
}

int peek(struct Stack st, int pos)
{
    if (st.top - pos + 1 >= 0)
        return st.S[st.top - pos + 1];
    else
        return -1;
}

int stackTop(struct Stack st)
{
    if (st.top == -1)
        return -1;
    else
        return st.S[st.top];
}

int isEmpty(struct Stack st)
{
    if (st.top == -1)
        return 1;
    else
        return 0;
}

int isFull(struct Stack st)
{
    if (st.top == st.size - 1)
        return 1;
    else
        return 0;
}

void display(struct Stack st)
{
    int i;
    if (st.top == -1)
        printf("Stack Empty \n");
    else
    {
        printf("Elements of Stack are : ");
        for (i = st.top; i >= 0; i--)
        {
            printf("%d ", st.S[i]);
        }
        printf("\n");
    }
}

int main()
{
    struct Stack st;

    create(&st);

    push(&st, 5);
    push(&st, 10);
    push(&st, 15);
    push(&st, 20);
    display(st);

    printf("Element Deleted : %d\n", pop(&st));
    display(st);

    printf("Element at position 2 : %d\n", peek(st, 2));
    return 0;
}