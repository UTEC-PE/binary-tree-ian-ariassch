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
            Node* root = new Node{data, nullptr, nullptr};
        }
        else
        {
            Node* temp = new Node{data, nullptr, nullptr};
            if (temp == root)return;
            if (temp->data > root->data)
            {
                root->right = temp;
            }
            if (temp->data < root->data)
            {
                root->left = temp;
            }
        }


    };

    void preorder()
    {
        if(!root)
        {
            return;
        }
        else if(root)
        {
            root->preorder();
        }

    }

};











#endif //BINARYTREE_TREE_H
