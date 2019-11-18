#ifndef SORT_H
#define SORT_H

#include <vector>

using std::vector;

class MySort
{
private:
    vector <int> mArray;
    int size;

    int partition(int p, int r);

    int getRandomNumber(int min, int max);
    int randomizedPartition(int p, int r);

public:
    int randomizedSelect(int p, int q, int k);
    void  quickSort(int p, int r);

    void groundIteamSort(int p, int r, int k);
    void randomizedQuickSort(int p, int r);
    int groundPartition(int p, int r, int k);

    void bubbleSort();
    void clearArray();

    void addIteam(int iteam);
    void show();

};

#endif // SORT_H
