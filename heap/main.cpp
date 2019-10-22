#include <iostream>

using std::cout;
using std::cin;

#include <heap.h>

int main()
{
    Heap B;
    int data{0};

    while(true)
    {
        cout << "Input: \n"
                "1 - insert iteam to heap\n"
                "2 - push to vector\n"
                "3 - extract max\n"
                "4 - heap sort\n"
                "5 - built max\n"
                "6 - increase key\n"
                "7 - get max\n"
                "8 - auto fill\n"
                "9 - to exit\n";

        cout << "Your response: ";
        int response;
        cin >> response;

        switch (response)
        {
        case 1:
        {
            cout << "Input key : ";
            cin >> data;
            B.heapMaxInsert(data);
        }
            break;
        case 2:
        {
            cout << '\n';
            cout << "Input key : ";
            cin >> data;
            B.pushIntoVector(data);
        }
            break;
        case 3:
        {
            B.heapExtractMax();
        }
            break;
        case 4:
        {
            B.heapSort();
        }
            break;
        case 5:
        {
            B.heapBuiltMax();
        }
            break;
        case 6:
        {
            int index;
            cout << "Input index : ";
            cin >> index;
            cout << "Input data : ";
            cin >> data;
            B.heapIncreaseKey(index - 1, data);
        }
            break;
        case 7:
        {
            cout <<"Max:" << B.heapGetMax();
        }
            break;
        case 8:
        {
            B.autoFill();
        }
            break;
        case 9:
        {
            return 0;
        }
        }
        cout << '\n';
        B.showHeap();
        cout << '\n';


    }
}
