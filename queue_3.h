#pragma once
#include "queue.h"
class Queue_3 :private Queue
{
public:
    int math_operation();
    void insert(int data);
    int remove();
    void printQueue();
    Queue* COPs();
    static Queue* merge(Queue* first, Queue* second, Queue* free);
};
