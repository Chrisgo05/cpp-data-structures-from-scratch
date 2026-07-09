#include <iostream>
#include "DoublyCircularLinkList.h"

int main() {

    DoublyCircularLinkList lista;
    int eliminado;

    std::cout << "===== LISTA VACIA =====\n";
    lista.print();
    std::cout << "Tamano: " << lista.size() << "\n\n";

    std::cout << "===== PUSH BACK =====\n";
    lista.pushBack(1);
    lista.pushBack(2);
    lista.pushBack(3);
    lista.pushBack(4);
    lista.pushBack(5);
    lista.print();
    std::cout << "Tamano: " << lista.size() << "\n\n";

    std::cout << "===== PUSH FRONT =====\n";
    lista.pushFront(0);
    lista.print();
    std::cout << "\n";

    std::cout << "===== FIND =====\n";
    if(lista.find(3))
        std::cout << "Se encontro el 3\n";
    else
        std::cout << "No se encontro el 3\n";

    if(lista.find(10))
        std::cout << "Se encontro el 10\n";
    else
        std::cout << "No se encontro el 10\n";

    std::cout << "\n";

    std::cout << "===== INSERT AFTER =====\n";
    lista.insertAfter(3, 99);
    lista.print();
    std::cout << "\n";

    std::cout << "===== INSERT BEFORE =====\n";
    lista.insertBefore(3, 88);
    lista.print();
    std::cout << "\n";

    std::cout << "===== POP FRONT =====\n";
    lista.popFront(eliminado);
    std::cout << "Valor eliminado: " << eliminado << "\n";
    lista.print();
    std::cout << "\n";

    std::cout << "===== POP BACK =====\n";
    lista.popBack(eliminado);
    std::cout << "Valor eliminado: " << eliminado << "\n";
    lista.print();
    std::cout << "\n";

    std::cout << "===== ERASE =====\n";
    std::cout << "Eliminar 88\n";
    lista.erase(88);
    lista.print();

    std::cout << "Eliminar 99\n";
    lista.erase(99);
    lista.print();

    std::cout << "Eliminar 3\n";
    lista.erase(3);
    lista.print();
    std::cout << "\n";

    std::cout << "===== REVERSE (rompiendo el circulo) =====\n";
    lista.reverse();
    lista.print();
    std::cout << "\n";

    std::cout << "===== AGREGAR MAS ELEMENTOS =====\n";
    lista.pushBack(6);
    lista.pushFront(-1);
    lista.print();
    std::cout << "\n";

    std::cout << "===== REVERSE CIRCULAR =====\n";
    lista.reverseCircular();
    lista.print();
    std::cout << "\n";

    std::cout << "===== CLEAR =====\n";
    lista.clear();
    lista.print();
    std::cout << "Tamano: " << lista.size() << "\n\n";

    std::cout << "===== POP EN LISTA VACIA =====\n";
    if(!lista.popFront(eliminado))
        std::cout << "popFront detecto correctamente lista vacia.\n";

    if(!lista.popBack(eliminado))
        std::cout << "popBack detecto correctamente lista vacia.\n";

    std::cout << "\nFin del programa.\n";

    return 0;
}