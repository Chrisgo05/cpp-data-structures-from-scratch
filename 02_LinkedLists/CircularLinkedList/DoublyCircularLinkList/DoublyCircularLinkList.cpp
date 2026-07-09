#include <iostream>
#include "DoublyCircularLinkList.h"

DoublyCircularLinkList::DoublyCircularLinkList(){
    head = nullptr;
    tail = nullptr;
}

DoublyCircularLinkList::~DoublyCircularLinkList(){
    clear();
}


void DoublyCircularLinkList::pushFront(int valor){
    Nodo* nuevo = new Nodo;
    nuevo -> valor = valor;

    if(head == nullptr){
        head = nuevo;
        tail = head;
        head -> siguiente = tail;
        head -> anterior = tail;
    }else{
        nuevo -> siguiente = head;
        head -> anterior = nuevo;
        head = nuevo;
        head -> anterior = tail;
        tail -> siguiente = head;
    }
}

bool DoublyCircularLinkList::popFront(int& valorpop){
    if(head == tail && head != nullptr){
        valorpop = head -> valor;
        delete head;

        head = nullptr;
        tail = head;

        return true;
    }else if(head != nullptr){
        Nodo* borrar = head;
        valorpop = head -> valor;

        head = head -> siguiente;

        head -> anterior = tail;
        tail -> siguiente = head;
        delete borrar;

        return true;
    }
    return false;
}

void DoublyCircularLinkList::pushBack(int valor){
    Nodo* nuevo = new Nodo;
    nuevo -> valor = valor;

    if(head == nullptr){
        tail = nuevo;
        head = tail;
        tail -> siguiente = head;
        tail -> anterior = head;
    }else{
        tail -> siguiente = nuevo;
        nuevo -> anterior = tail;
        tail = nuevo;
        tail -> siguiente = head;
        head -> anterior = tail;
    }

}

bool DoublyCircularLinkList::popBack(int& valorpop){
    if(head == tail && tail != nullptr){
        valorpop = tail -> valor;
        delete tail;

        tail = nullptr;
        head = tail;

        return true;
    }else if(tail != nullptr){
        Nodo* borrar = tail;
        valorpop = tail -> valor;

        tail = tail -> anterior;

        tail -> siguiente = head;
        head -> anterior = tail;
        delete borrar;

        return true;
    }
    return false;
}


bool DoublyCircularLinkList::insertAfter(int vAntes, int valor){
    Nodo* nAntes = find(vAntes);
    if(nAntes == tail && tail != nullptr){
        pushBack(valor);
        return true;
    }else if(nAntes != nullptr){
        Nodo* nDespues = nAntes -> siguiente;
        Nodo* nIntermedio = new Nodo;
        nIntermedio -> valor = valor;

        nAntes -> siguiente = nIntermedio;
        nDespues -> anterior = nIntermedio;
        nIntermedio -> siguiente = nDespues;
        nIntermedio -> anterior = nAntes;

        return true;
    }
    return false;
}

bool DoublyCircularLinkList::insertBefore(int vDespues, int valor){
    Nodo* nDespues = find(vDespues);
    if(nDespues == head && head != nullptr){
        pushFront(valor);
        return true;
    }else if(nDespues != nullptr){
        Nodo* nAntes = nDespues -> anterior;
        Nodo* nIntermedio = new Nodo;
        nIntermedio -> valor = valor;

        nAntes -> siguiente = nIntermedio;
        nDespues -> anterior = nIntermedio;
        nIntermedio -> siguiente = nDespues;
        nIntermedio -> anterior = nAntes;

        return true;
    }
    return false;
}


Nodo* DoublyCircularLinkList::find(int valor){
    if(head == nullptr){
        return nullptr;
    }else{
        Nodo* actual = head;
        do{
            if(actual -> valor == valor){
                return actual;
            }
            actual = actual -> siguiente;
        }while(actual != head);

        return nullptr;
    }
}

bool DoublyCircularLinkList::erase(int valor){
    Nodo* borrar = find(valor);
    int valorElimnado;

    if(borrar == head && head != nullptr){
        popFront(valorElimnado);
        return true;

    }else if(borrar == tail && tail != nullptr){
        popBack(valorElimnado);
        return true;

    }else if(borrar != nullptr){
        Nodo* nAntes = borrar -> anterior;
        Nodo* nDespues = borrar -> siguiente;

        nAntes -> siguiente = nDespues;
        nDespues -> anterior = nAntes;
        delete borrar;
        return true;
    }

    return false;
}


int DoublyCircularLinkList::size(){
    int tam = 0;

    if(head == nullptr){
        return tam;
    }else{
        Nodo* actual = head;
        do{
            tam++;
            actual = actual -> siguiente;

        }while(actual != head);

        return tam;
    }
}


void DoublyCircularLinkList::clear(){
    if(head == nullptr){
        return;
    }else{
        while(head != tail){
            Nodo* actual = head;
            head = head -> siguiente;
            delete actual;
            
        }
        
        delete tail;
        tail = nullptr;
        head = tail;
    }
}

void DoublyCircularLinkList::print(){
    if(head == nullptr){
        std::cout << "lista vacia" << std::endl;
    }else{
        Nodo* actual = head;
        do{
            std::cout << actual -> valor << " ";
            actual = actual -> siguiente;
            
        }while(head != actual);
        std::cout << std::endl;
    }
}

void DoublyCircularLinkList::reverse(){
    if(head == nullptr || head == tail){
        return;
    }else{
        tail -> siguiente = nullptr;
        head -> anterior = nullptr;
        Nodo* antiguaCabeza = head;
        Nodo* antiguaCola = tail;
        Nodo* actual = head;
        Nodo* tempSig;

        while(actual != nullptr){
            tempSig = actual -> siguiente;
            actual -> siguiente = actual -> anterior;
            actual -> anterior = tempSig;

            actual = actual -> anterior;
        }

        head = antiguaCola;
        tail = antiguaCabeza;

        head -> anterior = tail;
        tail -> siguiente = head;
    }
}

void DoublyCircularLinkList::reverseCircular(){
    if(head == tail || head == nullptr){
        return;
    }else{
        Nodo* actual = head;

        do{
            swapLinks(actual -> siguiente, actual -> anterior);
            actual = actual -> anterior;

        }while(actual != head);

        swapLinks(head, tail);
    }
}

void DoublyCircularLinkList::swapLinks(Nodo*& nodo1, Nodo*& nodo2){
    Nodo* temp = nodo1;
    nodo1 = nodo2;
    nodo2 = temp;
}