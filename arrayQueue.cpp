/*Circular array implementation of queue*/

#include "arrayQueue.h"
template<class ItemType>
ArrayQueue<ItemType>::ArrayQueue()

{
    front=0;
    back= (DEFAULT_CAPACITY - 1);
    itemCount=0;
}

template<class ItemType>
bool ArrayQueue<ItemType>::isEmpty() const
{
    return itemCount == 0;
}

template<class ItemType>
bool ArrayQueue<ItemType>::enqueue(const ItemType& newEntry)
{
bool result = false;
if (itemCount < DEFAULT_CAPACITY){
    back = (back + 1) % DEFAULT_CAPACITY;
    items[back] = newEntry;
    itemCount++;
    result = true;
}
    return result;
}

template<class ItemType>
bool ArrayQueue<ItemType>::dequeue()
{
bool result = false;
if (!isEmpty()){
    front = (front + 1) % DEFAULT_CAPACITY;
    itemCount--;
    result = true; 
}
    return result;
}

template<class ItemType>
ItemType ArrayQueue<ItemType>::peekFront() const
{
    if (isEmpty()){
        throw "queue is empty!";
    }
    return items[front];
}