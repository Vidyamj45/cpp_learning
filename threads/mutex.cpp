/*
   vidya@Vidya:~/mypractice/cpp/2026/threads$ g++ -std=c++11 -pthread mutex.cpp
vidya@Vidya:~/mypractice/cpp/2026/threads$ ./a.out
161343
*/


#include<iostream>
#include<thread>
using namespace std;

int amt=0;

/*void addMoney() {
    ++amt;
}*/
void addMoney() {
    for(int i = 0; i < 100000; i++) {
        ++amt;
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
