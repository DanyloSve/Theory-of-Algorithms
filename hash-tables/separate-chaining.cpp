#include <iostream>
#include <string>

#include "separate-chaining.h"

#include <cmath>

void SeparateChaining::createHash()
{
    mHashTableSize  = 10;

    for (int i{0}; i != mHashTableSize; i++)
    {
        Chain *pNewChain = new Chain;
        mHashTable.push_back(*pNewChain);
    }
}

void SeparateChaining::createHash(const int &size)
{
    mHashTableSize  = size;

    for (int i{0}; i != mHashTableSize; i++)
    {
        Chain *pNewChain = new Chain;
        mHashTable.push_back(*pNewChain);
    }
}

int SeparateChaining::hashFunction(const std::string key)
{
    int r = 0;

    for (int i{0}; i != key.size(); i++)
    {
        r += static_cast<int>(key[i]) * i;
    }
    return abs(r) % mHashTableSize;

}

int SeparateChaining::hashOccupancy()
{
    int result{0};
    for (int i{0}; i != mHashTableSize; i++)
    {
        if (!mHashTable[i].mKey.empty())
        {
            result++;
        }
    }
    return result;
}

SeparateChaining::SeparateChaining()
{

}

Chain *createNew(std::string key)
{
    Chain *pNewChain = new Chain;
    pNewChain->mKey = key;
    pNewChain->mpNext = nullptr;

    return pNewChain;
}

void SeparateChaining::increaseHash()
{
    std::vector <Chain> hashTableCopy;
    for (int i{0}; i != mHashTableSize; i++)
    {
        if (&mHashTable[i])
        {

            if (!mHashTable[i].mKey.empty())
            {
                hashTableCopy.push_back(mHashTable[i]);

                Chain *pTemp = mHashTable[i].mpNext;
                while (pTemp)
                {
                    hashTableCopy.push_back(*pTemp);
                    pTemp = pTemp->mpNext;
                }
            }
        }
        else
        {
            hashTableCopy.push_back(mHashTable[i]);
        }

    }

    //тут не працює
    int prevHashSize = mHashTableSize;

    // очищення таблиці
    for (int k{0}; k != prevHashSize; k++)
    {
        mHashTable[k].mKey = "";
        mHashTable[k].mData = "null";
        mHashTable[k].mpNext = nullptr;
    }

    for (int l{0}; l != prevHashSize; l++)
    {
        Chain *pNewChain = new Chain;
        mHashTable.push_back(*pNewChain);
    }

    mHashTableSize *= 2;


    for (int j{0}; j!= hashTableCopy.size(); j++)
    {
        addKey(hashTableCopy[j].mKey, hashTableCopy[j].mData);
    }

}

void SeparateChaining::addKey(const std::string key, const std::string &data)
{
    int index = hashFunction(key);

    if (!searchKey(key))
    {
        if (mHashTable[index].mKey.empty())
        {
            mHashTable[index].mKey = key;
            mHashTable[index].mData = data;
        }
        else
        {
            Chain *pNewChain = &mHashTable[index];

            while (pNewChain->mpNext)
            {
                pNewChain = pNewChain->mpNext;
            }
            pNewChain->mpNext = new Chain(key, data);
        }

        int occupancy = hashOccupancy();
        double hashOverload = static_cast<double>(occupancy) / mHashTableSize;

        if (hashOverload > 0.7)
        {
            increaseHash();
        }
    }
}



Chain *SeparateChaining::searchKey(const std::string key)
{// return previous Chain to the chain if we want to delete and if it belongd to chain
    // return exact Chain, if it locates in hash table
    int index = hashFunction(key);

    if (mHashTable[index].mKey.empty())
    {
        //std::cout << "Such key is not found!\n";
        return nullptr;
    }
    else
    {
        if (mHashTable[index].mKey == key)
        {
            return &mHashTable[index];
        }
        else
        {
            Chain *pNewChain = &mHashTable[index];
            Chain *pPrev = nullptr;

            while (pNewChain->mpNext)
            {
                pPrev = pNewChain;
                pNewChain = pNewChain->mpNext;

                if (pNewChain->mKey == key)
                {
                    return pPrev;
                }
            }
            return nullptr;
        }
    }
}


// ось тут треба доробити
void SeparateChaining::deleteKey(const std::string key)
{
    int index = hashFunction(key);
    Chain *delChain{searchKey(key)};

    if (delChain)
    {
        if (!(mHashTable[index].mKey == key))
        {
            delChain->mpNext = delChain->mpNext->mpNext;
            return;
        }
        else
        {

            delChain->mKey = delChain->mpNext->mKey;
            delChain->mData = delChain->mpNext->mData;
            delChain->mpNext = delChain->mpNext->mpNext;
            return;
        }

    }
    else
    {
        std::cout << "Such key doesnot exist!\n";
    }
}

void SeparateChaining::showHash()
{
    for (int i{0}; i != mHashTableSize; i++)
    {
        if (&mHashTable[i])
        {
            std::cout << i << " " << mHashTable[i].mKey << "[" << mHashTable[i].mData << "]";

            Chain *pTemp = mHashTable[i].mpNext;
            while (pTemp)
            {
                std::cout << "->";
                std::cout << pTemp->mKey << "[" << pTemp->mData << "]";
                pTemp = pTemp->mpNext;
            }
        }
        else
        {
            std::cout << i <<" "<<mHashTable[i].mKey << "[" << mHashTable[i].mData << "]";
        }
        std::cout << '\n';
    }
}
