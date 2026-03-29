#include <iostream>
using namespace std;

int main() {
    int *p = NULL;
    *p = 10;   // crash (segmentation fault), add bp here
    return 0;
}

