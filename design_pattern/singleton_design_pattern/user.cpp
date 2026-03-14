#include<iostream>
#include "logger.hpp"
#include<thread>
using namespace std;

void user1logs()
{
    Logger* logger1 = Logger::getlogger();
    logger1->Log("this msg is from user1");
}

void user2logs()
{
    Logger* logger2 = Logger::getlogger();
    logger2->Log("this msg is from user1");

}
int main()
{

    std::thread t1(user1logs);
    std::thread t2(user2logs);

    t1.join();
    t2.join();



    return 0;
}