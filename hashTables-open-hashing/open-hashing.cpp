#include<iostream>

#include "open-hashing.h"

int OpenHashing::hashOccupancy()
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

int OpenHashing::hashFunction(std::string key)
{
    int r = 0;

    for (int i{0}; i != key.size(); i++)
    {
        r += static_cast<int>(key[i]) * i;
    }
    return abs(r) % mHashTableSize;
}

int OpenHashing::increaseHash()
{
    std::vector<Slot> hashTableCopy;
    int count{0};
    int prevHashTableSize = mHashTableSize;
    for (int i{0}; i != mHashTableSize; i++)
    {
        if (!mHashTable[i].mKey.empty())
        {
            hashTableCopy.push_back(mHashTable[i]);
            count++;
        }
    }


    for (int i{0}; i != prevHashTableSize; i++)
    {
        mHashTable[i].mKey = "";
        mHashTable[i].mData = "null";
    }

    mHashTableSize *= 2;

    for (int i{0}; i != prevHashTableSize; i++)
    {
        Slot *NewSlot = new Slot;
        mHashTable.push_back(*NewSlot);
    }


    for (int i{0}; i != count; i++)
    {
        addKey(hashTableCopy[i].mKey, hashTableCopy[i].mData);
    }
}

OpenHashing::OpenHashing()
{

}

void OpenHashing::createHash()
{
    mHashTableSize = 10;

    for (int i{0}; i != mHashTableSize; i++)
    {
        Slot *NewSlot = new Slot;
        mHashTable.push_back(*NewSlot);
    }
}

void OpenHashing::createHash(int size)
{
    mHashTableSize = size;
    for (int i{0}; i != mHashTableSize; i++)
    {
        Slot *NewSlot = new Slot;
        mHashTable.push_back(*NewSlot);
    }
}

void OpenHashing::addKey(std::string key, const std::string data)
{
    int addIndex = hashFunction(key);
    int startIndex = addIndex;

    if (!searchKey(key))
    {
        while (true)
        {
            if (addIndex == mHashTableSize)
            {
                addIndex = 0;
            }
            if (mHashTable[addIndex].mKey.empty())
            {
                mHashTable[addIndex].mKey = key;
                mHashTable[addIndex].mData = data;
                break;
            }

            addIndex++;
            if (addIndex == startIndex)
            {
                break;
            }
        }

        int occupancy = hashOccupancy();
        double hashOverload = static_cast<double>(occupancy) / mHashTableSize;

        if (hashOverload > 0.7)
        {
            increaseHash();
        }
    }

}

void OpenHashing::deleteKey(std::string key)
{
    int dellIndex = hashFunction(key);
    int startIndex = dellIndex;

    while (true)
    {
        if (dellIndex == mHashTableSize)
        {
            dellIndex = 0;
        }


        if (mHashTable[dellIndex].mKey == key)
        {
            mHashTable[dellIndex].mKey = "";
            mHashTable[dellIndex].mData = "null";
            break;
        }

        dellIndex++;
        if (dellIndex == startIndex)
        {
            break;
        }
    }

    std::cout << "Such slot doesnot exist!\n";
}

int OpenHashing::searchKey(std::string key)
{
    int dellIndex = hashFunction(key);
    int startIndex = dellIndex;

    while (true)
    {
        if (dellIndex == mHashTableSize)
        {
            dellIndex = 0;
        }


        if (mHashTable[dellIndex].mKey == key)
        {
            return 1;
        }

        dellIndex++;
        if (dellIndex == startIndex)
        {
            break;
        }
    }
    return 0;
}

void OpenHashing::showHash()
{
    for (int i{0}; i != mHashTableSize; i++)
    {
        std::cout << i << ' ' <<mHashTable[i].mKey << " [" << mHashTable[i].mData << "]" << '\n';
    }
}

