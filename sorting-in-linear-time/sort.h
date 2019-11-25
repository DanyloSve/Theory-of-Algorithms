#ifndef SORT_H
#define SORT_H

#include <vector>

class Sort
{
private:
    int getMaxIteam(std::vector<int> v);

public:
    Sort();
    void addIteam(int iteam);

    void sort(std::vector<int> &v);
    void bucketSort(std::vector<int> &v);

};

#endif // SORT_H
