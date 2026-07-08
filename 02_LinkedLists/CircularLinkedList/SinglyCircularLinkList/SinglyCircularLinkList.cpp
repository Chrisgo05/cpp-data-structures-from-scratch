#include <iostream>
#include "SinglyCircularLinkList.h"

SinglyCircularLinkList::SinglyCircularLinkList(){
    head = nullptr;
    tail = nullptr;
}

SinglyCircularLinkList::~SinglyCircularLinkList(){
    clear();
}

void SinglyCircularLinkList::pushFront(int valor){
    Nodo* nuevo = new Nodo;
    nuevo -> valor = valor;

    if(head == nullptr){
        head = nuevo;
        tail = head;
        tail -> siguiente = head;
    }else{
        nuevo -> siguiente = head;
        head = nuevo;
        tail -> siguiente = head;
    }
}

bool SinglyCircularLinkList::popFront(int& valorpop){
    if(head == nullptr){
        return false;
    }else if(head == tail){
        valorpop = head -> valor;
        delete head;
        head = nullptr;
        tail = head;
        return true; 
    }else{
        valorpop = head -> valor;
        Nodo* borra = head;
        head = head -> siguiente;
        delete borra;
        tail -> siguiente = head;
        return true;
    }
}

void SinglyCircularLinkList::pushBack(int valor){
    Nodo* nuevo = new Nodo;
    nuevo -> valor = valor;

    if(tail == nullptr){
        tail = nuevo;
        head = tail;
        tail -> siguiente = head;
    }else{
        tail -> siguiente = nuevo;
        tail = tail -> siguiente;
        tail -> siguiente = head;
    }
}

bool SinglyCircularLinkList::popBack(int& valorpop){
    if(tail == nullptr){
        return false;
    }else if(head == tail){
        valorpop = tail -> valor;
        delete tail;
        tail = nullptr;
        head = tail;
        return true; 
    }else{
        valorpop = tail -> valor;
        Nodo* borra = tail;
        tail = findBefore(tail -> valor);
        tail -> siguiente = head;
        delete borra;
        return true;
    }
}


bool SinglyCircularLinkList::insertAfter(int vAntes ,int valor){
    Nodo* nAntes = find(vAntes);
    if(nAntes == nullptr){
        return false;
    }else if(vAntes == tail -> valor){
        pushBack(valor);
        return true;
    }else{
        Nodo* nDespues = nAntes -> siguiente;
        Nodo* nIntermedio = new Nodo;
    
        nIntermedio -> valor = valor;

        nAntes -> siguiente = nIntermedio;
        nIntermedio ->siguiente = nDespues;
        return true;
    }
}

bool SinglyCircularLinkList::insertBefore(int vDespues, int valor){
    Nodo* nAntes = findBefore(vDespues);
    if(nAntes == nullptr){
        return false;
    }else if(vDespues == head -> valor){
        pushFront(valor);
        return true;
    }else{
        Nodo* nDespues = nAntes -> siguiente;
        Nodo* nIntermedio = new Nodo;
    
        nIntermedio -> valor = valor;

        nAntes -> siguiente = nIntermedio;
        nIntermedio ->siguiente = nDespues;
        return true;
    }
}


Nodo* SinglyCircularLinkList::find(int buscando){
    Nodo* actual = head;
    if(head == nullptr){
        return nullptr;
    }
    
    do{
        if(buscando == actual -> valor){
            return actual;
        }

        actual = actual -> siguiente;
    }while(actual != head);

    return nullptr;
}

Nodo* SinglyCircularLinkList::findBefore(int vDespues){
    if(head == nullptr){
        return nullptr;
    }else if(vDespues == head -> valor){
        return tail;
    }
    else{
        Nodo* actual = head;
        do{
            if(actual -> siguiente -> valor == vDespues){
                return actual;
            }
            actual = actual -> siguiente;
        }while(actual != head);
        return nullptr;
    }
}

bool SinglyCircularLinkList::erase(int valor){
    Nodo* nAntes = findBefore(valor);
    int valorEliminado;

    if(head != nullptr && valor == head -> valor){
        popFront(valorEliminado);
        return true;
    }else if(tail != nullptr && valor == tail -> valor){
        popBack(valorEliminado);
        return true;
    }else if(nAntes != nullptr){
        Nodo* borrar = nAntes -> siguiente;
        Nodo* nDespues = borrar -> siguiente;

        nAntes -> siguiente = nDespues;
        delete borrar;
        return true;
    }
    return false;
}

void SinglyCircularLinkList::clear(){
    if(head == nullptr){
        return;

    }else{
        do{
            Nodo* actual = head;
            head = head -> siguiente;
            delete actual;

        }while(head != tail);

        delete tail;
        head = nullptr;
        tail = head;
    }
}

int SinglyCircularLinkList::size(){
    int tam = 0;
    if(head == nullptr){
        return tam;
    }

    Nodo* actual = head;

    do{
        tam++;
        actual = actual -> siguiente;

    }while(actual != head);

    return tam;
}

void SinglyCircularLinkList::print(){
    if(head == nullptr){
        std::cout << "Lista vacia" << "\n";
    }else{
        Nodo* actual = head;
        do{
            std::cout << actual -> valor << " ";
    
            actual = actual -> siguiente;
        }while(actual != head);
    
        std::cout << "\n";
    }
}

void SinglyCircularLinkList::reverse(){
    if(head == nullptr || head == tail){
        return;
    }else{
        tail -> siguiente = nullptr;
        Nodo* nuevoCirculo = head;
        Nodo* antiguaCabeza = head;
        Nodo* temp;

        head = head -> siguiente;
        nuevoCirculo -> siguiente = nullptr;

        while(head != tail){
            temp = head -> siguiente;
            head -> siguiente = nuevoCirculo;
            nuevoCirculo = head;
            head = temp;
        }

        tail -> siguiente = nuevoCirculo;
        head = tail;
        tail = antiguaCabeza;

        tail -> siguiente = head;

    }
}