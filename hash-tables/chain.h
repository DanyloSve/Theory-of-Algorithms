#ifndef CHAIN_H
#define CHAIN_H

#include <string>

struct Chain
{
    Chain *mpNext;
    std::string mData;
    std::string mKey;


    Chain(): mpNext{nullptr}, mData{"null"}, mKey{}
    {
    }

    Chain(const std::string &key, const std::string & data): mpNext{nullptr}, mData{data}, mKey{key}
    {
    }

};

#endif // CHAIN_H
