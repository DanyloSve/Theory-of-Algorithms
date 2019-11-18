#include <iostream>
#include <queue>

#include "tree.h"

using std::cout;
using std::queue;

void Tree::showTree(Node *pNode, const int &l)
{
    if (pNode) // (pNode)
    {
        showTree(pNode->mpLeft, l + 1);
        for (int i{0}; i < l; ++i)
        {
            cout << '\t';
        }
        cout << pNode->mKey <<'\n';
        showTree(pNode->mpRight, l + 1);
    }
}

Node *Tree::createRootBST(const int &data)
{
   Node *pRoot =  new Node;

   pRoot->mKey = data;
   pRoot->mpLeft = nullptr;
   pRoot->mpRight = nullptr;
   pRoot->mpParent = nullptr;

   return  pRoot;
}

void Tree::insertNodeBST(Node *pNode, const int data) //pNode має бути root
{
    //Перевірка на існування даного вузла
    if (searchNodeBST(pNode, data))  //pNode має бути root!
    {
        cout << "Such node already exists!\n";
    }
    else
    {
        Node* pNewNode = createRootBST(data); //створення нового вузла та його ініціалізація

        Node* pPrevious = nullptr;

        //пошук місця для вставки даних
        while (pNode != nullptr)
        {
            pPrevious = pNode;

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

Node *Tree::searchNodeBST(Node *pNode, const int &searchedKey)
{
    // pNode має бути коренем, оскільки пошук відбувається від корення!

     while (pNode)
     {
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

Node *Tree::successorNodeBST(Node *pNode) // найлівіший у правому піддереві
{
    Node *pPrevious = nullptr;

    if (pNode->mpRight) // якщо існує правий син
    {
        pPrevious = pNode->mpRight;

        while (pPrevious->mpLeft != nullptr)
        {
            pPrevious = pPrevious->mpLeft;
        }

        return pPrevious;
    }
    else if (!pNode->mpRight) //(!pNode->mpRight)   у вузла не існує правого сина
    {
        pPrevious = pNode->mpParent;

        while ( (pPrevious) && (pNode == pPrevious->mpRight) )
        {
            pNode = pPrevious;
            pPrevious = pPrevious->mpParent;
        }

        return pPrevious;
    }

    return nullptr;
}

Node *Tree::predecessorNodeBST(Node *pNode) // найправіший елемент у лівому піддереві
{
    Node *pPrevious = nullptr;

    if (pNode->mpLeft) // якщо існує лівий син
    {
        pPrevious = pNode->mpLeft;

        while (pPrevious->mpRight != nullptr)
        {
            pPrevious = pPrevious->mpRight;
        }

        return pPrevious;
    }
    else if (!pNode->mpLeft) // у вузла не існує лівий сина
    {
        pPrevious = pNode->mpParent;

        while ( (pPrevious) && (pNode == pPrevious->mpLeft) )
        {
            pNode = pPrevious;
            pPrevious = pPrevious->mpParent;
        }
        return pPrevious;
    }
    return nullptr;
}

Node *Tree::deleteNodeBST(Node *pDelNode, const int &data)
{
    if(!pDelNode)
    {
        return pDelNode;
    }
    else if(data < pDelNode->mKey)
    {
        pDelNode->mpLeft = deleteNodeBST(pDelNode->mpLeft, data);
    }
    else if (data> pDelNode->mKey)
    {
        pDelNode->mpRight = deleteNodeBST(pDelNode->mpRight, data);
    }
        else
        {
            //не має синів
            if(!pDelNode->mpRight && !pDelNode->mpLeft)
            {
                delete pDelNode;
                pDelNode = nullptr;
            }
            //Одн син
            else if(!pDelNode->mpRight)
            {
                Node *temp = pDelNode;
                pDelNode= pDelNode->mpLeft;
                delete temp;
            }
            else if(!pDelNode)
            {
                Node *temp = pDelNode;
                pDelNode = pDelNode->mpRight;
                delete temp;
            }
            //два сини
            else
            {
                Node *temp = Tree::successorNodeBST(pDelNode);
                pDelNode->mKey = temp->mKey;
                pDelNode->mpRight = deleteNodeBST(pDelNode->mpRight, temp->mKey);
            }
        }
        return pDelNode;
}




