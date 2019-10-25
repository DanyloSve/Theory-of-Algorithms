#include "dsu.h"
#include <iostream>

void DSU::set_make(int *previous, const int cPreviousSize)
{
    for (int i{0}; i < cPreviousSize; i++)
    {
        previous[i] = i;
    }
}

bool DSU::set_find(Edge &A)
{
    return (A.mFirstNode != A.mSecondNode);
}

void DSU::set_union(Edge &A, int *previous, const int cPreviousSize, int &temp)
{
    for (int j{0}; j < cPreviousSize; j++)
    {
        if (previous[j] == temp)
        {
            previous[j]  = previous[A.mFirstNode];
        }
    }
}


