#include <QCoreApplication>

#include <iostream>

using std::cin;
using std::cout;

#include "heap.h"


int main()
{
    Heap A;

    while (true)
    {
        void showHeap();

        cout << "Input:\n"
                "1 - to add insert in heap\n"
                "2 - to push in vector\n"
                "3 - to show maximum iteam from the heap\n"
                "4 - to increase key\n"
                "5 - to built maxHeap\n"
                "6 - to sort heap\n"
                "7 - to extract maximum\n"
                "8 - to auto fill heap\n"
                "9 - to exit\n";



        int response;
        cout << "Your response: ";
        cin >> response;

        int iteam;


        switch(response)
        {
        case 1:
        {
             cout << "Insert iteam: ";
             cin >> iteam;
             A.maxHeapInsert(iteam);

        }
            break;

        case 2:
        {
            cout << "Input iteam: ";
            cin >> iteam;
            A.addNewIteam(iteam);
        }
            break;
        case 3:
        {
            cout << "Max iteam:";
            cout << A.heapMaximum();
        }
            break;

        case 4:
        {
            cout << "Input iteam: ";
            cin >> iteam;

            cout << "Input index: ";
            int index;
            cin >> index;

             A.heapIncreaseKey(index - 1, iteam);
        }
            break;

        case 5:
        {

            cout << "Bulding maxHeap: ";
            A.builtMaxHeap();

        }
            break;

        case 6:
        {
            A.heapSort();
        }
            break;

        case 7:
        {
            A.heapExtractMax();
        }
            break;

        case 8:
        {
            A.autoFillingHeap();
        }
            break;

        case 9:
        {
            return 0;
        }

        }

        cout << '\n';
        A.showHeap();
        cout << '\n';
    }
}
