#include<iostream>

template <typename T>
T getMax(T a, T b)
{
    return (a>b ? a : b);
}

template <>
char getMax<char> (char a, char b)
{
    std::cout<<"Specialized char."<<std::endl;
    return (a>b ? a : b);
}

int main()
{
    std::cout<<getMax(3, 9)<<std::endl;
    std::cout<<getMax('S', 'V')<<std::endl;

    return 0;
}

