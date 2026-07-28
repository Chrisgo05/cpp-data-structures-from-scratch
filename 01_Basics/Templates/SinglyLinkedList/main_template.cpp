#include <iostream>
#include <string>
#include "SinglyLinkListTemplate.h"

int main() {

    // ==========================================
    // PRUEBA CON INT
    // ==========================================

    std::cout << "==============================\n";
    std::cout << "PRUEBA CON INT\n";
    std::cout << "==============================\n";

    SinglyLinkListTemplate<int> listaInt;
    int valorInt;

    listaInt.pushBack(10);
    listaInt.pushBack(20);
    listaInt.pushBack(30);
    listaInt.pushFront(5);

    listaInt.print();

    listaInt.insertAfter(20, 25);
    listaInt.insertBefore(20, 15);

    listaInt.print();

    listaInt.popFront(valorInt);
    std::cout << "PopFront: " << valorInt << '\n';

    listaInt.popBack(valorInt);
    std::cout << "PopBack: " << valorInt << '\n';

    listaInt.print();

    listaInt.reverse();
    listaInt.print();

    std::cout << "Tamano: " << listaInt.size() << "\n\n";


    // ==========================================
    // PRUEBA CON DOUBLE
    // ==========================================

    std::cout << "==============================\n";
    std::cout << "PRUEBA CON DOUBLE\n";
    std::cout << "==============================\n";

    SinglyLinkListTemplate<double> listaDouble;
    double valorDouble;

    listaDouble.pushBack(1.5);
    listaDouble.pushBack(2.75);
    listaDouble.pushBack(3.1416);

    listaDouble.print();

    listaDouble.popFront(valorDouble);

    std::cout << "PopFront: " << valorDouble << '\n';

    listaDouble.print();

    std::cout << '\n';


    // ==========================================
    // PRUEBA CON STRING
    // ==========================================

    std::cout << "==============================\n";
    std::cout << "PRUEBA CON STRING\n";
    std::cout << "==============================\n";

    SinglyLinkListTemplate<std::string> listaString;
    std::string palabra;

    listaString.pushBack("Hola");
    listaString.pushBack("Mundo");
    listaString.pushFront("!");

    listaString.print();

    listaString.insertAfter("Hola", "Templates");

    listaString.print();

    listaString.reverse();

    listaString.print();

    listaString.popBack(palabra);

    std::cout << "PopBack: " << palabra << '\n';

    listaString.print();

    return 0;
}