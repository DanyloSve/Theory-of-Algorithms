#ifndef HEAP_H
#define HEAP_H

#include <vector>

using std::vector;

class Heap
{
private:
    vector<int> mHeap;

    int mLength;
    int mHeapSize;

private:
    int getParentIndex (int i);
    int getLeftIndex   (int i);
    int getRightIndex  (int i);

public:
    Heap(int l = -1, int h = -1):mLength{l}, mHeapSize{h}
    {

    }

    void heapMaxHeapfy(int i);
    void heapBuiltMax();
     int heapGetMax();
    void heapSort();
     int heapExtractMax();
    void heapIncreaseKey(int i, int key);
    void heapMaxInsert(int key);

    void pushIntoVector(int data);
    void showHeap();
    void autoFill();
};

#endif // HEAP_H
