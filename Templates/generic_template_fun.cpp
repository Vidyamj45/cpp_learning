#include<iostream>

template <typename T>
T getMax(T a, T b)
{
    return (a>b ? a : b);
}

int main()
{
    std::cout<<getMax(10, 20)<<std::endl;
    std::cout<<getMax(2.3, 1.1)<<std::endl;

    return 0;
}