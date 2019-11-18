#ifndef TREE_H
#define TREE_H

#include <node.h>

class Tree
{
public:
    Tree();
    static  Node *deleteNodeBST     (Node *pDelNode, const int &data);
    static  Node *searchNodeBST     (Node *pNode, const int &searchedKey);
    static  Node *successorNodeBST  (Node *pNode);
    static  Node *predecessorNodeBST(Node *pNode);
    static  Node *createRootBST                  (const int &data);
    static  void insertNodeBST      (Node *pNode, const int data);
    static  void showTree           (Node *pNode, const int &l);
};

#endif // TREE_H
