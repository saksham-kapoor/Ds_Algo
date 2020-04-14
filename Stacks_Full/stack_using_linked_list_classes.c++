#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
    Node *top;

public:
    Stack() { top = NULL; }
    void push(int val);
    int pop();
    void display();
};

void Stack::push(int val)
{
    Node *t = new Node;
    if (t == NULL)
        cout << "StackFull \n";
    else
    {
        t->data = val;
        t->next = top;
        top = t;
    }
}

int Stack::pop()
{
    int x = -1;
    if (top == NULL)
        cout << "Underflow \n";
    else
    {
        Node *t = top;
        top = top->next;
        x = t->data;
        t->next = NULL;
        free(t);
    }
    return x;
}

void Stack::display()
{
    Node *p = top;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";
}

int main()
{
    Stack st;
    st.push(5);
    st.push(10);
    st.push(15);
    st.push(20);
    st.display();

    st.pop();
    st.display();
}