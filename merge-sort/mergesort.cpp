#include <cmath>
#include "mergesort.h"

#include <iostream>

static int i;

MergeSort::MergeSort()
{

}

void MergeSort::sort()
{
    for (double a : v)
    {
        std::cout << a << ' ';
    }
    std::cout << '\n';

}

void MergeSort::getIterations()
{
    int b = i;
    std::cout << b;
}

void MergeSort::mergeSort(int p, int q)
{
    if(q - p < 1)
    {
        return ;
    }

    int c = floor((p + q) / 2);

    if (q - p > 1)
    {
        mergeSort(p, c);
        mergeSort(c + 1, q);
    }

    //sort();
    merge(p, c, q);
}

void MergeSort::merge(int p, int c, int q)
{
    std::vector <int> b;
    for (int i{0}; i != v.size(); i++)
    {
        b.push_back(0);
    }

    int i = p;
    int j = c + 1;

    for (int k{p}; k <= q; k++)
    {
        if ( (j > q) || ( (i <= c) && (v[i] <= v[j])) )
        {
             b[k] = v[i];
             i++;
        }
        else
        {
            b[k] = v[j];
            j++;
        }
    }


    sort();
    std::cout << "Iterations : " << i << '\n';
    i++;

    for (int k{p}; k <= q; k++)
    {
        v[k] = b[k];
    }
}

void MergeSort::addIteam(double iteam)
{
    v.push_back(iteam);
}

std::vector<double> MergeSort::getArray()
{
    return  v;
}
