//
// Created by VICTOR on 19/09/2019.
//

#ifndef UNTITLED23_TREE_H
#define UNTITLED23_TREE_H

#include "Node.h"

template <typename T>
class Tree {
public:
    Node<T>* root;

    Tree():root(nullptr){}
    ~Tree(){}

    void insert_node (const T& _value) {
        Node<T>* new_node = new Node<T>(_value);
        if(!root)
            root = new_node;
        else {
            Node<T>* temp = root;
            while(temp){
                if (temp->key > _value)
                    if(temp->left)
                        temp = temp->left;
                    else {
                        temp->left = new_node;
                        break;
                    }
                else if (temp->key < _value)
                    if(temp->right)
                        temp = temp->right;
                    else {
                        temp->right = new_node;
                        break;
                    }
                else
                    break;
            }
        }
    }
};

#endif //UNTITLED23_TREE_H
