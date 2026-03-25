#include<iostream>

template<class T>
class Box {
    T value;
    public:
    Box(T val) :value(val){}

    void show()
    {
        std::cout<<"Value: "<<value<<std::endl;
    }
};

int main()
{
    Box<int> b1(10);
    Box<std::string> b2("Hello vidya");

    b1.show();
    b2.show();

    return 0;
}