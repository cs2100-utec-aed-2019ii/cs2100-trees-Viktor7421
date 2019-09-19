//
// Created by VICTOR on 19/09/2019.
//

#ifndef UNTITLED23_NODE_H
#define UNTITLED23_NODE_H

template <typename T>
class Node {
public:
    T key;
    Node<T> *left, *right;

    Node(T key){
        this->key = key;
        this->left = this->right = nullptr;
    }

};

#endif //UNTITLED23_NODE_H
