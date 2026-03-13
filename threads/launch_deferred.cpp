/*Video : CppNuts (multithreading series video 16)

  Here used launch::deferred, so seperate thread won't get create for the Oddfind function. main() and Oddfind threading are running on the same thread. We are observing the same thread ID.
vidya@Vidya:~/mypractice/cpp/2026/threads$ g++ -std=c++11 -pthread launch_deffer.cpp
vidya@Vidya:~/mypractice/cpp/2026/threads$ ./a.out
Thread ID  133674837043008
Thread Created if policy is std::launch::async
Waiting for thread
OddSum Thread ID of Oddfind 133674837043008
902500000000000000
Completed
 */

#include<iostream>
#include<mutex>
#include<thread>
#include<chrono>
#include<future>
using namespace std;
using namespace std::chrono;
typedef long int ull;

ull Oddfind( ull start, ull end)
{
    ull OddSum=0;
    cout<< "Thread ID of Oddfind "<<std::this_thread::get_id()<<endl;
    for(ull i=start;i<=end;i++)
    {
	if(i & 1 == 1)
	    OddSum +=i;
    }
    return OddSum;
}



int main() {
    ull start=0, end=1900000000;


    cout<< "Thread ID  "<< std::this_thread::get_id() <<endl;
    cout<< "Thread Created if policy is std::launch::async "<<endl;
    
    std::future<ull> OddSum = std::async(std::launch::deferred, Oddfind, start, end);

    cout<< "Waiting for thread "<<endl;

    cout<<"OddSum "<<OddSum.get()<<endl;

    cout << "Completed "<<endl;


    return 0;
}
