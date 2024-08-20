#include <iostream>
using namespace std;

class abc
{
public:
    int x;
    int *y;

    // Constructor
    abc(int _x, int _y) : x(_x), y(new int(_y)) {}

    // Copy Constructor (Shallow Copy)
    abc(const abc &obj) : x(obj.x), y(obj.y) {}

    // Uncomment this for Deep Copy
    // abc(const abc &obj) : x(obj.x), y(new int(*obj.y)) {}

    // Destructor to avoid memory leaks
    ~abc() { delete y; }

    void print() const
    {
        printf("X:%d\nPTR Y:%p\nContent of Y (*y):%d\n\n", x, y, *y);
    }
};

int main()
{
    abc a(1, 2);
    a.print();

    abc b = a; // Copying object a to b (Shallow Copy by default)
    b.print();

    // Changing b's y value
    *b.y = 10;

    cout << "After modifying b's y:" << endl;
    a.print(); // This will show the modified value if it's a shallow copy
    b.print();

    return 0;
}
