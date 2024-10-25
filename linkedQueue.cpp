#include "linkedQueue.h"
template<class ItemType> 
LinkedQueue<ItemType>::LinkedQueue(){
    frontPtr = nullptr;
    backPtr = nullptr;
}

template<class ItemType> 
LinkedQueue<ItemType>::LinkedQueue(const LinkedQueue<ItemType>& rhs){
    if(rhs.frontPtr != nullptr){
        Node<ItemType>* oldQPtr = rhs.frontPtr;

        Node<ItemType>* newNodePtr = new Node<ItemType>();
        newNodePtr->setItem(oldQPtr->getItem());

        frontPtr = backPtr = newNodePtr;

        oldQPtr = oldQPtr->getNext();

        while(oldQPtr != nullptr){
            newNodePtr = new Node<ItemType>();
            newNodePtr->setItem(oldQPtr->getItem());
            backPtr->setNext(newNodePtr);
            backPtr = newNodePtr;
            oldQPtr = oldQPtr->getNext();
        }
    }
}

template<class ItemType> 
bool LinkedQueue<ItemType>::isEmpty() const{
    return frontPtr == nullptr;
}


template<class ItemType> 
bool LinkedQueue<ItemType>::enqueue(const ItemType& newEntry){
    Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);

    if(isEmpty()){
        frontPtr = newNodePtr;
    }
    else{
        backPtr->setNext(newNodePtr);
    }
    backPtr = newNodePtr;
    newNodePtr = nullptr;

    return true;
}


template<class ItemType> 
bool LinkedQueue<ItemType>::dequeue(){
    bool canDq = !isEmpty();

    if(canDq){
        Node<ItemType>* nodeToDeletePtr = frontPtr;

        frontPtr = frontPtr->getNext();

        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;
        nodeToDeletePtr = nullptr;
    } 
 
    return canDq;
}


template<class ItemType> 
ItemType LinkedQueue<ItemType>::peekFront() const{
    bool canPeek = !isEmpty();

    if(canPeek){
        return frontPtr->getItem();
    }
    else{
        throw "empty queue";
    }
}


template<class ItemType> 
LinkedQueue<ItemType>::~LinkedQueue(){
    while(dequeue());
}