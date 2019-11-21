#include "dsu.h"
#include <iostream>

void DSU::set_make(int *previous, const int cPreviousSize)
{
    for (int i{0}; i < cPreviousSize; i++)
    {
        previous[i] = i;
    }
}

bool DSU::set_find(int *previous, int v)
{
    if (previous[v] != v) return DSU::set_find(previous, previous[v]);
     return v;
}

void DSU::set_union(int *previous, int x, int y)
{
    previous[DSU::set_find(previous, y)] = DSU::set_find(previous, x);
}


