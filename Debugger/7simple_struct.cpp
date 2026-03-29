/*
After adding breakpoint, compile with "g++ -g simple_struct.cpp -o simple_struct.exe"
Add d, d.a, d.b, d.c, &d, &d.a &d.b, &d.c, sizepf(d) to the watch window.
Observe values at d.a ...d.c and also addresses.
*/


#include <iostream>
using namespace std;

struct Data {
    int a;
    int b;
    int c;
};

int main() {
    Data d;

    d.a = 10;
    d.b = 20;
    d.c = 30;  // add breakpoint here.

    cout << d.a << " " << d.b << " " << d.c << endl;

    return 0;
}