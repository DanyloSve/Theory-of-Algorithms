#ifndef OPENADDRESSING_H
#define OPENADDRESSING_H

#include <vector>
#include <string>

class OpenAddressing
{
private:
    int mHashSize;
    std::vector<std::string> mHashTable;

    int hashFunction(std::string key);

public:
    OpenAddressing(int size);
    void addKey(std::string key);
    void showHash();
};

#endif // OPENADDRESSING_H
