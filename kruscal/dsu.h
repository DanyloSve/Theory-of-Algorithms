#ifndef DSU_H
#define DSU_H

struct Edge
{
    int mWeight;
    int mFirstNode;
    int mSecondNode;

    void initialize(int a, int b, int weight)
    {
        mWeight = weight;
        mFirstNode = a;
        mSecondNode = b;
    }

};

struct DSU
{
    static void set_make(int *previous, int const cPreviousSize);
    static bool set_find(Edge &A);
    static void set_union(Edge &A, int *previous, const int cPreviousSize, int &temp);
};

#endif // DSU_H
