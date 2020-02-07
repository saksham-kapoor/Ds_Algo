// 3 ways :
// 1. Pass by value
// 2. Pass by Address
// 3. Pass by Reference (only c++)

#include <stdio.h>
#include <iostream>

using namespace std;

// Pass By Value
void SwapByValue(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
    cout << "a : " << a << " and b : " << b << endl;
}

// Pass By Address
void SwapByAddress(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    cout << "a : " << *a << " and b : " << *b << endl;
}

// Pass By Reference
void SwapByReference(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
    cout << "a : " << a << " and b : " << b << endl;
}
int main(int argc, char *argv[])
{
    int a, b;
    a = 1;
    b = 3;
    SwapByValue(a, b);
    cout << "a : " << a << " b : " << b << endl;
    SwapByAddress(&a, &b);
    cout << "a : " << a << " b : " << b << endl;
    SwapByReference(a, b);
    cout << "a : " << a << " b : " << b << endl;
    return 0;
}