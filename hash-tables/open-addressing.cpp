#include "open-addressing.h"


int OpenAddressing::hashFunction(std::string key)
{

}

OpenAddressing::OpenAddressing(int size)
{
    for(int i{0}; i != mHashSize; i++)
    {
        mHashTable.push_back(" ");
    }
}

void OpenAddressing::addKey(std::string key)
{

}

void OpenAddressing::showHash()
{

}
