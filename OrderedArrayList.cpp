// OrderedArrayList.cpp
// Brendan Scharmann, #825291656 
// 2024 - 02 - 27
#include "OrderedArrayList.h"
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
    if (currentSize < capacity) {        
        return true;
    } else {
        return false;
    }
}

bool OrderedArrayList::add(int index, int data) {
    // Implement the logic to add data at the specific index
    // Return true if correct, false otherwise
    if (index >= 0 && index <= currentSize && currentSize < capacity) {
        return true;
    } else {
        return false;
    }
}

void OrderedArrayList::clear() {
    currentSize = 0;
}

bool OrderedArrayList::contains(int data) {
    // Implement the logic to check if the list contains the specified data
    for (int i = 0; i < currentSize; ++i) {
        if (array[i] == data) {
            return true;
        } else if (array[i] > data) {
            break; 
        }
    }
    return false;
}

int OrderedArrayList::get(int index) {
    // Implement the logic to get the element at the specified index
    if (index >= 0 && index < currentSize) {
        return array[index];
    } else {
        // Handle the case when the index is out of bounds
        throw std::out_of_range("Index out of bounds");
    }
}

int OrderedArrayList::remove(int index) {
    // Implement the logic to remove the element at the specified index
    if (index >= 0 && index < currentSize) {
        int removedData = array[index];
        for (int i = index; i < currentSize - 1; ++i) {
            array[i] = array[i + 1];
        }
        --currentSize;
        return removedData;
    } else {
        // Handle the case when the index is out of bounds
        throw std::out_of_range("Index out of bounds");
    }
}

bool OrderedArrayList::removeAll(int data) {
    // Implement the logic to remove all occurrences of the specified data
    bool dataRemoved = false;
    for (int i = 0; i < currentSize; ++i) {
        if (array[i] == data) {
            for (int j = i; j < currentSize - 1; ++j) {
                array[j] = array[j + 1];
            }
            --currentSize;
            dataRemoved = true;
            --i; // Check the same index again in case of consecutive occurrences
        } else if (array[i] > data) {
            break; 
        }
    }
    return dataRemoved;
}

int OrderedArrayList::indexOf(int data) {
    // Implement the logic to find the index of the first occurrence of the specified data
    for (int i = 0; i < currentSize; ++i) {
        if (array[i] == data) {
            return i;
        } else if (array[i] > data) {
            break; 
        }
    }
    return -1; // Return -1 if data is not found
}

bool OrderedArrayList::isEmpty() {
    return currentSize == 0;
}

int OrderedArrayList::size() {
    return currentSize;
}

void OrderedArrayList::trimToSize() {
    // Implement the logic to trim the capacity of the list to its current size
    int* newArray = new int[currentSize];
    for (int i = 0; i < currentSize; ++i) {
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
    capacity = currentSize;
}
