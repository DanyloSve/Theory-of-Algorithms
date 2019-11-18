#include <iostream>
#include <string>
#include<bits/stdc++.h>

#include "separate-chaining.h"

#include <cmath>

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
    //    int r = 0;
    //    for (int a: key)
    //    {
    //        r += a;
    //    }
    //    return abs(r) % mHashTableSize + 1;
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

    if (mHashTable[index].mKey.empty())
    {
        mHashTable[index].mKey = key;
    }
    else
    {
        Chain *pNewChain = &mHashTable[index];

        while (pNewChain->mpNext)
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
        if (&mHashTable[i])
        {
            std::cout << i << " " << mHashTable[i].mKey;

            Chain *pTemp = mHashTable[i].mpNext;
            while (pTemp)
            {
                std::cout << "->";
                std::cout << pTemp->mKey;
                pTemp = pTemp->mpNext;
            }
        }
        else
        {
            std::cout << i <<" "<<mHashTable[i].mKey;
        }

        std::cout << '\n';
    }
}

