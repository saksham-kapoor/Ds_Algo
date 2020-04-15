#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    int size;
    int top;
    char *s;
};

void push(struct Stack *st, char val)
{
    if (st->top == st->size - 1)
        printf("Stack Full");
    else
    {
        st->top++;
        st->s[st->top] = val;
    }
}

char pop(struct Stack *st)
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

int pre(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return 0;
}

int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    return 1;
}

char *convert(char *infix)
{
    struct Stack st;
    int i = 0, j = 0;
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    st.size = strlen(infix);
    st.top = -1;
    st.s = (char *)malloc(st.size * sizeof(char));
    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if (pre(infix[i]) > pre(st.s[st.top]))
                push(&st, infix[i++]);
            else
                postfix[j++] = pop(&st);
        }
    }
    while (st.top != -1)
    {
        postfix[j++] = pop(&st);
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *infix = "a+b+c*d";
    char *postfix = convert(infix);
    puts(postfix);
    return 0;
}