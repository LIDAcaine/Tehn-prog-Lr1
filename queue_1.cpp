#include "queue_1.h"
int Queue_1::math_operation()
{
    int size = Queue_Size();
    if (size < 2)
    {
        return -1;

    }
    int* arr = new int[size];
    int i = 0;
    for (i = 0; i < size; i++) {
        arr[i] = remove();
        this->insert(arr[i]);
    }
    i = 0;
    while (true){
        i++;
        cout << i;
    }
    int count = 0;
    for (i = 0; i < size; i++) {
        if (arr[i] < arr[i + 1]) {
            count++;
        }
        
    }
    delete[] arr;
    return count;
}
