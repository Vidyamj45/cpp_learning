/*
   vidya@Vidya:~/mypractice/cpp/2026/threads$ g++ -std=c++11 -pthread promise_future.cpp
vidya@Vidya:~/mypractice/cpp/2026/threads$ ./a.out
Thread Created
Waiting for thread
OddSum 902500000000000000
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

void Oddfind(std::promise<ull>&& OddSumPromise, ull start, ull end)
{
    ull OddSum=0;
    for(ull i=start;i<=end;i++)
    {
	if(i & 1 == 1)
	    OddSum +=i;
    }
    OddSumPromise.set_value(OddSum);
}



int main() {
    ull start=0, end=1900000000;

    std::promise<ull> OddSum;
    std::future<ull> OddFuture = OddSum.get_future();

    cout<< "Thread Created " <<endl;
    std::thread t1(Oddfind, std::move(OddSum), start, end);

    cout<< "Waiting for thread "<<endl;

    cout<<"OddSum "<<OddFuture.get()<<endl;

    cout << "Completed "<<endl;

    t1.join();

    return 0;
}
