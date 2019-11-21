#ifndef NODE_H
#define NODE_H

# include <memory>

using std::shared_ptr;

struct Node
{
    int mKey;

    shared_ptr<Node> mpParent;
    shared_ptr<Node> mpLeft;
    shared_ptr<Node> mpRight;

};

#endif // NODE_H
