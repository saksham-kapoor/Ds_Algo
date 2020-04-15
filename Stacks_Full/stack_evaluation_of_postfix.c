#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    int size;
    int top;
    int *s;
};

void push(struct Stack *st, int val)
{
    if (st->top == st->size - 1)
        printf("Stack Full");
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
        printf("Stack Empty");
    else
    {
        x = st->s[st->top];
        st->top--;
    }
    return x;
}

int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '(' || x == ')')
        return 0;
    return 1;
}

int evaluate(char *postfix)
{
    struct Stack st;
    int i, x1, x2, r;
    st.size = strlen(postfix);
    st.top = -1;
    st.s = (int *)malloc(st.size * sizeof(int));
    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isOperand(postfix[i]))
            push(&st, postfix[i] - '0');
        else
        {
            x2 = pop(&st);
            x1 = pop(&st);

            switch (postfix[i])
            {
            case '+':
                r = x1 + x2;
                push(&st, r);
                break;
            case '-':
                r = x1 - x2;
                push(&st, r);
                break;
            case '/':
                r = x1 / x2;
                push(&st, r);
                break;
            case '*':
                r = x1 * x2;
                push(&st, r);
                break;
            }
        }
    }
    return pop(&st);
}

int main()
{
    char *postfix = "35*62/+4-";
    printf("Answer : %d ", evaluate(postfix));
    return 0;
}