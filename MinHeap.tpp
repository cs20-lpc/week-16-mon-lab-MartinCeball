template <typename T>
void MinHeap<T>::siftUp(int i) {
    // While not root and parent is greater than current node
    while (i > 0 && data[(i - 1) / 2] > data[i]) {
        swap(data[i], data[(i - 1) / 2]);
        i = (i - 1) / 2; // Move up to parent's index
    }
}

template <typename T>
void MinHeap<T>::siftDown(int i) {
    int size = data.size();
    while (true) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        // Check if left child exists and is smaller than current smallest
        if (left < size && data[left] < data[smallest])
            smallest = left;

        // Check if right child exists and is smaller than current smallest
        if (right < size && data[right] < data[smallest])
            smallest = right;

        // If the smallest is still current, heap property is restored
        if (smallest == i) break;

        swap(data[i], data[smallest]);
        i = smallest; // Continue sifting down
    }
}

template <typename T>
void MinHeap<T>::insert(const T& value) {
    data.push_back(value);   // Add to the end to maintain complete tree
    siftUp(data.size() - 1); // Restore heap property upward
}

template <typename T>
T MinHeap<T>::removeRoot() {
    if (data.empty()) throw runtime_error("Heap is empty");

    T rootValue = data[0];
    data[0] = data.back(); // Move last element to root
    data.pop_back();       // Remove last element

    if (!data.empty()) {
        siftDown(0); // Restore heap property downward
    }
    return rootValue;
}

template <typename T>
void MinHeap<T>::removeAt(int index) {
    if (index < 0 || index >= (int)data.size())
        throw runtime_error("Invalid index");

    // Replace target with the last element
    data[index] = data.back();
    data.pop_back();

    if (index < (int)data.size()) {
        // Attempt to sift up (in case the new value is very small)
        siftUp(index);
        // Attempt to sift down (in case the new value is very large)
        siftDown(index);
    }
}
