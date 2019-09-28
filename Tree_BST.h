//
// Created by VICTOR on 19/09/2019.
//

#ifndef UNTITLED23_TREE_BST_H
#define UNTITLED23_TREE_BST_H

#include "Node.h"
#include <vector>
#include <list>
#include <iterator>

template <typename T>
class Tree_BST {
public:
    Node<T>* root;
    int Nodes = 0;

    Tree_BST():root(nullptr){}
    ~Tree_BST(){}

    void identicaly_left(Node<T>* temp, Node<T>* temp_other_tree, bool verificador){
        temp = temp->left;
        temp_other_tree = temp_other_tree->left;
        if(temp->key == temp_other_tree->key){
            if(temp->left && temp_other_tree->left){
                identicaly_left(temp, temp_other_tree, verificador);
            } else if((temp->left && !temp_other_tree->left) || (!temp->left && temp_other_tree->left)){
                verificador = false;
            }
            if(temp->right && temp_other_tree->right){
                identicaly_right(temp, temp_other_tree, verificador);
            } else if((temp->right && !temp_other_tree->right) || (!temp->right && temp_other_tree->right)){
                verificador = false;
            }
        } else {verificador = false;}
    }

    void identicaly_right(Node<T>* temp, Node<T>* temp_other_tree, bool verificador){
        temp = temp->right;
        temp_other_tree = temp_other_tree->right;
        if(temp->key == temp_other_tree->key){
            if(temp->left && temp_other_tree->left){
                identicaly_left(temp, temp_other_tree, verificador);
            } else if((temp->left && !temp_other_tree->left) || (!temp->left && temp_other_tree->left)){
                verificador = false;
            }
            if(temp->right && temp_other_tree->right){
                identicaly_right(temp, temp_other_tree, verificador);
            } else if((temp->right && !temp_other_tree->right) || (!temp->right && temp_other_tree->right)){
                verificador = false;
            }
        } else {verificador = false;}
    }

    bool identicaly(Tree_BST<T> other_tree){
        bool verificador = true;
        Node<T>* temp = root;
        Node<T>* temp_other_tree = other_tree.root;
        if(root->key == other_tree.root->key){
            if(temp->left && temp_other_tree->left){
                identicaly_left(temp, temp_other_tree, verificador);
            }
            if(temp->right && temp_other_tree->right){
                identicaly_right(temp, temp_other_tree, verificador);
            }
        } else {verificador = false;}
        return verificador;
    }

    void insert_node (const T& _value) {
        Node<T>* new_node = new Node<T>(_value);
        if(!root){
            root = new_node;
        } else {
            Node<T>* temp = root;
            while(temp){
                if (temp->key > _value)
                    if(temp->left)
                        temp = temp->left;
                    else {
                        temp->left = new_node;
                        Nodes++;
                        break;
                    }
                else if (temp->key < _value)
                    if(temp->right)
                        temp = temp->right;
                    else {
                        temp->right = new_node;
                        Nodes++;
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

    void in_order(Node<T>* temp){
        if(temp->left)
            in_order(temp->left);
        std::cout << temp->key << ' ';
        if(temp->right)
            in_order(temp->right);
    }

    void in_order(){
        if (root){
            Node<T>* temp = root;
            if(temp->left)
                in_order(temp->left);
            std::cout << temp->key << ' ';
            if(temp->right)
                in_order(temp->right);
        }
    }

    void pre_order(Node<T>* temp){
        std::cout << temp->key << ' ';
        if(temp->left)
            pre_order(temp->left);
        if(temp->right)
            pre_order(temp->right);
    }

    void pre_order(){
        if (root){
            Node<T>* temp = root;
            std::cout << temp->key << ' ';
            if(temp->left)
                pre_order(temp->left);
            if(temp->right)
                pre_order(temp->right);
        }
    }

    void post_order(Node<T>* temp){
        if(temp->left)
            post_order(temp->left);
        if(temp->right)
            post_order(temp->right);
        std::cout << temp->key << ' ';
    }

    void post_order(){
        if (root){
            Node<T>* temp = root;
            if(temp->left)
                post_order(temp->left);
            if(temp->right)
                post_order(temp->right);
            std::cout << temp->key << ' ';
        }
    }

    void same_level_left(Node<T>* temp, std::vector<T>* lista, int i, int cont){
        temp = temp->left;
        i++;
        if(cont == i){
            lista->push_back(temp->key);
        } else {
            if(temp->left){
                same_level_left(temp, lista, i, cont);
            }
            if(temp->right){
                same_level_right(temp, lista, i, cont);
            }
        }
    }

    void same_level_right(Node<T>* temp, std::vector<T>* lista, int i, int cont){
        temp = temp->right;
        i++;
        if(cont == i){
            lista->push_back(temp->key);
        } else {
            if(temp->left){
                same_level_left(temp, lista, i, cont);
            }
            if(temp->right){
                same_level_right(temp, lista, i, cont);
            }
        }
    }

    T next_in_same_level(T _value){
        if (root){
            Node<T>* temp = root;
            int cont1 = 0;
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
                    int i = 0;
                    int n = 1;
                    for(int j = 0; j < cont1; j++){n=n*2;}
                    std::vector<T>* lista = new std::vector<T>();
                    Node<T>* temp2 = root;
                    if(temp2->left){
                        same_level_left(temp2, lista, i, cont1);
                    }
                    if(temp2->right){
                        same_level_right(temp2, lista, i, cont1);
                    }
                    typename std::vector<T>::iterator it = lista->begin();
                    for(; it < lista->end(); it++){
                        if(_value == *it){
                            ++it;
                            if(it < lista->end()){return *it;} else { return NULL;}
                        }
                    }
                    break;
                }
                cont1++;
            }
        }
        return NULL;
    }

    bool complete (){
        Node<T>* temp = root;
        return (complete(temp->left, 1) && complete(temp->right, 2));
    }

    bool complete (Node<T>* temp, int index){
        if (temp == nullptr)
            return (true);

        if (index >= Nodes)
            return (false);

        return (complete(temp->left, 2*index + 1) && complete(temp->right, 2*index + 2));
    }

    void print_all_paths(Node<T>* temp, T path[], int pathLen)
    {
        if (temp == nullptr) return;

        path[pathLen] = temp->key;
        pathLen++;

        if (temp->left == nullptr && temp->right == nullptr)
        {
            std::cout << '\n';
            for(int i = 0; i < pathLen; i++){
                std::cout << path[i] << ' ';
            }
        }
        else
        {
            print_all_paths(temp->left, path, pathLen);
            print_all_paths(temp->right, path, pathLen);
        }
    }

    void print_all_paths(){
        if (root){
            Node<T>* temp = root;
            T path[Nodes];
            print_all_paths(temp, path, 0);
        }
    }

    void find_ancestor(T _value){
        if (root) {
            Node<T>* temp = root;
            std::list<T> lista;
            while(temp){
                lista.push_back(temp->key);
                if (temp->key > _value)
                    if(temp->left){
                        temp = temp->left;
                    } else {
                        return;
                    }
                else if (temp->key < _value)
                    if(temp->right){
                        temp = temp->right;
                    }
                    else {
                        return;
                    }
                else {
                    typename std::list<T>::iterator it;
                    lista.pop_back();
                    for(it = lista.begin(); it != lista.end();it++){
                        std::cout << *it << ' ';
                    }
                    std::cout << '\n';
                    return;
                }
            }
        }
    }

    bool balanced()
    {
        Node<T>* temp = root;
        int lh;
        int rh;


        if (temp == nullptr)
            return 1;

        lh = height(temp->left);
        rh = height(temp->right);

        if (lh - rh == 0 && balanced(temp->left) && balanced(temp->right))
            return 1;

        return 0;
    }

    bool balanced(Node<T>* temp)
    {
        int lh;
        int rh;


        if (temp == nullptr)
            return 1;

        lh = height(temp->left);
        rh = height(temp->right);

        if (lh - rh <= 1 && balanced(temp->left) && balanced(temp->right))
            return 1;

        return 0;
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

#endif //UNTITLED23_TREE_BST_H
