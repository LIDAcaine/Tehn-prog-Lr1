#include "queue_3.h"
int Queue_3::math_operation()
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

void Queue_3::insert(int data) {
    Queue::insert(data);
}

int Queue_3::remove() {
    return Queue::remove();
}

void Queue_3::printQueue() {
    Queue::printQueue();
}

Queue* Queue_3::COPs()
{
    return Queue::COPs();
}

Queue* Queue_3::merge(Queue* first, Queue* second, Queue* free) {
    return Queue::merge(first, second, free);
}
