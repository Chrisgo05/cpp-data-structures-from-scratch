#include <iostream>
#include "SinglyCircularLinkList.h"

int main() {

    SinglyCircularLinkList lista;
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
    std::cout << "Tamano: " << lista.size() << "\n\n";


    std::cout << "===== FIND =====\n";

    if(lista.find(3) != nullptr)
        std::cout << "Se encontro el 3\n";

    if(lista.find(10) == nullptr)
        std::cout << "No se encontro el 10\n";

    std::cout << "\n";


    std::cout << "===== INSERT AFTER =====\n";
    lista.insertAfter(3,99);
    lista.print();


    std::cout << "\n===== INSERT BEFORE =====\n";
    lista.insertBefore(3,88);
    lista.print();


    std::cout << "\n===== POP FRONT =====\n";
    lista.popFront(eliminado);
    std::cout << "Valor eliminado: " << eliminado << "\n";
    lista.print();


    std::cout << "\n===== POP BACK =====\n";
    lista.popBack(eliminado);
    std::cout << "Valor eliminado: " << eliminado << "\n";
    lista.print();


    std::cout << "\n===== ERASE =====\n";

    std::cout << "Eliminar 88\n";
    lista.erase(88);
    lista.print();

    std::cout << "Eliminar 99\n";
    lista.erase(99);
    lista.print();

    std::cout << "Eliminar 3\n";
    lista.erase(3);
    lista.print();


    std::cout << "\n===== REVERSE =====\n";
    lista.reverse();
    lista.print();


    std::cout << "\n===== CLEAR =====\n";
    lista.clear();
    lista.print();
    std::cout << "Tamano: " << lista.size() << "\n";


    std::cout << "\n===== POP EN LISTA VACIA =====\n";

    if(!lista.popFront(eliminado))
        std::cout << "popFront detecto correctamente lista vacia.\n";

    if(!lista.popBack(eliminado))
        std::cout << "popBack detecto correctamente lista vacia.\n";

    std::cout << "\nFin del programa.\n";

    return 0;
}