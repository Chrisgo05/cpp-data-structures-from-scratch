#include <iostream>
#include "SinglyLinkList.h"

int main(){
    SinglyLinkList lista;
    int valor;

    std::cout << "===== LISTA VACIA =====\n";
    lista.print();
    std::cout << "Tamano: " << lista.size() << "\n\n";

    // ==========================
    std::cout << "===== PUSH BACK =====\n";
    lista.pushBack(1);
    lista.pushBack(2);
    lista.pushBack(3);
    lista.pushBack(4);
    lista.pushBack(5);

    lista.print();
    std::cout << "Tamano: " << lista.size() << "\n\n";

    // ==========================
    std::cout << "===== PUSH FRONT =====\n";
    lista.pushFront(0);
    lista.print();
    std::cout << "Tamano: " << lista.size() << "\n\n";

    // ==========================
    std::cout << "===== FIND =====\n";

    if (lista.find(3))
        std::cout << "Se encontro el 3\n";
    else
        std::cout << "No se encontro el 3\n";

    if (lista.find(10))
        std::cout << "Se encontro el 10\n";
    else
        std::cout << "No se encontro el 10\n";

    std::cout << "\n";

    // ==========================
    std::cout << "===== INSERT AFTER =====\n";
    lista.insertAfter(3, 99);
    lista.print();

    std::cout << "\n===== INSERT BEFORE =====\n";
    lista.insertBefore(3, 88);
    lista.print();
    std::cout << "\n";

    // ==========================
    std::cout << "===== POP FRONT =====\n";
    if (lista.popFront(valor))
        std::cout << "Valor eliminado: " << valor << "\n";

    lista.print();

    std::cout << "\n===== POP BACK =====\n";
    if (lista.popBack(valor))
        std::cout << "Valor eliminado: " << valor << "\n";

    lista.print();
    std::cout << "\n";

    // ==========================
    std::cout << "===== ERASE =====\n";

    lista.erase(88);
    lista.print();

    lista.erase(99);
    lista.print();

    lista.erase(3);
    lista.print();

    std::cout << "\n";

    // ==========================
    std::cout << "===== REVERSE =====\n";
    lista.reverse();
    lista.print();

    std::cout << "\n";

    // ==========================
    std::cout << "===== CLEAR =====\n";
    lista.clear();
    lista.print();

    std::cout << "Tamano: " << lista.size() << "\n";

    // ==========================
    std::cout << "\n===== PROBANDO POP EN LISTA VACIA =====\n";

    if (!lista.popFront(valor))
        std::cout << "popFront correctamente detecto lista vacia.\n";

    if (!lista.popBack(valor))
        std::cout << "popBack correctamente detecto lista vacia.\n";

    return 0;
}