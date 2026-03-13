/*vidya@Vidya:~/mypractice/cpp/2026/threads$ g++ -std=c++11 -pthread detach.cpp
vidya@Vidya:~/mypractice/cpp/2026/threads$ ./a.out
main()
4main() after

*/
#include<iostream>
#include<chrono>
#include<thread>
using namespace std;

void run(int count) {
    while(count --> 0)
	cout<< count << "CppNuts" <<endl;
    std::this_thread::sleep_for(chrono::seconds(5));
    cout<< "thread finished" <<endl;
}

int main()
{
    std::thread t1(run, 5);
    cout<< "main()" <<endl;

    t1.detach();

    cout<< "main() after" <<endl;
    return 0;
}
