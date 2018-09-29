//
// Created by damin on 25/09/18.
//

#ifndef BINARYTREE_TREE_H
#define BINARYTREE_TREE_H

#include <lzma.h>
#include "Node.h"

class Tree
{
    Node *root;

public:

    Tree():root(nullptr){};

    Node* getroot()
    {
        return root;
    }

    void insert(int data)
    {
        if(!root)
        {
            root = new Node{data, nullptr, nullptr};
        }
        else
        {
            root->insert(data);
        }


    };

    void preorder()
    {
        if(!root)
        {
            cout<<"vacio"<<endl;
            return;
        }
        else if(root)
        {
            root->preorder();
        }
        cout<<endl;

    }
    void enorder()
    {
        if(!root)
        {
            cout<<"vacio"<<endl;
            return;
        }
        else if(root)
        {
            root->enorder();
        }
        cout<<endl;

    }
    void postorder()
    {
        if(!root)
        {
            cout<<"vacio"<<endl;
            return;
        }
        else if(root)
        {
            root->postorder();
        }
        cout<<endl;

    }
    void remove(int datos)
    {
        root->remove(datos, root);
    }

};











#endif //BINARYTREE_TREE_H
