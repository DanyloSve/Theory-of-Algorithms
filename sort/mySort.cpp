#include <iostream>

#include <stdio.h>
#include <ctime>

#include "mySort.h"

using std::swap;
using std::cout;

int MySort::partition(int p, int r)
{
    int x = mArray[r];
    int i = p - 1;
    for (int j = p; j <= r - 1; j++)
    {
        if (mArray[j] < x)
        {
            i++;
            swap(mArray[i], mArray[j]);
        }
    }
    swap(mArray[i + 1], mArray[r]);
    return i + 1;
}


void MySort::quickSort(int p, int r)
{
    if (p < r)
    {
        int q = partition(p, r);
        quickSort(p, q - 1);
        quickSort(q + 1, r);
    }
}

void MySort::randomizedQuickSort(int p, int r)
{
    if (p < r)
    {
        int q = randomizedPartition(p, r);
        randomizedQuickSort(p, q - 1);
        randomizedQuickSort(q + 1, r);
    }
}

void MySort::groundIteamSort(int p, int r, int k)
{
    if (p < r)
    {
        int q = groundPartition(p, r, k);
        randomizedQuickSort(p, q - 1);
        randomizedQuickSort(q + 1, r);
    }
}

int MySort::getRandomNumber(int min, int max)
{
    srand(static_cast<unsigned int>(time(0)));

    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

int MySort::randomizedPartition(int p, int r)
{
    int i = getRandomNumber(p, r);
    swap(mArray[r], mArray[i]);

    return partition(p, r);
}

int MySort::groundPartition(int p, int r, int k)
{
    int i = k;
    swap(mArray[r], mArray[i]);

    return partition(p, r);
}

int MySort::randomizedSelect(int p, int q, int k)
{
    if (p == q)
    {
        return  mArray[p];
    }

    int r = randomizedPartition(p, q);
    int t = r - p +1;

    if (k == t)
    {
        return mArray[r];
    }
    else if (k < t)
    {
        return randomizedSelect(p, r - 1, k);
    }
    else
    {
        return randomizedSelect(r + 1, q, k - t);
    }
}


void MySort::bubbleSort()
{
    int i, j;
       for (i = 0; i < mArray.size() - 1; i++)
       {
       for (j = 0; j < mArray.size() - i - 1; j++)
       {
           if (mArray[j] > mArray[j+1])
           {
               swap(mArray[j], mArray[j+1]);
           }
       }
       }
}

void MySort::clearArray()
{
    mArray.clear();
}



void MySort::addIteam(int iteam)
{
    size++;
    mArray.push_back(iteam);
}

void MySort::show()
{
    for (int i{0}; i != mArray.size(); i++)
    {
        cout<<mArray[i] << ' ';
    }
}
