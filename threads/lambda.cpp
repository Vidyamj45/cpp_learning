/*

   vidya@Vidya:~/mypractice/cpp/2026/threads$ g++ -std=c++11 -pthread lambda.cpp
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

int main()
{
    auto fun = [] (int x) {
	while (x-- > 0) {
	    cout<< x << endl;
	}
    };

    std::thread  t(fun, 10);
    t.join();
    return 0;
}
