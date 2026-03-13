/*
   vidya@Vidya:~/mypractice/cpp/2026/threads$ g++ -std=c++11 -pthread mutex_lock.cpp
vidya@Vidya:~/mypractice/cpp/2026/threads$ ./a.out
200000
*/
#include<iostream>
#include<mutex>
#include<thread>
using namespace std;

int amt=0;
std::mutex m;
void addMoney() {
for(int i=0;i<100000;i++)
{
    m.lock();
    ++amt;
    m.unlock();
}
}

int main()
{
    std::thread t1(addMoney);
    std::thread t2(addMoney);

    t1.join();
    t2.join();

    cout<<amt <<endl;

    return 0;
}
