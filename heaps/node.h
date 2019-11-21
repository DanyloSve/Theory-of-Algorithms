#ifndef NODE_H
#define NODE_H

struct Node
{
 public:
    int mKey;
    int mIndex;

    Node  *mpParent;
    Node  *mpLeft;
    Node  *mpRight;
};


#endif // NODE_H
