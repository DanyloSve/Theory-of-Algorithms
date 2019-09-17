#include <QCoreApplication>
#include <iostream>

int main()
{
   int inf = INT_MAX;

   int min_e[8][2];
   for (int i(0); i != 7; i++)
   {
       for (int j(0);j != 2; j++)
       {
           min_e[i][j] = inf;

       }
   }
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
   int sel_e[8][8] =
   {
       {0  ,   1,   2,   3, inf, inf, inf, inf},
       {1  ,   0,   3, inf,   5, inf, inf, inf},
       {2  ,   3,   0,  -2,   3,   4, inf, inf},
       {3  , inf,  -2,   0, inf,   3, inf, inf},
       {inf,   5,   3, inf,   0, inf,   1,   3},
       {inf, inf,   4,   3, inf,   0,   2,  -1},
       {inf, inf, inf, inf,   1,   2,   0,   4},
       {inf, inf, inf, inf,   3,  -1,   4,   0}
   };

   int temp_i(0);
   int temp_j(0);

   //пошук мінімальних елементів у стовпцях (пошук проходить зліва на право)

   for (int i(0); i < 8; i++)
      {
          for (int j(0); j < 8; j++)
          {
           if (sel_e[i][j] <= min_e[i][1]  && sel_e[i][j] != 0)
           {
               //занесення елементів у масив перший рядок якого номери елементів
               //а другий - наші мінімальні елементи
               min_e[i][1] = sel_e[i][j];
               temp_i = i;
               temp_j = j;
           }
          }

          //занесення у масив номери рядків
          min_e[i][0] = temp_j;
          //присвоєння відвідах елементів значень нескінченності, щоб їх ще раз не провіряти
          sel_e[temp_i][temp_j] = inf;
          sel_e[temp_j][temp_i] = inf;
      }

   //пошук мінімальних елемментів у рядках (пошук проходить згори вниз)
   //порівнюються  мінімальні елементи з стовців із рядками
   //це зроблено для графа, з однієї вершини якого виходять більше двох гілок

   for (int j(1); j < 8; j++)
   {
         for (int i(0); i < 8; i++)
       {
           //порівняння проходить за 1-м рядком масива min_e
            if ( sel_e[i][ min_e[j][0] ] <= min_e[j][1] && sel_e[i][ min_e[j][0] ] != 0 )
            {
                min_e[j][1] = sel_e[i][ min_e[j][0] ];
            }
       }
   }

    int weight(0);

    std::cout << "Tree: \n";

   for (int i(0); i != 7; i++)
   {
       std::cout << min_e[i][1];
       if (i != 6)
       {
           std::cout << " -> ";
       }
       weight += min_e[i][1];
   }
    std::cout << "\n";
    std::cout << "Weight : " << weight << '\n' ;

    return 0;
}
