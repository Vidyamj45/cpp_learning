/*
   vidya@Vidya:~/mypractice/cpp/2026/threads$ ./a.out
[main]Send the signal
[thread]Got the signal
[thread]Send the signal
[main]Got the signal
*/

#include<iostream>
#include<mutex>
#include<thread>
#include<semaphore>

using namespace std;

std::binary_semaphore
    smphSignalMainToThread{0},
    smphSignalThreadToMain{0};

void ThreadProc()
{
    smphSignalMainToThread.acquire();

    cout<< "[thread]Got the signal"<<endl;

    using namespace std::literals;
    std::this_thread::sleep_for(3s);

    cout<< "[thread]Send the signal"<<endl;

    smphSignalThreadToMain.release();

}

int main()
{
    std::thread t1(ThreadProc);
    cout<<"[main]Send the signal"<<endl;

    smphSignalMainToThread.release();
    smphSignalThreadToMain.acquire();

    cout<<"[main]Got the signal "<<endl;

    t1.join();
}





