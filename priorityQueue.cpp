#include "priorityQueue.h"
template<class ItemType>
PriorityQueue<ItemType>::PriorityQueue()
                    : front(0), back(DEFAULT_CAPACITY - 1), itemCount(0)
{
  for (int i = 0; i < DEFAULT_CAPACITY; ++i) {
        items[i] = nullptr;
    }
}

template<class ItemType>
PriorityQueue<ItemType>::~PriorityQueue() {
    for (int i = 0; i < itemCount; ++i) {
        delete items[(front + i) % DEFAULT_CAPACITY];
    }
}

template<class ItemType>
bool PriorityQueue<ItemType>::isEmpty() const
{
    return itemCount == 0;
}

template <class ItemType>
bool PriorityQueue<ItemType>::isFull() const
{
    return itemCount == DEFAULT_CAPACITY;
}

template<class ItemType>
bool PriorityQueue<ItemType>::enqueue(const ItemType& newEntry) {
    if (isFull()) {
        return false;
    }

    // Allocate memory for the new item
    ItemType* newItem = new ItemType(newEntry);

    // Find the correct position to insert the new item in sorted order
    int i = itemCount - 1;
    int insertPos = (back + 1) % DEFAULT_CAPACITY;

    // Start from the last item and shift larger items one position to the right
    while (i >= 0) {
        int currentPos = (front + i) % DEFAULT_CAPACITY;

        if (*items[currentPos] > *newItem) {
            items[insertPos] = items[currentPos];
            insertPos = currentPos;
            i--;
        } else {
            break;
        }
    }

    // Insert the new item at the correct position
    items[insertPos] = newItem;

    // Update back and count
    back = (back + 1) % DEFAULT_CAPACITY;
    itemCount++;
    return true;
}


template<class ItemType>
bool PriorityQueue<ItemType>::dequeue() {
    if (isEmpty()) {
        return false;
    }

    // Delete the front item to avoid memory leaks
    delete items[front];

    // Update front and decrease count
    front = (front + 1) % DEFAULT_CAPACITY;
    itemCount--;
    return true;
}

template<class ItemType>
ItemType PriorityQueue<ItemType>::peekFront() const
{
    if (isEmpty()){
        throw "queue is empty!";
    }
    return *items[front];
}