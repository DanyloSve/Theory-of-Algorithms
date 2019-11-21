#include "tree.h"

#include <iostream>

using std::cout;

using std::weak_ptr;
using std::shared_ptr;
using std::make_shared;

void showTree(shared_ptr<Node> const &pNode, int l)
{
    if (pNode != nullptr)
    {
        showTree(pNode->mpLeft, l + 1);
        for (int i{0}; i < l; i++)
        {
            cout << '\t';
        }
        cout << pNode->mKey <<'\n';
        showTree(pNode->mpRight, l + 1);
    }
}


int main()
{
    shared_ptr<Node> root = Tree::createRootBST(10);

    Tree::insertNodeBST(root,  5);
    Tree::insertNodeBST(root, 15);
    Tree::insertNodeBST(root,  7);
    Tree::insertNodeBST(root,  3);
    Tree::insertNodeBST(root, 12);
    Tree::insertNodeBST(root, 17);
    Tree::insertNodeBST(root, 16);
    Tree::insertNodeBST(root, 11);
    Tree::insertNodeBST(root,  6);

    showTree(root, 0);

    return 0;
}
