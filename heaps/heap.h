#ifndef HEAP_H
#define HEAP_H

#include "node.h"

#include <QVector>
#include <vector>

using std::vector;

class Heap
{
private:
    int mLength; // 2^n - розмір купи
    int mHeapSize; // заповненість купи mHeap.cpacity();
    vector<int> mHeap;

private:
    int parentIndex    (int i);
    int leftNodeIndex  (int i);
    int rightNodeIndex (int i);

public:
    Heap(int h = -1, int l = 0): mHeapSize{h}, mLength{l}
    {

    }

    void heapIncreaseKey (int i, const int &key);
    void maxHeapfy       (const int &i);
    void builtMaxHeap    ();
    void heapSort        ();
     int heapMaximum     ();
     int heapExtractMax  ();
     void maxHeapInsert  (const int &key);

    void addNewIteam(int iteam);
    void showHeap();
    void autoFillingHeap();
};

#endif // HEAP_H
