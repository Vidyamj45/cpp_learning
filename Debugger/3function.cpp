#include <iostream>
using namespace std;

int add(int a, int b) {
    int result = a + b;   // breakpoint here
    return result;
}

int main() {
    int x = 5, y = 10;
    int sum = add(x, y);  // breakpoint here
    cout << sum << endl;
    return 0;
}