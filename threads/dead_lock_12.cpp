/*
   vidya@Vidya:~/mypractice/cpp/2026/threads$ g++ -std=c++11 -pthread dead_lock_12.cpp
vidya@Vidya:~/mypractice/cpp/2026/threads$ ./a.out
Critical section of thread one
Critical section of thread two
*/

#include<iostream>
#include<thread>
#include<mutex>

using namespace std;
std::mutex m1;
std::mutex m2;

void thread1() {
    m1.lock();
    m2.lock();
    cout<<"Critical section of thread one "<<endl;
    m1.unlock();
    m2.unlock();
}

void thread2()
{
    m2.lock();
    m1.lock();
    cout<<"Critical section of thread two "<<endl;
    m2.unlock();
    m1.unlock();
}

int main()
{
    thread t1(thread1);
    thread t2(thread2);

    t1.join();
    t2.join();

    return 0;
}
