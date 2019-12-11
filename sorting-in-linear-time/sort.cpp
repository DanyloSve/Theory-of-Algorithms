#include "sort.h"

#include <iostream>
#include <vector>

Sort::Sort()
{

}

int Sort::getMaxIteam(std::vector<int> v)
{
    int rMaxIteam = 0;
    for (int i{0}; i != v.size(); i++)
    {
        if (rMaxIteam < v[i])
        {
            rMaxIteam = v[i];
        }
    }

    return rMaxIteam;
}


void Sort::countingSort(std::vector<int> &v)
{
    int maxIteam = getMaxIteam(v);
    std::vector<int> tempArr(maxIteam + 1);

    for (int i{0}; i != v.size(); i++)
    {
        tempArr[v[i]] = tempArr[v[i]] + 1;
    }

    for (int i{1}; i != maxIteam + 1; i++)
    {
        tempArr[i] = tempArr[i] + tempArr[i - 1];
    }

    std::vector<int> sortResult(v.size() + 1);

    for (int i = v.size() - 1; i != -1; i--)
    {
        sortResult[tempArr[v[i]]] = v[i];
        tempArr[v[i]] = tempArr[v[i]] - 1;
    }


    for (int i{0}; i != v.size(); i++)
    {
        v[i] = sortResult[i + 1];
    }
}

void Sort::bucketSort(std::vector<int> &v)
{
    std::vector<int> buckets[v.size() + 1];
    int maxItem = getMaxIteam(v);

    for (int i{0}; i != v.size(); i++)
    {
        buckets[v.size() * v[i] / maxItem].push_back(v[i]);
    }

    for (int i{0}; i != v.size() + 1; i++)
    {
        if (buckets[i].size() > 1)
        {
            countingSort(buckets[i]);
        }
    }

    for (int i{0}, k{0}; i != v.size() + 1; i++)
    {
        std::cout << "[" << i << "]" << ' ';
        if (buckets[i].size())
        {
            for (int j{0}; j != buckets[i].size(); j++)
            {
                std::cout << buckets[i][j] << ' ';
                v[k] = buckets[i][j];
                k++;
            }
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}


