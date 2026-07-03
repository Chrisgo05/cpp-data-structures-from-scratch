#include <iostream>
#include "DoublyLinkList.h"

DoublyLinkList::DoublyLinkList(){
    head = nullptr;
    tail = nullptr;
}

DoublyLinkList::~DoublyLinkList(){
    clear();
}

void DoublyLinkList::pushFront(int valor){
    if(head == nullptr){
        head = new Nodo;
        head -> valor = valor;
        tail = head;
    }else{
        Nodo* headAnterior = head;
        head -> anterior = new Nodo;
        head = head -> anterior;
        head -> valor = valor;
        head -> siguiente = headAnterior;
    }
}

bool DoublyLinkList::popFront(int& valorpop){
    if(head == nullptr){
        return false;
    }
    else if(head == tail){
        valorpop = head ->valor;
        delete head;
        head = nullptr;
        tail = head;
        return true;
    }else{
        valorpop = head -> valor;
        head = head -> siguiente;
        delete head -> anterior;
        head -> anterior = nullptr;
        return true;
    }
}

void DoublyLinkList::pushBack(int valor){
    if(tail == nullptr){
        tail = new Nodo;
        tail -> valor = valor;
        head = tail;
    }else{
        Nodo* tailAnterior = tail;
        tail -> siguiente = new Nodo;
        tail = tail -> siguiente;
        tail -> valor = valor;
        tail -> anterior = tailAnterior;
    }
}

bool DoublyLinkList::popBack(int& valorpop){
    if(tail == nullptr){
        return false;
    }
    else if(tail == head){
        valorpop = tail ->valor;
        delete tail;
        tail = nullptr;
        head = tail;
        return true;
    }else{
        valorpop = tail -> valor;
        tail = tail -> anterior;
        delete tail -> siguiente;
        tail -> siguiente = nullptr;
        return true;
    }
}


bool DoublyLinkList::insertAfter(int vAntes, int valor){
    Nodo* nAntes = find(vAntes);

    if(nAntes != nullptr && nAntes -> siguiente != nullptr){
        Nodo* nDespues = nAntes ->siguiente;
        Nodo* nIntermedio = new Nodo;
        
        nIntermedio -> valor = valor;
        nIntermedio -> anterior = nAntes;
        nIntermedio -> siguiente = nDespues;
    
        nAntes -> siguiente = nIntermedio;
        nDespues -> anterior = nIntermedio;

        return true;
    }else if(nAntes != nullptr && nAntes ->siguiente == nullptr){
        pushBack(valor);
        return true;
    }
    
    return false;

}

bool DoublyLinkList::insertBefore(int vDespues, int valor){
    Nodo* nDespues = find(vDespues);

    if(nDespues != nullptr && nDespues -> anterior != nullptr){
        Nodo* nAntes = nDespues ->anterior;
        Nodo* nIntermedio = new Nodo;
        
        nIntermedio -> valor = valor;
        nIntermedio -> siguiente = nDespues;
        nIntermedio -> anterior = nAntes;
    
        nDespues -> anterior = nIntermedio;
        nAntes -> siguiente = nIntermedio;

        return true;
    }else if(nDespues != nullptr && nDespues ->anterior == nullptr){
        pushFront(valor);
        return true;
    }
    
    return false;
}


Nodo* DoublyLinkList::find(int valor){
    Nodo* actual = head;
    while (actual != nullptr){
        if(actual -> valor == valor){
            return actual;
        }
        actual = actual -> siguiente;
    }
    return nullptr;
}

bool DoublyLinkList::erase(int valor){
    Nodo* borrar = find(valor);
    int valorborrado;

    if(borrar == nullptr){
        return false;
        
    }else if(head == borrar){
        popFront(valorborrado);
        return true;
        
    }else if(tail == borrar){
        popBack(valorborrado);
        return true;
        
    }

    Nodo* nAntes = borrar -> anterior;
    Nodo* nDespues = borrar -> siguiente;

    nAntes -> siguiente = nDespues;
    nDespues -> anterior = nAntes;

    delete borrar;
    return true;

}


int DoublyLinkList::size(){
    int tam = 0;
    Nodo* actual = head;
    
    while(actual != nullptr){
        tam++;
        actual = actual -> siguiente;
    }

    return tam;
}

void DoublyLinkList::reverse(){
    if(head == nullptr || head == tail){
        return;
    }

    Nodo* ntemp = head;
    head = tail;
    tail = ntemp;
    Nodo* actual = head;

    while(actual != nullptr){
        ntemp = actual -> anterior;
        actual -> anterior = actual -> siguiente;
        actual -> siguiente = ntemp;

        actual = actual -> siguiente;
    }

}

void DoublyLinkList::clear(){
    while(head != nullptr){
        if(tail == head){
            delete tail;
            tail = nullptr;
            head = tail;
            break;
        }
        Nodo* borrar = head;
        head = head -> siguiente;
        head -> anterior = nullptr;
        delete borrar;
    }
}

void DoublyLinkList::print(){
    Nodo* actual = head;
    while(actual != nullptr){
        std::cout << actual -> valor << " ";
        actual = actual -> siguiente;
    }
    std::cout << "\n";
}