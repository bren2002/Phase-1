// OrderedArrayList.cpp
// Brendan Scharmann, #825291656 
// 2024 - 02 - 27
#include "OrderedArrayList.cpp"
OrderedArrayList::OrderedArrayList() {
    // Initialize the array and other variables
    // Set initial values
    array = nullptr;
    capacity = 0;
    currentSize = 0;
}

OrderedArrayList::OrderedArrayList(int initialCapacity) {
    // Initialize the array with the specific initial capacity
    array = new int[initialCapacity];
    capacity = initialCapacity;
    currentSize = 0;
}

bool OrderedArrayList::add(int data) {
    // Implement the logic to add data to the ordered array
    // Return true if correct, false otherwise
}

bool OrderedArrayList::add(int index, int data) {
    // Implement the logic to add data at the specific index
    // Return true if correct, false otherwise
}

void OrderedArrayList::clear() {
    // Put in the logic to clear the list
}

bool OrderedArrayList::contains(int data) {
    // Implement the logic to check if the list contains the specified data
    // Return true if found, false otherwise
}

int OrderedArrayList::get(int index) {
    // Put in the logic to get the element at the specified index
    // Return the element if index is valid, otherwise 
}

int OrderedArrayList::remove(int index) {
    // Put in the logic to remove the element at the specified index
    // Return the removed element if index is correct, otherwise 
}

bool OrderedArrayList::removeAll(int data) {
    // Put in the logic to remove all times the specified data
    // Return true if at least one time is removed, false otherwise
}

int OrderedArrayList::indexOf(int data) {
    // Put in the logic to find the index of the first time of the specified data
    // Return the index if found, otherwise return -1
}

bool OrderedArrayList::isEmpty() {
    // Put in the logic to check if the list is empty
    // Return true if empty, false otherwise
}

int OrderedArrayList::size() {
    // Put in the logic to get the size of the list
    // Return the current size
}

void OrderedArrayList::trimToSize() {
    // Put in the logic to trim the capacity of the list to its current size
    // If needed resize the array to match the current size
}
