//
// Created by damin on 25/09/18.
//

#ifndef BINARYTREE_NODE_H
#define BINARYTREE_NODE_H

#endif //BINARYTREE_NODE_H

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    void insert(int datos)
    {
        if(datos>data)
        {
            if(this->right)
            {
                right->insert(datos);
            }
            else
            {
                Node* temp = new Node{datos, nullptr, nullptr};
                right = temp;
            }
        }
        if(datos<data)
        {
            if(this->left)
            {
                left->insert(datos);
            }
            else
            {
                Node* temp = new Node{datos, nullptr, nullptr};
                left = temp;
            }
        }
    }

    void preorder()
    {
        if(left)
        {
            left->preorder();
        }


            cout<<data<<" ";
         if(right)
            {
                right->preorder();
            }


    }
};
