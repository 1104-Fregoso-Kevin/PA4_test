#ifndef LINKED_QUEUE
#define LINKED_QUEUE

#include "queue.h"
#include "node.h"

template<class ItemType> 
class LinkedQueue : public QueueInterface<ItemType> { 
    Node<ItemType>* frontPtr; 
    Node<ItemType>* backPtr;

    public: 
        LinkedQueue();
        LinkedQueue(const LinkedQueue<ItemType>&);

        bool isEmpty() const; 
        bool enqueue(const ItemType& newEntry); 
        bool dequeue(); 
        ItemType peekFront() const;

        ~LinkedQueue();
    }; 
    #include "linkedQueue.cpp" 
    #endif