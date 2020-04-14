#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    int size;
    int top;
    char *s;
};

void push(struct Stack *st, int val)
{
    if (st->top == st->size - 1)
        printf("Stack Full\n");
    else
    {
        st->top++;
        st->s[st->top] = val;
    }
}

int pop(struct Stack *st)
{
    int x = -1;
    if (st->top == -1)
        printf("Stack Empty\n");
    else
    {
        x = st->s[st->top];
        st->top--;
    }
    return x;
}

int isBalanced(struct Stack *st, char *exp)
{
    int i;
    for (i = 0; exp[i]; i++)
    {
        if (exp[i] == '(')
            push(st, exp[i]);
        else if (exp[i] == ')')
            if (st->top == -1)
                return 0;
            else
                pop(st);
    }
    if (st->top == -1)
        return 1;
    else
        return 0;
}

int main()
{
    struct Stack st;
    char exp[20];
    printf("Enter Expression : ");
    gets(exp);
    st.size = strlen(exp);
    st.top = -1;
    st.s = (char *)malloc(st.size * sizeof(char));

    isBalanced(&st, exp) ? printf("Given Expression is Balanced\n") : printf("Given Expression is not Balamced\n");
}