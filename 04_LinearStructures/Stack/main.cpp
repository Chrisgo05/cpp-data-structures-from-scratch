#include <iostream>
#include <string>

#include "StackTemplate.h"

int main(){

    std::cout << "==============================\n";
    std::cout << "STACK<int>\n";
    std::cout << "==============================\n";

    StackTemplate<int> s1;
    int x;

    s1.push(10);
    s1.push(20);
    s1.push(30);

    std::cout << "Tamano: " << s1.size() << "\n";

    if(s1.top(x))
        std::cout << "Top: " << x << "\n";

    while(s1.pop(x)){
        std::cout << "Pop: " << x << "\n";
    }

    std::cout << "Empty: " << s1.empty() << "\n\n";


    std::cout << "==============================\n";
    std::cout << "STACK<double>\n";
    std::cout << "==============================\n";

    StackTemplate<double> s2;
    double d;

    s2.push(3.14);
    s2.push(2.71);
    s2.push(1.41);

    while(s2.pop(d)){
        std::cout << d << "\n";
    }

    std::cout << "\n";


    std::cout << "==============================\n";
    std::cout << "STACK<string>\n";
    std::cout << "==============================\n";

    StackTemplate<std::string> s3;
    std::string texto;

    s3.push("Hola");
    s3.push("Templates");
    s3.push("Stack");

    while(s3.pop(texto)){
        std::cout << texto << "\n";
    }

    std::cout << "\n";


    std::cout << "==============================\n";
    std::cout << "STACK VACIO\n";
    std::cout << "==============================\n";

    if(!s1.pop(x))
        std::cout << "No se pudo hacer pop.\n";

    if(!s1.top(x))
        std::cout << "No hay elemento en el top.\n";

    return 0;
}