#include <QCoreApplication>
#include <QTextStream>

#include <iostream>
#include <vector>

int main()
{
    QTextStream out(stdout);

    const u_int inf = INT_MAX;
    u_int n{9};

    int sel_e[9][9] =
    {       // 1    2     3    4    5    6    7    8    9
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

    for (u_int i(0); i < n; i++)
    {
        out << "{";

        for (u_int j(0); j < n; j++)
        {
            if (sel_e[i][j] == INT_MAX)
            {
                out << ' ' << "inf" << ' ';
            }
            else if (sel_e[i][j] / 10 > 0)
            {
                out << ' ' << sel_e[i][j] << ' ' << ' ';
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

    bool isVisited[n];
    u_int weight{0};

    for (u_int i{0}; i < n; i++)
    {
        isVisited[i] = 0;
    }

    isVisited[0] = 1;

    u_int tempI{0};
    u_int tempJ{0};
    u_int counter{1};

    std::vector <int> min_e;

    while(counter < n)
    {
        u_int min {inf};

        for(u_int i{0}; i < n; i++)
        {
            for(u_int j{0}; j < n; j++)
            {
                if(sel_e[i][j] != 0 && sel_e[i][j] < min && isVisited[i])
                {
                    min = sel_e[i][j];
                    tempI = i;
                    tempJ = j;
                }

            }

        }

        if(isVisited[tempI] == 0 || isVisited[tempJ] == 0)
        {
            min_e.push_back(min);
            counter++;
            isVisited[tempJ] = 1;
        }

        sel_e[tempI][tempJ] = inf;
        sel_e[tempJ][tempI] = inf;


    }

    for (u_int i{0}; i < min_e.size(); i++)
    {
        out << min_e[i];
        if (i != n - 2)
        {
            out << " -> ";
        }
        weight += min_e[i];
    }

    out << '\n';
    out<<"Weight = "<< weight <<"\n";

    return 0;
}
