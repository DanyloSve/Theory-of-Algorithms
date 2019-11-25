#include <iostream>
#include <vector>

#include "sort.h"

void show(std::vector<int> v)
{
    for (int i{0}; i != v.size(); i++)
    {
        std::cout << v[i] << ' ';
    }
    std::cout << '\n';
}

int main(int argc, char *argv[])
{
    Sort G;
    std::vector <int> v;

    while (true)
    {
        std::cout << "Input: \n"
                     "1 - to add iteam\n"
                     "2 - to countingSort\n"
                     "3 - to bucketSort\n"
                     "0 - to exit\n";
        std::cout << "Your response: ";
        int resp;
        std::cin >> resp;

        switch (resp)
        {
        case 1 :
        {
            int iteam;
            std::cout << "Input iteam to add: ";
            std::cin >> iteam;
            v.push_back(iteam);
        }
            break;

        case 2 :
        {
            G.countingSort(v);
        }
            break;

        case 3 :
        {
            G.bucketSort(v);
        }
            break;

        case 0:
        {
            return 0;
        }
        }

       // G.show();
        show(v);
    }
}
