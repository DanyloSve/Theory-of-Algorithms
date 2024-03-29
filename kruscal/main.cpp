#include <QCoreApplication>
#include <QTextStream>

#include <iostream>

#include "dsu.h"

using std::vector;
using std::cin;
using std::array;
using std::swap;

QTextStream out(stdout);

void sort(Edge *lineArr, int lineArrSize)
{
      int min;

      for(u_int i{0}; i < lineArrSize; i++)
      {
          min = i;
          for(u_int k{i}; k < lineArrSize; k++)
          {
              if(lineArr[k].mWeight < lineArr[min].mWeight)
              min = k;
          }
          swap(lineArr[i], lineArr[min]);
      }
}

void initialize(Edge *lineArr)
{
    lineArr[0].initialize(0, 1, 4);
    lineArr[1].initialize(0, 7, 8);
    lineArr[2].initialize(1, 7, 11);
    lineArr[3].initialize(1, 2, 8);
    lineArr[4].initialize(2, 8, 2);
    lineArr[5].initialize(7, 8, 7);
    lineArr[6].initialize(6, 8, 6);
    lineArr[7].initialize(6, 7, 1);
    lineArr[8].initialize(2, 3, 7);
    lineArr[9].initialize(2, 5, 4);
    lineArr[10].initialize(5, 6, 2);
    lineArr[11].initialize(3, 5, 14);
    lineArr[12].initialize(3, 4, 9);
    lineArr[13].initialize(4, 5, 10);
}

void showTitle(Edge *lineArr, u_int cLineArrSize)
{

    out << "|  edge:  | nods: | weight: \n";
    for (u_int i{0}; i <  cLineArrSize; i++)
    {
        if ((i + 1) < 10)
        {
            out << "|    " << i + 1 << "    | " <<lineArr[i].mFirstNode + 1 << " ; "
                 << lineArr[i].mSecondNode + 1 << " |    " << lineArr[i].mWeight << " \n";
        }
        else
        {
            out << "|    " << i + 1 << "   | " <<lineArr[i].mFirstNode + 1 << " ; "
                 << lineArr[i].mSecondNode + 1 << " |    " << lineArr[i].mWeight << " \n";
        }
    }

    out << "\n";
}

void showPrevious( int *previous, const int cPreviousSize)
{
    for (u_int i{0}; i < cPreviousSize; i++)
    {
        out << i + 1 << "(" << previous[i] + 1 << "),";
    }
}

void pInitializing(int *p, int *previous, const u_int cPreviousSize)
{
    for (u_int i{0}; i != cPreviousSize; i++)
    {
        p[i] = previous[i];
    }
}

bool isAdded(int *p, int *previous, const u_int cPreviousSize)
{
    for (u_int i{0}; i != cPreviousSize; i++)
    {
        if (p[i] != previous[i])
        {
            return 1;
        }
    }
    return 0;
}

void kruscal (Edge *lineArr, const u_int cLineArrSize, int *previous, const u_int cPreviousSize)
{
    int p[cPreviousSize];


    for (u_int i{0}; i < cLineArrSize; i++)
    {
        for (u_int i{0}; i != cPreviousSize; i++)
        {
            p[i] = previous[i];
        }

        if ( DSU::set_find(lineArr[i]) )
        {
            int temp = previous[lineArr[i].mSecondNode];
            DSU::set_union(lineArr[i],previous,cPreviousSize, temp);

            if (lineArr[i].mWeight <= 9)
            {
                out << "|  "<< lineArr[i].mWeight << "  | " << lineArr[i].mFirstNode + 1 << " ; "
                     << lineArr[i].mSecondNode + 1 << " | ";
                showPrevious(previous, cPreviousSize);

            }
            else
            {
                out << "|  "<< lineArr[i].mWeight  << " | " << lineArr[i].mFirstNode + 1 << " ; "
                     << lineArr[i].mSecondNode + 1 << " | ";
                showPrevious(previous, cPreviousSize);

            }

        }

        for (u_int i{0}; i != cPreviousSize; i++)
        {
            if (p[i] != previous[i])
            {
                out << "added";
                break;
            }
        }

        out << "\n";
    }
}

int main()
{
    const u_int cLineArrSize {14};
    Edge lineArr[cLineArrSize];

    const u_int cPreviousSize{9};
    int previous [cPreviousSize];

    initialize(lineArr);
    sort(lineArr, cLineArrSize);
    DSU::set_make(previous, cPreviousSize);

    showTitle(lineArr, cLineArrSize);
    kruscal(lineArr, cLineArrSize, previous, cPreviousSize);

    return 0;
}
