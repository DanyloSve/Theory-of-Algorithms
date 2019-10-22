#include <iostream>
#include <bits/stdc++.h>

using std::swap;
using std::cout;
using std::cin;

#include "heap.h"

int Heap::getParentIndex(int i)
{
    return (i - 1) / 2;
}

int Heap::getLeftIndex(int i)
{
    return  2 * i + 1;
}

int Heap::getRightIndex(int i)
{
    return 2 * i + 2;
}

void Heap::heapMaxHeapfy(int i)
{
    int left = getLeftIndex(i);
    int right = getRightIndex(i);
    int largest = i;

    if (left <= mHeapSize && mHeap[left] > mHeap[largest])
    {
        largest = left;
    }

    if (right <= mHeapSize && mHeap[right] > mHeap[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(mHeap[i], mHeap[largest]);
        heapMaxHeapfy(largest);
    }
}

void Heap::heapBuiltMax()
{
    mHeapSize = mLength;

    for (int i{mHeapSize / 2}; i != -1; i--)
    {
        heapMaxHeapfy(i);
    }

    mHeapSize = mLength;
}

int Heap::heapGetMax()
{
    heapBuiltMax();

    return mHeap[0];
}


void Heap::heapSort()
{
    heapBuiltMax();

    for (int i{mLength}; i != -1; i--)
    {
        swap(mHeap[0], mHeap[i]);
        mHeapSize--;
        heapMaxHeapfy(0);
    }

    mHeapSize = mLength;
}

int Heap::heapExtractMax()
{
    heapBuiltMax();

    if (mHeapSize < 0)
    {
        cout << "Heap is empty!\n";
    }
    else
    {
        int max = mHeap[0];
        mHeap[0] = mHeap[mHeapSize];
        mHeapSize--;
        mLength--;
        heapMaxHeapfy(0);
        return max;
    }
}

void Heap::heapIncreaseKey(int i, int key)
{
    if (key < mHeap[i])
    {
        cout << "New key is smaller than previous!\n";
    }
    else
    {
        mHeap[i] = key;
        while (i != 0 && mHeap[getParentIndex(i)] < mHeap[i])
        {
            swap(mHeap[i], mHeap[getParentIndex(i)]);
            i = getParentIndex(i);
        }
    }
}

void Heap::heapMaxInsert(int key)
{
    mHeapSize++;
    mLength++;

    mHeap[mHeapSize] = INT_MIN;
    heapIncreaseKey(mHeapSize, key);
}

void Heap::pushIntoVector(int data)
{
   mHeapSize++;
   mLength++;

   mHeap.push_back(data);
}

void Heap::showHeap()
{
    if (mHeapSize < 0)
    {
        cout << "Heap is empty!";
    }
    else
    {
        for (int i{0}; i < mLength + 1; i++)
        {
            cout << mHeap[i] <<' ';
        }
    }
}

void Heap::autoFill()
{
    mHeap = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    mLength = 9;
    mHeapSize = 9;
}
