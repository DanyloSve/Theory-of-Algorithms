#ifndef TREE_H
#define TREE_H

#include <memory>
using std::unique_ptr;
using std::shared_ptr;

#include "node.h"

class Tree
{
public:
    Tree();
    static  shared_ptr<Node> deleteNodeBST     (shared_ptr<Node> &pDelNode, const int searchedKey);
    static  shared_ptr<Node> searchNodeBST     (shared_ptr<Node> &pNode, const int &searchedKey);
    static  shared_ptr<Node> successorNodeBST  (shared_ptr<Node> &pNode, const int data);
    static  shared_ptr<Node> predecessorNodeBST(shared_ptr<Node> &pNode, const int data);
    static  shared_ptr<Node> createRootBST                              (const int &data);

    static              void insertNodeBST     (shared_ptr<Node> &pNode, const int data);
    static              void showTree          (shared_ptr<Node> &pNode, const int &l);
};

#endif // TREE_H
