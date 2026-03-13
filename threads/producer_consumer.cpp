#include<iostream>
#include<mutex>
#include<condition_variable>
#include<thread>
using namespace std;
std::mutex m;
std::condition_variable cv;
deque<int> buffer;

const unsigned int maxBufferSize = 0;

void producer(int val) {
    while(val) {
	std::unique_lock<std::mutex> locker(m);
	cv.wait(locker, [](){return buffer.size < maxBufferSize;});
	buffer.push_back(val);
	cout<<"Produced: "<<val <<endl;
	val--;
	locker.unlock();
	cv.notify_one();
    }
}

void consumer() {
    while(1) {
	std::unique_lock<std::mutex> locker(m);
	cv.wait(locker, [](){return buffer.size() > 0;});
	int val = buffer.back();
	buffer.pop_back();
	cout<< "Consumed "<<val << endl;
	locker.unlock();
	cv.notify_one();
    }
}

int main()
{
    std::thread t1(producer, 100);
    std:: thread t2(consumer);

    t1.join();
    t2.join();

    return 0;
}
