#include <iostream>
using namespace std;

int main() {
    int arr[3] = {10, 20, 30};
    arr[5] = 100;   // bug, add bp here
    cout << "Done" << endl;
    return 0;
}