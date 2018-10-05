//
// Created by damin on 25/09/18.
//

#ifndef BINARYTREE_NODE_H
#define BINARYTREE_NODE_H

#include <iostream>

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

    void enorder()
    {
        if(left)
        {
            left->enorder();
        }
            cout<<data<<" ";
         if(right)
            {
                right->enorder();
            }
    }

    void preorder()
    {
        cout<<data<<" ";
        if(left)
        {
          left->preorder();
        }
        if(right)
        {
          right->preorder();
        }

    }
    void postorder()
    {
      if(left)
      {
        left->postorder();
      }
      if(right)
      {
        right->postorder();
      }
      cout<<data<<" ";
    }
    bool find(int datos, Node* nodo)
    {
        Node* temp = nodo;
        while(datos != temp->data)
        {
            if(datos>temp->data)
            {
                if(temp->right)
                {
                    temp = temp->right;
                }
                else{cout<<"No esta"; return true;}
            }
            if(datos<temp->data)
            {
                if(temp->left)
                {
                    temp = temp->left;
                }
                else{cout<<"No esta";return false;}
            }


        } return true;

    }
    Node* remove(int datos, Node* nodo)
    {
        if(!nodo)
        {
            return nodo;
        }
        else if(datos>nodo->data){nodo->right->remove(datos, right);}
        else if(datos<nodo->data){nodo->left->remove(datos, left);}
        else
        {
            if(nodo->left == NULL and nodo->right == NULL)
            {
                nodo->data=NULL; // No deberías igualar T a null
                delete nodo;
            }
            else if(nodo->right == NULL)
            {
                Node* temp = nodo;
                nodo = nodo->left;
                temp->left = NULL;
                delete temp;
            }
            else if(nodo->left == NULL)
            {
                Node* temp = nodo;
                nodo = nodo->right;
                temp->data = NULL;
                delete temp;
            }
        }
        return nodo;

    }
};

#endif //BINARYTREE_NODE_H