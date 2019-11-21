#ifndef SLOT_H
#define SLOT_H

#include <string>

struct Slot
{
    std::string mKey;
    std::string mData;

    Slot(): mKey{},mData{"null"}
    {
    }

    Slot(const std::string &key, const std::string &data): mKey{key}, mData{data}
    {
    }

};

#endif // SLOT_H
