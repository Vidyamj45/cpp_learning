#include<iostream>

template<typename T>
class Printer{

    public:
    void show(T data)
    {
        std::cout<<"Generic "<<data<<std::endl;
    }
};

template<>
class Printer<int>
{
    public:
    void show(int data)
    {
        std::cout<<"Specialized "<<data<<std::endl;
    }
};

int main()
{
    Printer<std::string> p1;
    Printer<int> p2;
    p1.show("vidya");
    p2.show(4549);

    return 0;
}
