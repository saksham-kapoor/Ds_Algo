#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *first;

public:
    LinkedList() { first = NULL; }
    LinkedList(int A[], int n);
    ~LinkedList();

    void Display();
    void Insert(int val);
    void Delete(int index);
    int Length();
};

LinkedList::LinkedList(int A[], int n)
{
    first = new Node;
    first->data = A[0];
    Node *last = first;
    for (int i = 1; i < n; i++)
    {
        Node *t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

LinkedList::~LinkedList()
{
    Node *p = first;
    while (p)
    {
        first = first->next;
        delete p;
        p = first;
    }
}

void LinkedList::Display()
{
    Node *p = first;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";
}

void LinkedList::Insert(int val)
{
    Node *p = first;
    while (p->next)
    {
        p = p->next;
    }
    Node *t = new Node;
    t->data = val;
    t->next = NULL;
    p->next = t;
}

void LinkedList::Delete(int index)
{
    Node *p = first, *q = NULL;
    if (index == 1)
    {
        first = first->next;
        p->next = NULL;
        cout << "Item Deleted = " << p->data << "\n";
        delete p;
        return;
    }
    for (int i = 1; i < index; i++)
    {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    p->next = NULL;
    cout << "Item Deleted = " << p->data << "\n";
    delete p;
}

int LinkedList::Length()
{
    int count = 0;
    Node *p = first;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}

int main()
{
    int Arr[] = {1, 3, 4, 6, 7, 9};
    LinkedList A(Arr, 6);
    A.Display();
    A.Insert(20);
    A.Display();
    cout << "Length = " << A.Length() << "\n";
    A.Delete(1);
    A.Display();
    return 0;
}