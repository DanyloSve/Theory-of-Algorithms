#include <iostream>
#include <string>

#include "separate-chaining.h"

int main()
{
    SeparateChaining S;
    std::cout << "Set size for hash table?[Y/n]\n";

        char response;

        while (!(std::cin >> response))
        {
            std::cout << "Error: input a char!\n";
            std::cin.clear();
            std::cin.ignore(3000, '\n');
            std::cout << "Your response: ";
        }

        if (response == 'Y' || response == 'y')
        {
            std::cout << "Input size of hash table: ";
            int size;

            while (!(std::cin >> size))
            {
                std::cout << "Error: input an integer!\n";
                std::cin.clear();
                std::cin.ignore(3000, '\n');
                std::cout << "Input size of hash table: ";
            }

            S.createHash(size);
        }
        else
        {
           S.createHash();
        }



    while(true)
    {
        std::cout << "Input\n"
                     "1 - to add key\n"
                     "2 - to delete key\n"
                     "3 - to find key\n"
                     "0 - to exit\n";
        int response;
        std::cout << "Your response: ";

        while (!(std::cin >> response))
        {
            std::cout << "Error: input a number!\n";
            std::cin.clear();
            std::cin.ignore(3000, '\n');
            std::cout << "Your response: ";
        }

        switch (response)
        {
        case 1 :
        {
            std::cout << "Input data to add: ";
            int data;
            while (!(std::cin >> data))
            {
                std::cout << "Error: Input data to add: ";
                std::cin.clear();
                std::cin.ignore(3000, '\n');
                std::cout << "Your response: ";
            }

            std::cout << "Input key to add: ";
            std::string key;
            while (!(std::cin >> key))
            {
                std::cout << "Error: Input key to add: ";
                std::cin.clear();
                std::cin.ignore(3000, '\n');
                std::cout << "Your response: ";
            }
            S.addKey(key, data);
        }
            break;

        case 2:
        {
            std::cout << "Input key to delete: ";
            std::string key;
            while (!(std::cin >> key))
            {
                std::cout << "Error: Input key to delete:";
                std::cin.clear();
                std::cin.ignore(3000, '\n');
                std::cout << "Input key to delete: ";
            }
            S.deleteKey(key);
        }
            break;

        case 3:
        {
            std::cout << "Input key to find: ";
            std::string key;
            while (!(std::cin >> key))
            {
                std::cout << "Error: input a number!\n";
                std::cin.clear();
                std::cin.ignore(3000, '\n');
                std::cout << "Input key to find: ";
            }
            (S.searchKey(key)) ? (std::cout << "Such key exists\n")
                               : (std::cout << "Such key doesnot exists!\n");
        }
            break;


        case 0 :
            return 0;
        }
        S.showHash();
    }


}
