#include <iostream>

#include <stdio.h>
#include <ctime>
#include <random>

#include <chrono>
#include <unistd.h>

#include "mySort.h"

using std::cout;
using std::cin;

int getRandomNumber(int min, int max)
{
    srand(static_cast<unsigned int>(time(0)));

    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

int main()
{
    MySort A;
    int sizeOfArray = 0;

    while (true)
    {
        cout << "Input:\n"
                " 1 to add iteam to array\n"
                " 2 to sort\n"
                " 3 to randomized sort\n"
                " 4 to order static\n"
                " 5 to get small random array\n"
                " 6 to get huge random array\n"
                " 7 to get bubble sort\n"
                " 8 to get sort from ground iteam\n"
                " 0 to exit\n";
        int response;
        cout << "Your response: ";
        cin >> response;

        switch(response)
        {
        case 1:
            cout << "Item to add: ";
            int iteam;
            cin >> iteam;
            A.addIteam(iteam);
            sizeOfArray++;
            break;

        case 2:
        {
            int k;
            cout << "Sort ";
            cout << "Input k statistic: ";
            cin >> k;

            auto start = std::chrono::steady_clock::now();

            A.quickSort(k, sizeOfArray - 1);

            auto end = std::chrono::steady_clock::now();
            cout << "Elapsed time in nanoseconds : "
                    << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() * 1E-9
                    << "s" << std::endl;
        }
            break;

        case 3:
        {
            cout << "Randomized sort: ";
            auto start = std::chrono::steady_clock::now();

            A.randomizedQuickSort(0, sizeOfArray - 1);

            auto end = std::chrono::steady_clock::now();
            cout << "Elapsed time in nanoseconds : "
                    << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()* 1E-9
                    << " s" << std::endl;
        }
            break;

        case 4:
            int k;
            cout << "Input k statistic: ";
            cin >> k;
            cout << A.randomizedSelect(0, sizeOfArray - 1, k);
            cout << '\n';
            break;

        case 5:
            A.clearArray();
            for (int i = 0; i != 64; i++)
            {
                std::random_device rd;
                std::mt19937 mersenne(rd());
                A.addIteam(mersenne() % 100);
            }
            sizeOfArray = 64;
            break;

        case 6:
            A.clearArray();
            for (int i = 0; i != 1024; i++)
            {
                std::random_device rd;
                std::mt19937 mersenne(rd());

                A.addIteam(mersenne() % 100);
            }
            sizeOfArray = 1024;
            break;

        case 7:
        {
            auto start = std::chrono::steady_clock::now();

            A.bubbleSort();

            auto end = std::chrono::steady_clock::now();
            cout << "Elapsed time in nanoseconds : "
                    << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()* 1E-9
                    << " s" << std::endl;
        }
            break;

        case 8:
        {
            int k;
            cout << "Sort ";
            cout << "Input k statistic: ";
            cin >> k;

            auto start = std::chrono::steady_clock::now();

            A.groundIteamSort(0, sizeOfArray - 1, k);

            auto end = std::chrono::steady_clock::now();
            cout << "Elapsed time in nanoseconds : "
                    << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() * 1E-9
                    << "s" << std::endl;
        }
            break;

        case 0:
            return 0;
        }

        A.show();
        cout <<'\n';
    }
}
