#include <iostream>
#include "BinarySearchTree.h"

int main() {
    BinarySearchTree<int> arbol;

    std::cout << "===== INSERT =====\n";

    int valores[] = {50,25,75,12,37,62,87,6,18,31,43,56,68,81,93};

    for (int x : valores) {
        arbol.insert(x);
    }

    std::cout << "\nInorder:\n";
    arbol.inorder();

    std::cout << "\n\nPreorder:\n";
    arbol.preorder();

    std::cout << "\n\nPostorder:\n";
    arbol.postorder();

    std::cout << "\n\nTree:\n";
    arbol.printTree();

    std::cout << "\nAltura: " << arbol.altura() << std::endl;
    std::cout << "Size: " << arbol.size() << std::endl;

    std::cout << "\n===== SEARCH =====\n";

    int buscar[] = {50,93,12,100};

    for (int x : buscar) {
        if (arbol.search(x) != nullptr)
            std::cout << x << " encontrado\n";
        else
            std::cout << x << " NO encontrado\n";
    }

    std::cout << "\n===== FIND MIN / MAX =====\n";

    std::cout << "Min: " << arbol.findMin()->valor << std::endl;
    std::cout << "Max: " << arbol.findMax()->valor << std::endl;

    std::cout << "\n===== REMOVE =====\n";

    std::cout << "\nEliminar hoja (18)\n";
    arbol.remove(18);
    arbol.printTree();

    std::cout << "\nEliminar nodo con un hijo (12)\n";
    arbol.remove(12);
    arbol.printTree();

    std::cout << "\nEliminar nodo con dos hijos (75)\n";
    arbol.remove(75);
    arbol.printTree();

    std::cout << "\nEliminar raiz (50)\n";
    arbol.remove(50);
    arbol.printTree();

    std::cout << "\nIntentar eliminar inexistente (999)\n";
    if (arbol.remove(999))
        std::cout << "Se elimino\n";
    else
        std::cout << "No existe\n";

    std::cout << "\n===== CLEAR =====\n";

    arbol.clear();

    std::cout << "Empty: " << arbol.empty() << std::endl;
    std::cout << "Size: " << arbol.size() << std::endl;
    std::cout << "Altura: " << arbol.altura() << std::endl;

    std::cout << "\nFin del programa.\n";

    return 0;
}