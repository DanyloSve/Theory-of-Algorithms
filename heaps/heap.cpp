#include <algorithm>
#include <iostream>

using std::cout;

#include "heap.h"

using std::swap;

int Heap::parentIndex(int i)
{
    int result = (i - 1) >> 1;
}

int Heap::leftNodeIndex(int i)
{
    return ( (i << 1) + 1);
}

int Heap::rightNodeIndex(int i)
{
    return (i << 1) + 2;
}

//
void Heap::heapIncreaseKey(int i, const int &key)
{
    if (key < mHeap[i])
    {
        cout << "New key is smaller then previous\n";
    }
    else
    {
        mHeap[i] = key;
        while(i >= 1 && mHeap[parentIndex(i)] < mHeap[i] && parentIndex(i) >= 0)
        {
            swap(mHeap[i], mHeap[parentIndex(i)]);
            i = parentIndex(i);
        }
    }
}


void Heap::maxHeapfy(const int &i)
{
   int leftIndex = leftNodeIndex(i);
   int rightIndex = rightNodeIndex(i);

   int largest;

   if (leftIndex <= mHeapSize && mHeap[leftIndex] > mHeap[i])
   {
       largest = leftIndex;
   }
   else
   {
       largest = i;
   }

   if (rightIndex <= mHeapSize && mHeap[rightIndex] > mHeap[largest])
   {
       largest = rightIndex;
   }

   if (largest != i)
   {
       swap(mHeap[i], mHeap[largest]);
       maxHeapfy(largest);
   }
}

void Heap::builtMaxHeap()
{
    mHeapSize = mLength - 1;

   for (int i{mLength / 2}; i != -1; i--)
   {
       maxHeapfy(i);
   }
}

void Heap::heapSort()
{
    builtMaxHeap();
    int temp = mHeapSize;
    for (int i{mHeapSize}; i > 0; i--)
    {
        swap(mHeap[0], mHeap[i]);
        mHeapSize = mHeapSize - 1;
        maxHeapfy(0);
    }
    mHeapSize = temp;
}

int Heap::heapMaximum()
{
    builtMaxHeap();
    return mHeap[0];
}

//
int Heap::heapExtractMax()
{
    if (mHeapSize == -1)
    {
        cout << "Queue is empty\n";
    }
    else
    {
        builtMaxHeap();
        int max = mHeap[0];
        mHeap[0] = mHeap[mHeapSize];
        mHeapSize--;
        mLength--;

        maxHeapfy(0);
        return max;
    }
}

void Heap::showHeap()
{
    if (mHeap.empty())
    {
        cout << "Heap is empty\n";
        return;
    }

    cout << "Heap : ";
    for (int i{0}; i < mLength; i++)
    {
        cout << mHeap[i] << ' ';
    }
    cout << '\n';
}

void Heap::maxHeapInsert(const int &key)
{
    int mInf = INT_MIN;

    if (mHeapSize == -1)
    {
        mHeapSize = 0;
        mLength = 1;
    }
    else
    {
        mHeapSize++;
        mLength++;
    }
    mHeap[mHeapSize] = mInf;
    heapIncreaseKey(mHeapSize,key);
}

void Heap::addNewIteam(int iteam)
{
    if (mHeapSize == -1)
    {
        mHeapSize = 0;
        mLength = 1;

    }
    else
    {
        mLength++;
        mHeapSize++;
    }
    mHeap.push_back(iteam);
}

void Heap::autoFillingHeap()
{
    mHeap = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    mLength = 10;
    mHeapSize = 9;
}

