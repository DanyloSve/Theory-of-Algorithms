#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>

class MergeSort
{
private:
    std::vector<double> v;


public:

    MergeSort();

    void mergeSort(int p, int q);
    void merge(int p, int c, int q);
    void addIteam(double iteam);

    void sort();

    void getIterations();

    std::vector <double> getArray();
};

#endif // MERGESORT_H
