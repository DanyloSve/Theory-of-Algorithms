#ifndef SEPARATECHAINING_H
#define SEPARATECHAINING_H

#include "chain.h"

#include <vector>
#include <string>

class SeparateChaining
{
    int mHashTableSize;
    std::vector <Chain> mHashTable;

    int hashFunction(const std::string key);
    int hashOccupancy();
    void increaseHash();

public:
    SeparateChaining();
    void createHash();
    void createHash(const int &size);
    void addKey(const std::string key, const int &data);
    void deleteKey(const std::string key);
    Chain *searchKey(const std::string key);
    void showHash();
};

#endif // SEPARATECHAINING_H
