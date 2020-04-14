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
    int i, x;
    for (i = 0; exp[i]; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(st, exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
            if (st->top == -1)
                return 0;
            else
            {
                x = pop(st);
                if (!((int)x + 2 == (int)exp[i] || (int)x + 1 == (int)exp[i]))
                    return 0;
            }
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

    isBalanced(&st, exp) ? printf("Given Expression is Balanced\n") : printf("Given Expression is not Balanced\n");
}