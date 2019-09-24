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

    Node<T>* max_min(Node<T>* temp, Node<T>* node_delete, Node<T>* temp_prev){
        bool direction = 1;
        temp_prev = temp;
        temp = temp->left;
        while(temp->right){
            direction = 0;
            temp_prev = temp;
            temp = temp->right;
        }
        node_delete->key = temp->key;
        if(temp->left){
            temp = max_min(temp, temp, temp_prev);
        } else if(temp->right){
            temp = min_max(temp, temp, temp_prev);
        } else {
            if(direction == 1){
                temp_prev->left = nullptr;
            } else {
                temp_prev->right = nullptr;
            }
        }
        return temp;
    }

    Node<T>* min_max(Node<T>* temp, Node<T>* node_delete, Node<T>* temp_prev){
        bool direction = 0;
        temp_prev = temp;
        temp = temp->right;
        while(temp->left){
            temp_prev = temp;
            temp = temp->left;
            direction = 1;
        }
        node_delete->key = temp->key;
        if(temp->left){
            temp = max_min(temp, temp, temp_prev);
        } else if(temp->right){
            temp = min_max(temp, temp, temp_prev);
        } else {
            if(direction == 1){
                temp_prev->left = nullptr;
            } else {
                temp_prev->right = nullptr;
            }
        }
        return temp;
    }

    void delete_node (const T& _value) {
        if (root) {
            Node<T>* temp = root;
            Node<T>* temp_prev = root;
            while(temp){
                if (temp->key > _value)
                    if(temp->left)
                        temp = temp->left;
                    else {
                        break;
                    }
                else if (temp->key < _value)
                    if(temp->right)
                        temp = temp->right;
                    else {
                        break;
                    }
                else {
                    if(temp->left)
                        temp = max_min(temp, temp, temp_prev);
                    else if(temp->right)
                        temp = min_max(temp, temp, temp_prev);
                    delete temp;
                    break;
                }
            }
        }
    }

    void branches(int& cont, Node<T>* temp, int& height, bool direction){
        if(direction == 1){
            cont++;
            temp = temp->left;
            if(cont > height){
                height = cont;
            }
            if(temp->left){
                branches(cont, temp, height, 1);
            }
            if(temp->right){
                branches(cont, temp, height, 0);
            }
        }
        if(direction == 0) {
            (cont)++;
            temp = temp->right;
            if(cont > height){
                height = cont;
            }
            if(temp->left){
                branches(cont, temp, height, 1);
            }
            if(temp->right){
                branches(cont, temp, height, 0);
            }
        }
    }

    int get_height(){
        int height = 0;
        if(!root)
            return 0;
        else {
            Node<T>* temp = root;
            int cont = 0;
            if(temp->left)
                branches(cont, temp, height, 1);
            if(temp->right)
                branches(cont, temp, height, 0);
        }
        return height;
    }

    void delete_left(Node<T>* temp){
        temp = temp->left;
        if(temp->left)
            delete_left(temp);
        if(temp->right)
            delete_right(temp);
        delete temp;
    }

    void delete_right(Node<T>* temp){
        temp = temp->right;
        if(temp->left)
            delete_left(temp);
        if(temp->right)
            delete_right(temp);
        delete temp;
    }

    void delete_all_tree(){ //debe eliminar todo y volverlo inutilizable, o con la posibilidad de poder reusarlo
        if (root) {
            Node<T>* temp = root;
            if(temp->left)
                delete_left(temp);
            if(temp->right)
                delete_right(temp);
            delete root;
        }
    }
};

#endif //UNTITLED23_TREE_H
