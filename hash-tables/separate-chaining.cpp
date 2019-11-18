#include <iostream>
#include <string>
#include<bits/stdc++.h>

#include "separate-chaining.h"

SeparateChaining::SeparateChaining()
{
    for (int i{0}; i != mHashTableSize; i++)
    {
        Chain *pNewChain = new Chain;
        mHashTable.push_back(*pNewChain);
    }
}

int SeparateChaining::hashFunction(const std::string key)
{
    return 'z' - key[0];
}

Chain *createNew(std::string key)
{
    Chain *pNewChain = new Chain;
    pNewChain->mKey = key;
    pNewChain->mpNext = nullptr;

    return pNewChain;
}

void SeparateChaining::addKey(const std::string key)
{
        int index = hashFunction(key);

        if (mHashTable[index].mKey == " ")
        {
            mHashTable[index].mKey = key;
        }
        else
        {
           Chain *pNewChain = mHashTable[index].mpNext;

           while (pNewChain)
           {
               pNewChain = pNewChain->mpNext;
           }
           pNewChain->mpNext = new Chain(key);

         }
}

void SeparateChaining::showHash()
{
    for (int i{0}; i != mHashTableSize; i++)
    {
        if (mHashTable[i].mpNext)
        {
            std::cout << i << " " << mHashTable[i].mKey;

            Chain *pTemp = mHashTable[i].mpNext;
            while (pTemp != nullptr)
            {
                std::cout << "->";
                std::cout << pTemp->mKey;
            }
        }
        else
        {
            std::cout << i <<" "<<mHashTable[i].mKey;
        }

        std::cout << '\n';
    }
}

