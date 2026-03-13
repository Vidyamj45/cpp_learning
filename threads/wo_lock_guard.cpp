/*
   vidya@Vidya:~/mypractice/cpp/2026/threads$ g++ -std=c++11 -pthread wo_lock_guard.cpp
vidya@Vidya:~/mypractice/cpp/2026/threads$ ./a.out
T1 1
T1 2
T1 3
T1 4
T1 5
T1 6
T1 7
T1 8
T1 9
T1 10
T0 11
T0 12
T0 13
T0 14
T0 15
T0 16
T0 17
T0 18
T0 19
T0 20
*/

#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

std::mutex m1;
int buffer =0;

void task(const char* threadNumber, int loopFor)
{
    m1.lock();
    for(int i=0;i<loopFor; ++i)
    {
	buffer++;
	cout << threadNumber << buffer << endl;
    }
    m1.unlock();
}

int main() {
    thread t1(task, "T0 ", 10);
    thread t2(task, "T1 ", 10);

    t1.join();
    t2.join();
    return 0;
}
