#ifndef OPENHASHING_H
#define OPENHASHING_H

#include <vector>

#include "slot.h"

class OpenHashing
{
private:
    std::vector <Slot> mHashTable;
    int mHashTableSize;

    int hashOccupancy();
    int hashFunction(std::string key);
    int increaseHash();

public:
    OpenHashing();
    void createHash();
    void createHash(int size);
    void addKey(std::string key, const std::string data);
    void deleteKey(std::string key);
    int searchKey(std::string key);
    void showHash();

};

#endif // OPENHASHING_H
