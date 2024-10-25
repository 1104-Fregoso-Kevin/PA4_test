#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE 

#include "queue.h"
template<class ItemType> 
class PriorityQueue : public QueueInterface<ItemType> { 
    private:
    static const int DEFAULT_CAPACITY = 100;
    ItemType* items[DEFAULT_CAPACITY];
    int front;
    int back;
    int itemCount;

    public: 
        PriorityQueue();
        ~PriorityQueue();

        bool isEmpty() const; 
        bool isFull() const;
        bool enqueue(const ItemType& newEntry); 
        bool dequeue(); 
        ItemType peekFront() const;
    };
#include "priorityQueue.cpp"
#endif
