// OrderedPQ.cpp
// Brendan Scharmann, #825291656
// 2024-03-04

#include "OrderedPQ.h"
#include <stdexcept>

int OrderedPQ::findMinIndex() {
    // Find the index of the object with the highest priority that has been in the priority queue the longest
    // first elements priority and index then iterate through the elements 
    // updating the index when a higher priority is encountered
    if (isEmpty()) {
        throw std::invalid_argument("Cannot find minimum index in an empty queue");
    }

  
    int minIndex = 0;
    int minPriority = pq->get(0);

    for (int i = 1; i < pq->size(); ++i) {
        int currentPriority = pq->get(i);
        if (currentPriority < minPriority) {
            minPriority = currentPriority;
            minIndex = i;
        }
    }

    return minIndex;
}

OrderedPQ::OrderedPQ() {
    // Initialize the ordered priority queue using OrderedArrayList
    pq = new OrderedArrayList();
}

OrderedPQ::OrderedPQ(int capacity) {
    // Initialize the ordered priority queue with the specific initial capacity
    pq = new OrderedArrayList(capacity);
}

bool OrderedPQ::insert(int object) {
    // Inserts a new object into the ordered priority queue based on
    // the natural order
    // Utilizes the OrderedArrayLists 'add' method
    // Returns true if the insertion is successful, otherwise false
    return pq->add(object);
}

int OrderedPQ::remove() {
    // Removes the object with the highest priority that has
    // been in the ordered priority queue the longest
    // Uses the 'findMinIndex' method to determine the index of the object to be removed
    if (isEmpty()) {
        throw std::invalid_argument("Cannot remove from empty queue");
    }

    int minIndex = findMinIndex();
    return pq->remove(minIndex);
}

bool OrderedPQ::deleteAll(int obj) {
    // Implement the logic to delete all instances of the parameter object from the priority queue if found
    return pq->removeAll(obj);
}

int OrderedPQ::peek() {
    // Returns the object of highest priority that has been
    // in the ordered priority queue the longest without removing it
    // If the queue is empty throws an exception. Uses the 'findMinIndex' method to
    // determine the index of the object and retrieves it using 'get'.
    if (isEmpty()) {
        throw std::invalid_argument("Cannot peek from empty queue");
    }

    int minIndex = findMinIndex();
    return pq->get(minIndex);
}

bool OrderedPQ::contains(int obj) {
    // Implement the logic to check if the ordered priority queue contains the specified element
    return pq->contains(obj);
}

int OrderedPQ::size() {
    // Implement the logic to return the number of objects currently in the ordered PQ
    return pq->size();
}

void OrderedPQ::clear() {
    // Implement the logic to clear the ordered priority queue
    pq->clear();
}

bool OrderedPQ::isEmpty() {
    // Implement the logic to check if the ordered priority queue is empty
    return pq->isEmpty();
}

bool OrderedPQ::isFull() {
    // Checks if the ordered priority queue is full
    // Always returns false.
    return false;
}

