#include <iostream>

#include <chrono>
#include <unistd.h>

#include "mergesort.h"


void show(MergeSort &B)
{
    for (double iteam : B.getArray())
    {
        std::cout << iteam << ' ';
    }
    std::cout << '\n';
}

int main()
{
    int count(0);
    MergeSort B;

    int iteam;
    while (true)
    {
        std::cout << "Input:\n"
                     "1 - to add iteam\n"
                     "2 - to sort\n"
                     "0 - to exit\n";
        std::cout << "Your response: ";
        int response;
        std::cin >> response;

        switch (response)
        {
        case 1:
            std::cout << "Input iteam: ";
            std::cin >> iteam;
            count++;
            B.addIteam(iteam);
            break;

        case 2:
        {
            auto start = std::chrono::steady_clock::now();
            B.mergeSort(0, count - 1);
            auto end = std::chrono::steady_clock::now();
            std::cout << "Elapsed time in nanoseconds : "
                    << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() * 1E-9
                    << "s" << std::endl;
            B.getIterations();
            std::cout << '\n';
        }
            break;

//        case 3:
//        {
//            while(std::cin >> iteam)
//            {
//                count++;
//                B.addIteam(iteam);
//            }
//        }
//            break;

        case 0:
            return 0;

        default:
            std::cout << "Input correct data!\n";
        }

        show(B);
    }
}
