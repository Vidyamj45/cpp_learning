/*
   vidya@Vidya:~/mypractice/cpp/2026/threads$ g++ -std=c++11 -pthread condition_variable.cpp
vidya@Vidya:~/mypractice/cpp/2026/threads$ ./a.out
Amount added, current balance is : 500
Amount deducted: 500


########################
vidya@Vidya:~/mypractice/cpp/2026/threads$ g++ -std=c++11 -pthread condition_variable.cpp
vidya@Vidya:~/mypractice/cpp/2026/threads$ ./a.out
Amount added, current balance is : 500
Amount deducted: 500



#########added money=500. withdraw request=600#############
vidya@Vidya:~/mypractice/cpp/2026/threads$ g++ -std=c++11 -pthread condition_variable.cpp
vidya@Vidya:~/mypractice/cpp/2026/threads$ ./a.out
Amount added, current balance is : 500
Amount can't be deducted, current balance isless than: 600
Current Balance is : 500
*/

#include<iostream>
#include<condition_variable>
#include<mutex>
#include<thread>
#include<chrono>
using namespace std;

std::condition_variable cv;
std::mutex m;
long balance = 0;


void addMoney(int money)
{
    std::lock_guard<mutex> lg(m);
    balance +=money;
    cout<< "Amount added, current balance is : "<< balance <<endl;
    cv.notify_one();
}

void withDrawMoney(int money) {
    std::unique_lock<mutex> ul(m);
    cv.wait(ul, [] { return (balance!=0) ? true : false; });
    if(balance >=money) {
	balance -= money;
	cout<< "Amount deducted: "<< money << endl;
    } else {
	cout<< "Amount can't be deducted, current balance isless than: " << money <<endl;
    }


	cout<< "Current Balance is : "<< balance << endl;
}


int main() {
    std::thread t1(withDrawMoney, 600);
//    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::thread t2(addMoney, 500);
    t1.join();
    t2.join();

    return 0;
}



