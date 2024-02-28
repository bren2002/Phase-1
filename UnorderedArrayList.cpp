// UnorderedArrayList.cpp
// Brendan Scharmann, #825291656 
// 2024 - 02 - 27
#include "UnorderedArrayList.h"
UnorderedArrayList::UnorderedArrayList() {
    // Initialize the array and other variables
    // Set initial values
    array = nullptr;
    capacity = 0;
    currentSize = 0;
}

UnorderedArrayList::UnorderedArrayList(int initialCapacity) {
    // Initialize the array with the specific initial capacity
    array = new int[initialCapacity];
    capacity = initialCapacity;
    currentSize = 0;
}

bool UnorderedArrayList::add(int data) {
    // Put in the logic to add data to the unordered array
    // Return true if correct, false otherwise
    if (currentSize < capacity) {
        array[currentSize++] = data;
        return true;
    } else {
        // Handle the case when the array is full
        return false;
    }
}

bool UnorderedArrayList::add(int index, int data) {
    // Put in the logic to add data at the specific index
    // Return true if correct, false otherwise
    if (index >= 0 && index <= currentSize && currentSize < capacity) {
        // Add the logic to add data at the specified index
        // Update the array and currentSize
        for (int i = currentSize; i > index; --i) {
            array[i] = array[i - 1];
        }
        array[index] = data;
        ++currentSize;
        return true;
    } else {
        // Handle the case when the index is out of bounds or the array is full
        return false;
    }
}
void UnorderedArrayList::clear() {
    // Implement the logic to clear the array
    currentSize = 0;
}

bool UnorderedArrayList::contains(int data) {
    // Implement the logic to check if the array contains the specified data
    for (int i = 0; i < currentSize; ++i) {
        if (array[i] == data) {
            return true;
        }
    }
    return false;
}

int UnorderedArrayList::get(int index) {
    // Implement the logic to get the data at the specified index
    if (index >= 0 && index < currentSize) {
        return array[index];
    } else {
        // Handle the case when the index is out of bounds
        throw std::out_of_range("Index out of bounds");
    }
}

int UnorderedArrayList::remove(int index) {
    // Implement the logic to remove the data at the specified index
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

bool UnorderedArrayList::removeAll(int data) {
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
        }
    }
    return dataRemoved;
}

int UnorderedArrayList::indexOf(int data) {
    // Implement the logic to find the index of the first occurrence of the specified data
    for (int i = 0; i < currentSize; ++i) {
        if (array[i] == data) {
            return i;
        }
    }
    return -1; // Return -1 if data is not found
}

bool UnorderedArrayList::isEmpty() {
    // Implement the logic to check if the array is empty
    return currentSize == 0;
}

int UnorderedArrayList::size() {
    // Implement the logic to get the size of the array
    return currentSize;
}

void UnorderedArrayList::trimToSize() {
    // Implement the logic to trim the capacity of the array to its current size
    int* newArray = new int[currentSize];
    for (int i = 0; i < currentSize; ++i) {
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
    capacity = currentSize;
}
