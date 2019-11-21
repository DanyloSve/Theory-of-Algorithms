#include <iostream>
#include <queue>

#include "tree.h"

using std::cout;
using std::queue;

void showTree(shared_ptr<Node> const &pNode, const int &l)
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

shared_ptr<Node> Tree::createRootBST(const int &data)
{
   Node *temp = new Node;
   shared_ptr<Node> pNode(temp);

   pNode->mKey = data;
   pNode->mpLeft = nullptr;
   pNode->mpRight = nullptr;
   pNode->mpParent = nullptr;

   return  pNode;
}
shared_ptr<Node> Tree::searchNodeBST(shared_ptr<Node> &pNode, const int &searchedKey)
{
    // pNode має бути коренем, оскільки пошук відбувається від корення!

     while (pNode != nullptr) // ось тут pNode стає рівним nullptr
     {                        // і через те, що тут є передача по силці &pNode, воно стає nullptr
        if (pNode->mKey == searchedKey)
        {
            return pNode;
        }
        else if ( (pNode->mKey) > searchedKey)
        {
            pNode = pNode->mpLeft;
        }
        else if ( (pNode->mKey) < searchedKey)
        {
            pNode = pNode->mpRight;
        }
     }

     return nullptr;
}


void Tree::insertNodeBST(shared_ptr<Node> &pNode, const int data) //pNode має бути root
{
    if ( searchNodeBST(pNode, data) != nullptr ) // отут відбувається pNode =  nullptr
    {
        cout << "Such node already exists!\n";
    }
    else
    {
        shared_ptr<Node> pNewNode = createRootBST(data); //створення нового вузла та його ініціалізація
        shared_ptr<Node> pPrevious = nullptr; // swap(pNewNode, pNode)

        //пошук місця для вставки даних
        while (pNode != nullptr) // тут pNode == nullptr
        {
            pPrevious = pNode;   //тому тут pNode не ініціалізується

            if ( data < (pNode->mKey) )
            {
                pNode = pNode->mpLeft;
            }
            else
            {
                pNode = pNode->mpRight;
            }
        }

        // Вставка даних
        pNewNode->mpParent = pPrevious;

        if ( (pPrevious->mKey) > data)
        {
            pPrevious->mpLeft = pNewNode;
        }
        else if ( (pPrevious->mKey) < data)
        {
            pPrevious->mpRight = pNewNode;
        }
    }
}

void deletDeepest(shared_ptr <Node> pRoot, shared_ptr <Node> pDNode)
{
    queue<shared_ptr <Node>> q;
    q.push(pRoot);

    // Do level order traversal until last node
    shared_ptr <Node> pTemp;
    while (!q.empty())
    {
        pTemp = q.front();
        q.pop();

        if (pTemp == pDNode)
        {
            pTemp = nullptr;
            pDNode.reset();
            return;
        }
        if (pTemp->mpRight)
        {
            if (pTemp->mpRight == pDNode)
            {
                pTemp->mpRight = nullptr;
                pDNode.reset();
                return;
            }
            else
            {
                q.push(pTemp->mpRight);
            }
        }

        if (pTemp->mpLeft) {
            if (pTemp->mpLeft == pDNode)
            {
                pTemp->mpLeft = nullptr;
                pDNode.reset();
                return;
            }
            else
            {
                q.push(pTemp->mpLeft);
            }
        }
    }
}

shared_ptr<Node> Tree::deleteNodeBST(shared_ptr<Node>  &pDelNode, const int searchedKey)
{
//    if (searchNodeBST(pDelNode, searchedKey) == nullptr )
//    {
//        cout << "Such node does not exist\n";
//    }
//    else
      {
        if (pDelNode == nullptr)
        {
            return nullptr;
        }
        if ( (pDelNode->mpLeft == nullptr) && (pDelNode->mpRight == nullptr) )
        {
            if (pDelNode->mKey == searchedKey)
            {
                return nullptr;
            }
            else
            {
                return pDelNode;
            }
        }
        else if ( ( (pDelNode->mpLeft != nullptr) && (pDelNode->mpRight == nullptr) )
                  || ( (pDelNode->mpLeft == nullptr) && (pDelNode->mpRight != nullptr) ) ) // якщо pDelNote має одного нащадка
        {
            queue<shared_ptr<Node>> q;
            q.push(pDelNode);
                q.push(pDelNode);

                shared_ptr<Node> pTemp;
                shared_ptr<Node> pKeyNode = nullptr;

                // Do level order traversal to find deepest
                // node(temp) and node to be deleted (key_node)
                while (!q.empty())
                {
                    pTemp = q.front();
                    q.pop();

                    if (pTemp->mKey == searchedKey)
                    {
                        pKeyNode = pTemp;
                    }
                    if (pTemp->mpLeft)
                    {
                        q.push(pTemp->mpLeft);
                    }
                    if (pTemp->mpRight)
                    {
                        q.push(pTemp->mpRight);
                    }
                }

                if (pKeyNode != nullptr)
                {
                    int x = pTemp->mKey;
                    deletDeepest(pDelNode, pTemp);
                    pKeyNode->mKey = x;
                }
                return pDelNode;
        }

    }
}

shared_ptr<Node> Tree::successorNodeBST(shared_ptr<Node> &pNode, const int data)
{
    shared_ptr<Node> pPrevious;

    if ( (pNode->mpRight) != nullptr)
    {
        pPrevious = pNode->mpRight;

        while (pPrevious != nullptr)
        {
            pPrevious = pPrevious->mpLeft;
        }

        return pPrevious;
    }
    else if ( (pNode->mpRight) == nullptr)
    {
        pPrevious = pNode->mpParent;

        while ( (pPrevious != nullptr) && (pNode == pPrevious->mpRight) )
        {
            pNode = pPrevious;
            pPrevious = pPrevious->mpParent;
        }

        return pPrevious;
    }
    else if ( (pNode->mpParent) == nullptr)
    {
        return nullptr;
    }
}

shared_ptr<Node> Tree::predecessorNodeBST(shared_ptr<Node> &pNode, const int data)
{
    shared_ptr<Node> pPrevious;

    if ( (pNode->mpLeft) != nullptr)
    {
        pPrevious = pNode->mpLeft;

        while (pPrevious != nullptr)
        {
            pPrevious = pPrevious->mpRight;
        }

        return pPrevious;
    }
    else if ( (pNode->mpRight) == nullptr)
    {
        pPrevious = pNode->mpParent;

        while ( (pPrevious != nullptr) && ( pNode == (pPrevious->mpLeft) ) )
        {
            pNode = pPrevious;
            pPrevious = pPrevious->mpParent;
        }

        return pPrevious;
    }
    else if ( (pNode->mpParent) == nullptr)
    {
        return nullptr;
    }
}
