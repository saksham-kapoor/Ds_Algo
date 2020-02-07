#include <iostream>
using namespace std;

template <class T>
class Arithmetic
{
    T a;
    T b;

public:
    Arithmetic(T a, T b);
    T add()
    {
        T c = a + b;
        return c;
    }
    T sub()
    {
        T c = a - b;
        return c;
    }
};

template <class T>
Arithmetic<T>::Arithmetic(T a, T b)
{
    this->a = a;
    this->b = b;
}

int main(int argc, char *argv[])
{
    Arithmetic<int> cal(10, 5);
    cout << cal.add();
    cout << endl;
    cout << cal.sub();
    cout << endl;

    Arithmetic<float> fl(10.2, 5.1);
    cout << fl.add();
    cout << endl;
    cout << fl.sub();
    cout << endl;
}