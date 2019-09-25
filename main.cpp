#include <iostream>
#include "Tree.h"

int main() {
    Tree<int> tree;
    tree.insert_node(5);
    tree.insert_node(2);
    tree.insert_node(1);
    tree.insert_node(4);
    tree.insert_node(3);
    tree.insert_node(6);

    Tree<int> tree2;
    tree2.insert_node(5);
    tree2.insert_node(2);
    tree2.insert_node(1);
    tree2.insert_node(4);
    tree2.insert_node(3);
    tree2.insert_node(6);

    std::cout << "Complete: " << tree.complete() << '\n';
    std::cout << "Verificador antes de eliminaar el 5 del primer arbol: " << tree.identicaly(tree2) << '\n';

    tree.delete_node(5);

    std::cout << "Verificador despues de eliminar el 5 del primer arbol: " << tree.identicaly(tree2) << '\n';

    std::cout << "In-Order: ";
    tree.in_order();
    std::cout << '\n' << "Pre-Order: ";
    tree.pre_order();
    std::cout << '\n' << "Post-Order: ";
    tree.post_order();
    std::cout << '\n' << "All Paths: ";
    tree.print_all_paths();
    std::cout << '\n';
    std::cout << "Altura: " << tree.get_height() << '\n';
    std::cout << "Siguiente de 2 en el mismo nivel: " << tree.next_in_same_level(2) << '\n';
    std::cout << "Nodo ancestro de 3: " << tree.find_ancestor(3) << '\n';
    std::cout << "Complete: " << tree.complete() << '\n';
    tree.delete_all_tree();
    tree.insert_node(1);
    std::cout << "Borrado de arbol y colocacion de un valor nuevo: " << tree.root->key << '\n';
    return 0;
}