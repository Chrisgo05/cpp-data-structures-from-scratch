#include <iostream>
#include <string>

#include "QueueTemplate.h"

int main(){

    // ==============================
    // QUEUE<int>
    // ==============================
    std::cout << "==============================\n";
    std::cout << "QUEUE<int>\n";
    std::cout << "==============================\n";

    QueueTemplate<int> cola;
    int valor;

    std::cout << "Empty inicial: " << cola.empty() << "\n";
    std::cout << "Tamano inicial: " << cola.size() << "\n\n";

    // ==============================
    std::cout << "===== ENQUEUE =====\n";

    cola.enqueue(10);
    cola.enqueue(20);
    cola.enqueue(30);
    cola.enqueue(40);

    std::cout << "Tamano: " << cola.size() << "\n";

    if(cola.front(valor))
        std::cout << "Front: " << valor << "\n";

    std::cout << "\n";

    // ==============================
    std::cout << "===== DEQUEUE =====\n";

    while(cola.dequeue(valor)){
        std::cout << "Dequeue: " << valor << "\n";
    }

    std::cout << "\n";

    // ==============================
    std::cout << "===== QUEUE VACIA =====\n";

    std::cout << "Tamano: " << cola.size() << "\n";
    std::cout << "Empty: " << cola.empty() << "\n";

    if(!cola.dequeue(valor))
        std::cout << "Dequeue correctamente detecto cola vacia.\n";

    if(!cola.front(valor))
        std::cout << "Front correctamente detecto cola vacia.\n";

    std::cout << "\n";


    // ==============================
    // QUEUE<double>
    // ==============================
    std::cout << "==============================\n";
    std::cout << "QUEUE<double>\n";
    std::cout << "==============================\n";

    QueueTemplate<double> colaDouble;
    double decimal;

    colaDouble.enqueue(1.5);
    colaDouble.enqueue(2.75);
    colaDouble.enqueue(3.1416);

    if(colaDouble.front(decimal))
        std::cout << "Front: " << decimal << "\n";

    while(colaDouble.dequeue(decimal)){
        std::cout << "Dequeue: " << decimal << "\n";
    }

    std::cout << "\n";


    // ==============================
    // QUEUE<string>
    // ==============================
    std::cout << "==============================\n";
    std::cout << "QUEUE<string>\n";
    std::cout << "==============================\n";

    QueueTemplate<std::string> colaString;
    std::string texto;

    colaString.enqueue("Hola");
    colaString.enqueue("Templates");
    colaString.enqueue("Queue");

    if(colaString.front(texto))
        std::cout << "Front: " << texto << "\n";

    while(colaString.dequeue(texto)){
        std::cout << "Dequeue: " << texto << "\n";
    }

    return 0;
}