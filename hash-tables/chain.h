#ifndef CHAIN_H
#define CHAIN_H

#include <string>

struct Chain
{
    Chain *mpNext;
    std::string mKey;

    Chain(): mpNext{nullptr}, mKey{" "}
    {

    }

    Chain(std::string key): mpNext{nullptr}, mKey{key}
    {

    }
};

#endif // CHAIN_H
