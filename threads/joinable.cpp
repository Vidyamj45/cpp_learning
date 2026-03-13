/*
   vidya@Vidya:~/mypractice/cpp/2026/threads$ g++ -std=c++11 -pthread joinable.cpp
vidya@Vidya:~/mypractice/cpp/2026/threads$ ./a.out
main()
CppNuts
CppNuts
main() after
*/
`
#include<iostream>
#include<chrono>
#include<thread>
using namespace std;

void run(int count)
{
    while(count --> 0) 
	cout<< "CppNuts" <<endl;
    std::this_thread::sleep_for(chrono::seconds(5));
    
}
int main()
{
    std::thread t1(run, 2);
    cout<< "main()" <<endl;
    t1.join();

    if(t1.joinable())
	t1.join();

    cout<<"main() after" <<endl;
    return 0;
}
