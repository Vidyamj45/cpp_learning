#include<iostream>

int main() {
    int arr[5] = {1,2,3,4,5};

    for(int i = 0; i <= 5; i++) {  // BUG
        std::cout<<arr[i]<<std::endl;
    }
    int b = arr[5];

    return 0;
}