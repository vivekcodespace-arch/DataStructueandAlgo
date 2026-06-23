#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>  // std::swap

// A simple binary max-heap stored in a 0-based array (std::vector).
// For a node at index i:
//   left child  = 2*i + 1
//   right child = 2*i + 2
//   parent      = (i - 1) / 2
class MaxHeap {
    std::vector<int> heap;

    // Push the element at index i DOWN until the heap property holds.
    // Used after deletion, when a small value lands near the top.
    void siftDown(int i) {
        int n = static_cast<int>(heap.size());
        while (true) {
            int largest = i;
            int l = 2 * i + 1;
            int r = 2 * i + 2;

            if (l < n && heap[l] > heap[largest]) largest = l;
            if (r < n && heap[r] > heap[largest]) largest = r;

            if (largest == i) break;          // already bigger than both children
            std::swap(heap[i], heap[largest]);
            i = largest;                       // follow the element down
        }
    }

    // Push the element at index i UP until the heap property holds.
    // Used after insertion, or when an arbitrary deletion leaves a value
    // that is too LARGE for its new position.
    void siftUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap[i] > heap[parent]) {
                std::swap(heap[i], heap[parent]);
                i = parent;
            } else {
                break;
            }
        }
    }

public:
    explicit MaxHeap(std::vector<int> values = {}) : heap(std::move(values)) {
        // If seeded with raw data, turn it into a valid heap in O(n)
        // by sifting down every non-leaf node, bottom-up.
        for (int i = static_cast<int>(heap.size()) / 2 - 1; i >= 0; --i)
            siftDown(i);
    }

    bool   empty() const { return heap.empty(); }
    size_t size()  const { return heap.size(); }
    int    peek()  const {                       // the max, without removing it
        if (heap.empty()) throw std::out_of_range("heap is empty");
        return heap[0];
    }

    void insert(int value) {
        heap.push_back(value);                   // add at the end
        siftUp(static_cast<int>(heap.size()) - 1);
    }

    // --- Deletion of the root (the maximum) -------------------------------
    // 1. Save the root value (this is what we return).
    // 2. Move the LAST element into the root slot, then shrink the heap.
    // 3. Sift that element down until order is restored.
    // Runs in O(log n).
    int extractMax() {
        if (heap.empty()) throw std::out_of_range("heap is empty");

        int maxVal = heap[0];
        heap[0] = heap.back();   // last element fills the hole at the root
        heap.pop_back();         // shrink the heap (don't forget this step!)

        if (!heap.empty()) siftDown(0);
        return maxVal;
    }

    // --- Deletion of an arbitrary element by index ------------------------
    // Same idea as extractMax, but the replacement might be too BIG for its
    // new spot rather than too small, so we pick the one direction needed.
    void deleteAt(int i) {
        int n = static_cast<int>(heap.size());
        if (i < 0 || i >= n) throw std::out_of_range("index out of range");

        heap[i] = heap.back();
        heap.pop_back();

        // If we removed the last element, there is nothing left to fix.
        if (i < static_cast<int>(heap.size())) {
            if (i > 0 && heap[i] > heap[(i - 1) / 2])
                siftUp(i);       // replacement is larger than its parent
            else
                siftDown(i);     // otherwise it may need to sink
        }
    }

    void print() const {
        std::cout << "[ ";
        for (int v : heap) std::cout << v << ' ';
        std::cout << "]\n";
    }
};

int main() {
    // Same heap as the diagram: 50 at the root, 15 as the last leaf.
    MaxHeap h({50, 30, 40, 10, 20, 35, 15});

    std::cout << "Initial heap:        ";
    h.print();

    int removed = h.extractMax();   // delete the root (50)
    std::cout << "Removed max (" << removed << ")\n";
    std::cout << "After extractMax:    ";
    h.print();                      // expect 40 at the front

    h.insert(60);                   // round-trip demo: add a new max
    std::cout << "After insert(60):    ";
    h.print();

    h.deleteAt(2);                  // arbitrary deletion by index
    std::cout << "After deleteAt(2):   ";
    h.print();

    return 0;
}