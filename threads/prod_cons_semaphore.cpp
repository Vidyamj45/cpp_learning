/*
    vidya@Vidya:~/mypractice/cpp/2026/threads$ g++ -std=c++20 -pthread prod_cons_semaphore.cpp
vidya@Vidya:~/mypractice/cpp/2026/threads$ ./a.out
Produced = [main] Got the signal
0 1 4 9 16
Consumer = 16 9 4 1 0

Produced = 0 1 4 9 16
Consumer = 16 9 4 1 0

Produced = 0 1 4 9 16
Consumer = 16 9 4 1 0

Produced = 0 1 4 9 16
Consumer = 16 9 4 1 0
*/

#include<iostream>
#include<semaphore>
#include<thread>

using namespace std;
std::binary_semaphore signal_to_producer{1}, signal_to_consumer{0};

#define buff_size 5
int buff[buff_size];

void producer() {
    while(1) {
	signal_to_producer.acquire();
	cout<<"Produced = ";
	for(int i=0; i<buff_size; i++) {
	    buff[i] = i*i;
	    cout<< buff[i]<< " "<<std::flush;
	    std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}
	cout<<endl;
	signal_to_consumer.release();
    }
}

void consumer() {
    while(1) {
	signal_to_consumer.acquire();
	cout<<"Consumer = ";
	for(int i=buff_size-1; i>=0; --i) {
	    cout<<buff[i]<< " "<<std::flush;
	    buff[i] =0;
	    std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}
	cout<<endl;cout<<endl;
	signal_to_producer.release();
    }
}

int main()
{
    std::thread producer_thread(producer);
    std::thread consumer_thread(consumer);

    cout<<"[main] Got the signal"<<endl;
    producer_thread.join();
    consumer_thread.join();
    return 0;
}

 
