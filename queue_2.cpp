#include "queue_2.h"
int Queue_2::math_operation()
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
    int count = 0;
    for (i = 0; i < size; i++) {
        if (arr[i] < arr[i + 1]) {
            count++;
        }

    }
    delete[] arr;
    return count;
}

void Queue_2::insert(int data) {
    Queue::insert(data);
}

int Queue_2::remove() {
    return Queue::remove();
}

void Queue_2::printQueue() {
    Queue::printQueue();
}

Queue* Queue_2::COPs()
{
    return Queue::COPs();
}



Queue* Queue_2::merge(Queue* first, Queue* second, Queue* free) {
    return Queue::merge(first, second, free);
}
