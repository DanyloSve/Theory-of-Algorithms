#include <iostream>
#include <tree.h>

using std::cout;
using std::cin;
using std::endl;

int main()
{

//   Node *root = Tree::createRootBST(10);
//    Tree::insertNodeBST(root,  5);
//    Tree::insertNodeBST(root, 15);
//    Tree::insertNodeBST(root,  7);
//    Tree::insertNodeBST(root,  3);
//    Tree::insertNodeBST(root, 12);
//    Tree::insertNodeBST(root, 17);
//    Tree::insertNodeBST(root, 16);
//    Tree::insertNodeBST(root, 11);
//    Tree::insertNodeBST(root,  6);

//    Tree::showTree(root,0);

    Node *root = nullptr;
    while (true)
    {
        int response{7};
        int iteam{5};
        cout << "Input:\n"
                " 1 - to create root \n"
                " 2 - to insert new node \n"
                " 3 - to delete node \n"
                " 4 - to find predesessor \n"
                " 5 - to find successor   \n"
                " 6 - to search \n"
                " 7 - to exit \n";
        cout << "Your choise: ";
        cin >> response;

        switch(response)
        {

        case 1:
        {
            cout << "Input iteam to add: ";
            cin >> iteam;
            root = Tree::createRootBST(iteam);
            Tree::showTree(root,0);
        }
            break;


        case 2:
        {
            cout << "Input iteam to add: ";
            cin >> iteam;
            Tree::insertNodeBST(root, iteam);
            Tree::showTree(root,0);
        }
            break;

        case 3:
        {
            cout << "Input iteam to delete: ";
            cin >> iteam;
            Tree::deleteNodeBST(root, iteam);
            Tree::showTree(root,0);
        }
            break;

        case 4:
        {
            cout << "Input iteam to search predesassor: ";
            cout << Tree::predecessorNodeBST(root)->mKey;
            cout << '\n';
            Tree::showTree(root,0);
        }
         break;

        case 5:
        {
            cout << "Input iteam to search successor: ";
            cout << Tree::successorNodeBST(root)->mKey;
            cout << '\n';
            Tree::showTree(root,0);
        }
            break;

        case 6:
        {
            cout << "Input iteam to search: ";
            cin >> iteam;
            (Tree::searchNodeBST(root, iteam))?
                        (cout << "Such node exits\n"):
                                                (cout << "Such node does not exist\n");
             cout << '\n';
        }
            break;

        case 7:
        {
            return 0;
        }

        default:
            cout << "Sorry...\n"
                    "I don't understand you..."
                    "Input one more time: ";
        }
    }
}
