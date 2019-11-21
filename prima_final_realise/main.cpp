#include <QCoreApplication>
#include <QTextStream>

#include <vector>
#include <iostream>


void prima()
{
    QTextStream out(stdout);

    int inf = INT_MAX;

     /*Graph:
           [s2]-5-[s5]--1-- [s7]
           / |     / \      / |
          1  3    3   3    /  |
         /   |   /     \  /   |
       {s1}2[s3]        \/    4
         \   |   \      /\    |
          3 (-2)  4    2  \   |
           \ |     \  /    \  |
            [s4]-3-[s6]-(-2)-[s8]
     */
//    int sel_e[8][8] =
//    {
//        {0  ,   1,   2,   3, inf, inf, inf, inf},
//        {1  ,   0,   3, inf,   5, inf, inf, inf},
//        {2  ,   3,   0,  -2,   3,   4, inf, inf},
//        {3  , inf,  -2,   0, inf,   3, inf, inf},
//        {inf,   5,   3, inf,   0, inf,   1,   3},
//        {inf, inf,   4,   3, inf,   0,   2,  -1},
//        {inf, inf, inf, inf,   1,   2,   0,   4},
//        {inf, inf, inf, inf,   3,  -1,   4,   0}
//    };

    u_int n(8);

    int sel_e[9][9] =
    {       //1     2     3    4    5    6    7    8    9
        /*1*/{ 0,   4,  inf, inf, inf, inf, inf,   8, inf},
        /*2*/{ 4,   0,    8, inf, inf, inf, inf,  11, inf},
        /*3*/{inf,  8,    0,   7, inf,   4, inf, inf,   2},
        /*4*/{inf, inf,   7,   0,   9,  14, inf, inf, inf},
        /*5*/{inf, inf, inf,   9,   0,  10, inf, inf, inf},
        /*6*/{inf, inf,   4,  14,  10,   0,   2, inf, inf},
        /*7*/{inf, inf, inf, inf, inf,   2,   0,   1,   6},
        /*8*/{  8,  11, inf, inf, inf, inf,   1,   0,   7},
        /*9*/{inf, inf,   2, inf, inf, inf,   6,   7,   0}
    };

    int min_e[n][2];
    for (u_int i(0); i != n - 2; i++)
    {
        for (u_int j(0);j != 2; j++)
        {
            min_e[i][j] = inf;

        }
    }
    u_int temp_i(0);
    u_int temp_j(0);

    for (u_int i(0); i < n; i++)
    {
        out << "{";

        for (u_int j(0); j < n; j++)
        {
            if (sel_e[i][j] == INT_MAX)
            {
                out << ' ' << "inf" << ' ';
            }
            else if (sel_e[i][j] < 0)
            {
                out << ' ' << sel_e[i][j] << ' ' << ' ';
            }
            else if (sel_e[i][j] >= 0)
            {
                out << ' ' << ' ' << sel_e[i][j] << ' ' << ' ';
            }
        }

        out << "}";
        out << '\n';
    }

    for (u_int i(0); i < n; i++)
       {
           for (u_int j(0); j < n; j++)
           {
            if (sel_e[i][j] <= min_e[i][1]  && sel_e[i][j] != 0)
            {

                min_e[i][1] = sel_e[i][j];
                temp_i = i;
                temp_j = j;
            }

           }

           min_e[i][0] = temp_j;
           sel_e[temp_i][temp_j] = inf;
           sel_e[temp_j][temp_i] = inf;


       }


    for (u_int j(0); j < n; j++)
    {
          for (u_int i(0); i < n; i++)
        {
             if ( sel_e[i][ min_e[j][0] ] <= min_e[j][1] && sel_e[i][ min_e[j][0] ] != 0 )
             {
                 min_e[j][1] = sel_e[i][ min_e[j][0] ];
             }
        }
    }


     QString str1 =  "Tree: \n";

     out << str1;


    u_int weight(0);

    for (u_int i(0); i != n - 1; i++)
    {
        out << min_e[i][1];
        if (i != n - 2)
        {
            out << " -> ";
        }
        weight += min_e[i][1];
    }

     out << '\n';
     QString str2 = "Weight : %1\n" ;
     out << str2.arg(weight);

}

int main()
{
    prima();
    return 0;
}

