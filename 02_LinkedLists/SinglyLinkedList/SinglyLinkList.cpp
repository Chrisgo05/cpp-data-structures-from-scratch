#include "SinglyLinkList.h"
#include <iostream>

SinglyLinkList::SinglyLinkList(){
    head = nullptr;
    tail = nullptr;
}

SinglyLinkList::~SinglyLinkList(){
    clear();
}

Nodo* SinglyLinkList::findBefore(int buscando){
    Nodo* actual = head;
    while(actual != nullptr && actual->siguiente != nullptr){
        if(actual->siguiente->valor == buscando){
            return actual;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}

void SinglyLinkList::pushFront(int valor){
    if (head == nullptr){
        head = new Nodo;
        head-> valor = valor;
        tail = head;
    }else{
        Nodo* nuevo = new Nodo;
        nuevo -> valor = valor;
        nuevo -> siguiente = head;
        head = nuevo;
    }
}

bool SinglyLinkList::popFront(int& valor){
    if(head == nullptr && tail == nullptr){
        return false;
    }
    else if(head == tail){
        valor = head -> valor;
        delete head;
        head = nullptr;
        tail = head;
        return true;
    }else{
        Nodo* temp = head;
        head = head -> siguiente;
        valor = temp -> valor;
        delete temp;
        return true;
    }
}

void SinglyLinkList::pushBack(int valor){
    if (tail == nullptr){
        tail = new Nodo;
        tail -> valor = valor;
        head = tail;
    }else{
        Nodo* nuevo = new Nodo;
        tail -> siguiente = nuevo;
        tail = tail -> siguiente;
        tail -> valor = valor;
    }
}

bool SinglyLinkList::popBack(int& valor){
    if(tail == nullptr){
        return false;
    }else if(tail == head){
        valor = tail -> valor;
        delete tail;
        tail = nullptr;
        head = tail;
        return true;
    }else{
        Nodo* actual = head;
        valor = tail -> valor;
        while(actual->siguiente != tail){
            actual = actual->siguiente;
        }
        actual-> siguiente = nullptr;
        delete tail;
        tail = actual;
        return true;
    }
}

Nodo* SinglyLinkList:: find(int buscando){
    Nodo* actual = head;
    while(actual != nullptr){
        if(actual -> valor == buscando){
            return actual;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}

bool SinglyLinkList::insertAfter(int vAntes, int valor){
    Nodo* nAntes = find(vAntes);
    
    if(nAntes != nullptr && nAntes -> siguiente != nullptr){ // por si esta en el medio
        Nodo* nDespues = nAntes -> siguiente;
        Nodo* nIntermedio = new Nodo;
        
        nIntermedio -> valor = valor;
        nIntermedio -> siguiente = nDespues;
        nAntes -> siguiente = nIntermedio;
        
        return true;
        
    }else if(nAntes != nullptr && nAntes -> siguiente == nullptr){ //por si es despues del ultimo nodo valido 
        pushBack(valor);
        return true;
        
    }else if(nAntes == nullptr){
        return false;
        
    }
    return false;
}

bool SinglyLinkList::insertBefore(int vDespues, int valor){
        Nodo* nAntes = findBefore(vDespues);

    if(head != nullptr && head->valor == vDespues){ //por si el valor es la cabeza actual
        pushFront(valor);
        return true;
        
    }else if(head != nullptr && nAntes != nullptr){ //si esta en medio
        Nodo* nDespues = nAntes->siguiente;
        Nodo* nIntermedio = new Nodo;

        nIntermedio -> valor = valor;
        nAntes -> siguiente = nIntermedio;
        nIntermedio -> siguiente = nDespues;

        return true;

    }else{
        return false;

    }
    return false;
}


bool SinglyLinkList::erase(int valor){
    int valorEliminado;
    Nodo* nAntes = findBefore(valor);

    if(head != nullptr && head -> valor == valor){
        popFront(valorEliminado);
        return true;

    }else if(tail != nullptr && tail -> valor == valor){
        popBack(valorEliminado);
        return true;

    }else if(nAntes != nullptr && head != nullptr){
        Nodo* nBorrar = nAntes -> siguiente;

        nAntes -> siguiente = nBorrar -> siguiente;
        delete nBorrar;

        return true;

    }else{
        return false;

    }
}

void SinglyLinkList::clear(){
    while(head != nullptr && tail != nullptr){
        if(head == tail){
            delete head;
            head = nullptr;
            tail = head;
            break;
        }

        Nodo* temp = head;
        head = head -> siguiente;

        delete temp;
    }
}

int SinglyLinkList::size(){
    Nodo* actual = head;
    int tam = 0;

    if(head == nullptr){
        return tam;
    }
    
    while(actual != tail){
        tam++;
        actual = actual -> siguiente;
    }
    tam++;
    return tam;
}

void SinglyLinkList::print(){
    Nodo* actual = head;
    while(actual != nullptr){
        std::cout << actual->valor << " ";
        actual = actual->siguiente;
    }
    std::cout << "\n";
}

void SinglyLinkList::reverse(){
    if(head == tail || head == nullptr){
        return;
    }
    Nodo* temph = head; //guarda direccion del primer elemento

    Nodo* inverlista = head;  //empieza la lista invertida
    Nodo* temp; // prepara la temporal

    head = head-> siguiente; //avanza uno en la lista normal
    inverlista -> siguiente = nullptr; // desvincula la lista invertida de la normal

    while(head != tail){ 
        temp = head -> siguiente; //guarda el siguiente nodo del nodo actual
        head -> siguiente = inverlista; //conceta el nodo actual a la lista invertida
        inverlista = head; // mueve la variable de inicio de la lista invertida
        head = temp; //cambia al nodo guardado anteriormente
        
    }

    tail ->siguiente = inverlista; //conecta la antigua cola con la lista invertida
    head = tail; //cambia la variable que identifica la cabeza (ya no es la variable tail ahora es la de head)
    tail = temph; //asigna el final de la lista a la variable que es(o sea la tail)
}