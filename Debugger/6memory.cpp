/*#include <iostream>
using namespace std;

int add(int a, int b) {
    int sum = a + b;
    return sum;
}

int main() {
    int x = 5;
    int y = 10;
    int result = add(x, y);  // add bp here

    int* heapVar = new int(50);

    cout << result << " " << *heapVar << endl;  // add bp here, do step over

    delete heapVar;
    return 0;
}
    */


    #include <iostream>
using namespace std;

int* createValue() {
    int* ptr = new int(100);  // allocated on heap
    return ptr;
}

int main() {
    int* p = createValue();  // add bp here

    cout << *p << endl;  // ✅ works (memory still valid)

    delete p;            // must free manually
    return 0;
}