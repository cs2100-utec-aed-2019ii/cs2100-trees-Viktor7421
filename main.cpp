#include <iostream>
#include "Tree.h"

int main() {
    Tree<int> tree;
    tree.insert_node(5);
    tree.insert_node(1);
    tree.insert_node(4);
    tree.insert_node(3);
    tree.insert_node(2);
    tree.delete_node(5);
    std::cout << tree.root->left->key << ' ';
    std::cout << tree.root->left->right->left->key << ' ';
    std::cout << tree.root->left->right->key << ' ';
    std::cout << tree.root->key << '\n';
    std::cout << tree.get_height() << ' ';
    //std::cout << tree.root->right->key << ' ';
    return 0;
}