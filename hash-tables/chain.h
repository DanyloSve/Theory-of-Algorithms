#ifndef CHAIN_H
#define CHAIN_H

#include <string>

struct Chain
{
    Chain *mpNext;
    int mData;
    std::string mKey;

    Chain(): mpNext{nullptr}, mData{}, mKey{}
    {
    }

    Chain(const std::string &key, const int data): mpNext{nullptr}, mData{data}, mKey{key}
    {
    }
};

#endif // CHAIN_H
