#ifndef SEPARATECHAINING_H
#define SEPARATECHAINING_H

#include "chain.h"

#include <vector>
#include <string>

class SeparateChaining
{
    int mHashTableSize = 'z' - 'a' + 1;
    std::vector <Chain> mHashTable;

    int hashFunction(const std::string key);

public:
    SeparateChaining();
    void addKey(const std::string key);
    void showHash();
};

#endif // SEPARATECHAINING_H
