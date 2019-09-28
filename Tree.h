//
// Created by VICTOR on 26/09/2019.
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

    void insert_node(T _value){
        Node<T>* new_node = new Node<T>(_value);
        if(!root){
            root = new_node;
        } else {
            Node<T>* temp = root;
            while(temp){
                if(!temp->left){
                    temp->left = new_node;
                    return;
                } else if(!temp->right){
                    temp->right = new_node;
                    return;
                } else {
                    if(!temp->left->left || !temp->left->right){
                        temp = temp->left;
                    } else if(!temp->right->left || !temp->right->right){
                        temp = temp->right;
                    } else {
                        temp = temp->left;
                    }
                }
            }
        }
    }

    int max(int n, int m)
    {
        return (n >= m) ? n : m;
    }

    int height(Node<T>* temp)
    {
        if (temp == nullptr)
            return 0;
        return 1 + max(height(temp->left),height(temp->right));
    }
    int height()
    {
        Node<T>* temp = root;
        if (temp == nullptr)
            return 0;
        return 1 + max(height(temp->left),height(temp->right));
    }

    void insert_right(T _value){
        Node<T>* new_node = new Node<T>(_value);
        if(!root){
            Node<T>* root = new_node;
        } else {
            root->right = new_node;
        }
    }

    void print (){
        if(root){
            Node<T>* temp = root;
            std::list<T> lista_final;
            int n = 1;
            for(int i = 0; i < height(); i++){n = n*2;}
            T lista[n-1];
            for(int i = 0; i < n-1; i++){lista[i] = NULL;}
            lista[0] = temp->key;
            if(temp->left){
                print(temp->left, 1, lista);
            }
            if(temp->right){
                print(temp->right, 2, lista);
            }
            for(int i = 0; i < n-1; i++){lista_final.push_back(lista[i]);}
            for(int i = 0; i < height(); ++i){
                int m = 1;
                for(int k = 0; k < i; k++){m = m*2;}
                for(int k = 0; k < n/(2*m)-1; k++){std::cout << "\t";}
                for(int j = 0; j < m; ++j){
                    std::cout << lista_final.front() << "\t";
                    for(int k = 0; k < n/m-1; k++){std::cout << "\t";}
                    lista_final.pop_front();
                }
                std::cout << '\n';
                if(!lista_final.empty()){
                    for(int k = 0; k < n/(2*m)-2; k++){std::cout << "\t";}
                    for(int j = 0; j < m; ++j){
                        std::cout << "/" << "\t\t" << "\\" << "\t\t";
                        for(int k = 0; k < n/(4*m)-1; k++){std::cout << "\t\t\t\t";}
                    }
                }
                std::cout << '\n';
            }
            std::cout << '\n';
        }
    }

    void print (Node<T>* temp, int index, T lista[]){
        lista[index] = temp->key;
        if(temp->left){
            print(temp->left, 2*index + 1, lista);
        }
        if(temp->right){
            print(temp->right, 2*index + 2, lista);
        }
    }

    void delete_all_tree(Node<T>* temp){
        if(temp->left)
            delete_all_tree(temp->left);
        if(temp->right)
            delete_all_tree(temp->right);
        temp = nullptr;
    }

    void delete_all_tree(){
        if (root) {
            Node<T>* temp = root;
            if(temp->left)
                delete_all_tree(temp->left);
            if(temp->right)
                delete_all_tree(temp->right);
            root = nullptr;
        }
    }

};

#endif //UNTITLED23_TREE_H
