#include <stdio.h>

typedef struct
{
    int arr[5];
    int b;
    int value;
} s;

s s_array[5];

int main()
{
    // Initialize first struct
    for(int i = 0; i < 5; i++) {
        s_array[0].arr[i] = i + 1;  
    }

    s_array[0].b = 10;
    s_array[0].value = 100;

    // Print values
    for(int i = 0; i < 5; i++) {
        printf("%d ", s_array[0].arr[i]);
    }

    printf("\nb = %d\n", s_array[0].b);
    printf("value = %d\n", s_array[0].value);

    return 0;
}