#include <iostream>
#include <string>

#include "separate-chaining.h"

int main(int argc, char *argv[])
{
    SeparateChaining S;
    while(true)
    {
        std::cout << "Input\n"
                     "1 - to add iteam\n"
                     "0 - to exit\n";
        int response;
        std::cout << "Your response: ";
        std::cin >> response;

        switch (response)
        {
        case 1 :
        {
            std::cout << "Input key to add: ";
            std::string key;
            std::cin >> key;
            S.addKey(key);
        }
            break;

        case 0 :
            return 0;
        }
        S.showHash();
    }


}
