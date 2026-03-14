#ifndef logger_h
#define logger_h

#include<string>
#include<mutex>
using namespace std;

class Logger{

    static int ctr;
    static Logger* loggerInstance;
    static mutex mtx;
    Logger();
    Logger(const Logger&);
    Logger operator=(const Logger&);

    public:
    static Logger* getlogger();
        void Log(string msg);


};

#endif