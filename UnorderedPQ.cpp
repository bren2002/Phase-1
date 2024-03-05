// UnorderedPQ.cpp
// Brendan Scharmann, #825291656
// 2024-03-04

#include "UnorderedPQ.h"
#include <stdexcept>

int UnorderedPQ::findMinIndex() {
    // Finds the index of the object with the highest priority
    // That has been in the unordered priority queue the longest
    if (isEmpty()) {
        throw std::invalid_argument("Cannot find minimum index in an empty queue");
    }
    // Initialize variables to store the index and priority of the minimum element
    int minIndex = 0;
    int minPriority = pq->get(0);
    // Iterate through the elements to find the one with the highest priority
    for (int i = 1; i < pq->size(); ++i) {
        int currentPriority = pq->get(i);
        // Compare the current priority with the minimum priority
        if (currentPriority < minPriority) {
            minPriority = currentPriority;
            minIndex = i;
        }
    }

    return minIndex;
}

UnorderedPQ::UnorderedPQ() {
    // Initialize the unordered priority queue using UnorderedArrayList
    pq = new UnorderedArrayList();
}

UnorderedPQ::UnorderedPQ(int capacity) {
    // Initialize the unordered priority queue with the specific initial capacity
    pq = new UnorderedArrayList(capacity);
}

bool UnorderedPQ::insert(int object) {
    // Inserts a new object into the unordered priority queue without any specific order  
    // Utilizes the 'add' method of the underlying UnorderedArrayList
    // Returns true if the insertion is successful otherwise false
    return pq->add(object);
}

int UnorderedPQ::remove() {
    // Removes the object with the highest priority 
    // Uses the 'findMinIndex' method to determine the index of the object to be removed
    // Then calls 'remove' on the underlying UnorderedArrayList  
    // Returns the removed object
    if (isEmpty()) {
        throw std::invalid_argument("Cannot remove from empty queue");
    }

    int minIndex = findMinIndex();
    return pq->remove(minIndex);
}

bool UnorderedPQ::deleteAll(int obj) {
    // Deletes all instances of the specified object from the unordered priority queue
    // Utilizes the 'removeAll' method of the underlying UnorderedArrayList
    return pq->removeAll(obj);
}

int UnorderedPQ::peek() {
    // Returns the object of highest priority without removing it
    // Uses the 'findMinIndex' method to determine the index of the object and collects it using 'get'
    if (isEmpty()) {
        throw std::invalid_argument("Cannot peek from empty queue");
    }

    int minIndex = findMinIndex();
    return pq->get(minIndex);
}

bool UnorderedPQ::contains(int obj) {
    // Implement the logic to check if the unordered priority queue contains the specified element
    return pq->contains(obj);
}

int UnorderedPQ::size() {
    // Implement the logic to return the number of objects currently in the unordered priority queue
    return pq->size();
}

void UnorderedPQ::clear() {
    // Implement the logic to clear the unordered priority queue
    pq->clear();
}

bool UnorderedPQ::isEmpty() {
    // Implement the logic to check if the unordered priority queue is empty
    return pq->isEmpty();
}

bool UnorderedPQ::isFull() {
    // Checks if the unordered priority queue is full
    // It can never be full as we are using a list based implementation
    // Always returns false
    return false;
}
