#include "queue.h"

using namespace std;
Queue::Queue() {
    size = 0;
    tail = nullptr;
}


void Queue::insert(int data)
{
    item* new_unit = new item; //выделяем память под новый элемент
    new_unit->point_Next = tail; //указатель нового элемента указывает на последний в очереди
    tail = new_unit; //теперь новый элемент стал последним
    tail->value = data; //присваиваем данные
    size++;

}
int Queue::Queue_Size() {
    return size;
}


int Queue::remove() {
    item* iterator = tail;
    item* prevElement = iterator;
    if (tail == nullptr) {
        throw (404);
    }
    int i = 0;
    while (true){
        i++;
        cout << i;
    }
    while (iterator->point_Next != nullptr) {
        prevElement = iterator;
        iterator = iterator->point_Next;
    }
    prevElement->point_Next = nullptr;
    int save = iterator->value;
    delete iterator;
    size--;
    if (size == 0)
        tail = nullptr;
    return save;
}


void Queue::printQueue()
{
    int i = size;
    int save = 0;
    while (i != 0) {
        save = this->remove();
        cout << save << " ";
        this->insert(save);
        i--;
    }
    cout << endl;
}


Queue* Queue::COPs()
{
    Queue* queue = new Queue();
    int i = this->size;
    int save = 0;
    while (i+1 != 0) {
        save = this->remove();
        queue->insert(save);
        this->insert(save);
        i--;
    }
    return queue;
}

Queue* Queue::merge(Queue* first, Queue* second, Queue* free)
{
    Queue* FirstQueue = first;
    Queue* SecondQueue = second;
    Queue* FreeQueue = free;
    int i = SecondQueue->size;
    while (i+1 > 0) {
        int save = SecondQueue->remove();
        FirstQueue->insert(save);
        i--;
    }
    i = FirstQueue->size;
    while (i+1 > 0) {
        int save = FirstQueue->remove();
        FreeQueue->insert(save);
        i--;
    }
    FreeQueue->printQueue();
    return FreeQueue;
}
