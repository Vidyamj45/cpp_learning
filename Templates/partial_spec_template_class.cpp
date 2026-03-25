#include <iostream>
using namespace std;

template <typename T>
class MyClass
{
public:
    void show()
    {
        cout << "Generic Template\n";
    }
};

// Partial specialization for pointer types
template <typename T>
class MyClass<T*>
{
public:
    void show()
    {
        cout << "Pointer Template\n";
    }
};

int main()
{
    MyClass<int> obj1;
    MyClass<int*> obj2;

    obj1.show(); // Generic
    obj2.show(); // Partial specialized
}