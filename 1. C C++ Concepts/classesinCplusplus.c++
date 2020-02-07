#include <iostream>

using namespace std;

class Rectangle
{
private:
    int length;
    int breadth;

public:
    Rectangle(int l, int b);              //Constructor
    Rectangle() { length = breadth = 1; } //Constructor
    int Area();                           //Facilitator (uses datamembers of class)
    int Perimeter();                      //Facilittor
    int getLength();                      //Getter Function, Accessor
    void setLength(int l);                //Setter Function, Mutator
    ~Rectangle();                         //Destructor
};

Rectangle::Rectangle(int l, int b)
{
    length = l;
    breadth = b;
}

int Rectangle::Area()
{
    return (length * breadth);
}

int Rectangle::Perimeter()
{
    return 2 * (length + breadth);
}

int Rectangle::getLength()
{
    return length;
}

void Rectangle::setLength(int l)
{
    length = l;
}

Rectangle::~Rectangle()
{
}

int main(int argc, char *argv[])
{
    Rectangle r;
    Rectangle rect(10, 5);
    int ar, arect, pr, prect;
    ar = r.Area();
    arect = rect.Area();
    pr = r.Perimeter();
    prect = rect.Perimeter();
    cout << ar << "\n"
         << arect << "\n"
         << pr << "\n"
         << prect << "\n";
    cout << r.getLength() << "\n"
         << rect.getLength() << "\n";
    r.setLength(500);
    rect.setLength(50000);
    cout << r.getLength() << "\n"
         << rect.getLength() << "\n";
    return 0;
}