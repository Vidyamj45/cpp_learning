/*
   vidya@Vidya:~/mypractice/cpp/2026/threads$ g++ -std=c++11 -pthread double_detach.cpp
vidya@Vidya:~/mypractice/cpp/2026/threads$ ./a.out
main()
4CppNuts
3CppNuts
2CppNuts
1CppNuts
0CppNuts
thread finished
terminate called after throwing an instance of 'std::system_error'
  what():  Invalid argument
Aborted (core dumped)

Double detach throws system error.
*/
#include<iostream>
#include<thread>
#include<chrono>
using namespace std;

void run(int count) {
    while(count --> 0)
	cout << count << "CppNuts" <<endl;
    cout << "thread finished" <<endl;
}

int main() {
    std::thread t1(run, 5);
    cout<< "main()" <<endl;
    t1.detach();
    t1.detach();
    cout<< "main() after" <<endl;

    return 0;
}
