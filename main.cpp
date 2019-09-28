#include <iostream>
#include "Tree_BST.h"
#include "Tree.h"

template<typename T>
bool BST(Node<T>* temp){
    bool verificador = 1;
    if(temp->left){
        if(temp->left->key < temp->key){
            verificador = 1*BST(temp->left);
        } else {
            verificador = 0*BST(temp->left);
        }
    }
    if(temp->right){
        if(temp->right->key > temp->key){
            verificador = 1*BST(temp->right);
        } else {
            verificador = 0*BST(temp->right);
        }
    }
    return verificador;
}

template<typename T>
bool BST(Tree<T> tree){
    Node<T>* temp = tree.root;
    return BST(temp);
}

template<typename T>
void convert_BST(Node<T>* temp, std::list<T>* lista){
    lista->push_back(temp->key);
    if(temp->left){
        convert_BST(temp->left, lista);
    }
    if(temp->right){
        convert_BST(temp->right, lista);
    }
}

template<typename T>
void convert_BST(Tree<T>* tree){
    Node<T>* temp = tree->root;
    Tree_BST<T> tree_BST;
    std::list<T> lista;
    convert_BST(temp, &lista);
    tree->delete_all_tree();
    typename std::list<T>::iterator it;
    for(it = lista.begin(); it != lista.end(); it++){
        tree_BST.insert_node(*it);
    }
    tree->root = tree_BST.root;
}


int main() {
    Tree_BST<int> tree;
    tree.insert_node(5);
    tree.insert_node(2);
    tree.insert_node(1);
    tree.insert_node(4);
    tree.insert_node(3);
    tree.insert_node(6);

    Tree_BST<int> tree2;
    tree2.insert_node(5);
    tree2.insert_node(2);
    tree2.insert_node(1);
    tree2.insert_node(4);
    tree2.insert_node(3);
    tree2.insert_node(6);

    Tree_BST<int> tree3;
    tree3.insert_node(8);
    tree3.insert_node(4);
    tree3.insert_node(12);
    tree3.insert_node(2);
    tree3.insert_node(6);
    tree3.insert_node(10);
    tree3.insert_node(14);/*
    tree3.insert_node(1);
    tree3.insert_node(3);
    tree3.insert_node(5);
    tree3.insert_node(7);
    tree3.insert_node(9);
    tree3.insert_node(11);
    tree3.insert_node(13);
    tree3.insert_node(15);*/

    Tree<int> tree4;
    tree4.insert_node(4);
    tree4.insert_node(5);
    tree4.insert_node(6);
    tree4.insert_node(1);
    tree4.insert_node(2);
    tree4.insert_node(3);

    Tree<int> tree5;
    tree5.insert_node(2);
    tree5.insert_node(1);
    tree5.insert_node(3);

    std::cout << "Arbol BST: " << '\n';
    tree.print();


    std::cout << "Complete: " << tree.complete() << '\n';
    std::cout << "Verificador antes de eliminaar el 5 del primer arbol: " << tree.identicaly(tree2) << '\n';

    tree.delete_node(5);

    std::cout << "Verificador despues de eliminar el 5 del primer arbol: " << tree.identicaly(tree2) << '\n';

    tree.print();
    std::cout << "In-Order: ";
    tree.in_order();
    std::cout << '\n' << "Pre-Order: ";
    tree.pre_order();
    std::cout << '\n' << "Post-Order: ";
    tree.post_order();
    std::cout << '\n' << "All Paths: ";
    tree.print_all_paths();
    std::cout << '\n';
    std::cout << "Altura: " << tree.height() << '\n';
    std::cout << "Siguiente de 2 en el mismo nivel: " << tree.next_in_same_level(2) << '\n';
    std::cout << "Nodo ancestro de 3: ";
    tree.find_ancestor(3);
    std::cout << '\n';
    std::cout << "Balanceado arbol 1: " << tree.balanced() << '\n';
    std::cout << "Balanceado arbol 3: " << tree3.balanced() << '\n';
    std::cout << "Complete: " << tree.complete() << '\n';
    tree.delete_all_tree();
    tree.insert_node(1);
    std::cout << "Borrado de arbol y colocacion de un valor nuevo: " << tree.root->key << '\n';
    std::cout << "Arbol 4: " << '\n';
    tree4.print();
    std::cout << "BST?: " << BST(tree4) << '\n';
    convert_BST(&tree4);
    std::cout << "Arbol 4 convertido: " << '\n';
    tree4.print();
    std::cout << "Arbol 5: " << '\n';
    tree5.print();
    std::cout << "BST?: " << BST(tree5) << '\n';
    return 0;
}