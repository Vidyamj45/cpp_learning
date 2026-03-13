/*
   vidya@Vidya:~/mypractice/cpp/2026/threads$ g++ -std=c++11 -pthread non_static.cpp
vidya@Vidya:~/mypractice/cpp/2026/threads$ ./a.out
9
8
7
6
5
4
3
2
1
0
*/
#include<iostream>
#include<thread>
using namespace std;

class Base
{
    public:
	void run(int x) {
	    while(x-- > 0) {
		cout<< x <<endl;
	    }
	}
};

int main() {
    Base b;
    std::thread t(&Base::run, &b, 10);
    t.join();
    return 0;
}
