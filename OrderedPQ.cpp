// OrderedPQ.cpp
// Brendan Scharmann, #825291656
// 2024-03-04

#include "OrderedPQ.h"
#include <stdexcept>


int OrderedPQ::findMinIndex() {

    // Find the index of the object with the highest priority that has been in the priority queue the longest
    // Throws an exception if the queue is empty
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

OrderedPQ::OrderedPQ() {
    // Create a new ordered priority queue using the OrderedArrayList
    pq = new OrderedArrayList();
}

OrderedPQ::OrderedPQ(int capacity) {
    // Create a new ordered priority queue with a specified capacity using the OrderedArrayList
    pq = new OrderedArrayList(capacity);
}

bool OrderedPQ::insert(int object) {
    // Insert a new object into the ordered priority queue based on the natural order
    // Utilizes the OrderedArrayList's 'add' method
    return pq->add(object);
}

int OrderedPQ::remove() {
    // Check if the ordered priority queue is empty
    if (isEmpty()) {
        throw std::invalid_argument("Cannot remove from empty queue");
    }

     // Find the index of the object with the highest priority in the ordered priority queue
    int minIndex = findMinIndex();
    return pq->remove(minIndex);
}

bool OrderedPQ::deleteAll(int obj) {
    // Delete all instances of the specified object from the ordered priority queue
    return pq->removeAll(obj);
}

int OrderedPQ::peek() {
    // Returns the object of highest priority that has been in the ordered priority queue the longest without removing it
    // Uses the 'findMinIndex' method to determine the index of the object and collects it using 'get'
    if (isEmpty()) {
        throw std::invalid_argument("Cannot peek from empty queue");
    }

    // Find the index of the object with the highest priority in the ordered priority queue
    int minIndex = findMinIndex();
    return pq->get(minIndex);
}

bool OrderedPQ::contains(int obj) {
    // Check if the ordered priority queue contains the specified element
    return pq->contains(obj);
}

int OrderedPQ::size() {
    // Return the number of objects currently in the ordered priority queue
    return pq->size();
}

void OrderedPQ::clear() {
    // Clear the ordered priority queue by utilizing the 'clear' method of OrderedArrayList
    pq->clear();
}

bool OrderedPQ::isEmpty() {
    // Check if the ordered priority queue is empty by using the 'isEmpty' method of OrderedArrayList
    return pq->isEmpty();
}

bool OrderedPQ::isFull() {
    // Check if the ordered priority queue is full
    // Always returns false
    return false;
}

