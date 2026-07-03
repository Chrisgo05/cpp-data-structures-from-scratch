#include <iostream>
#include "DoublyLinkList.h"

DoublyLinkList::DoublyLinkList(){
    head = nullptr;
    tail = nullptr;
}

DoublyLinkList::DoublyLinkList(){
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

}

bool DoublyLinkList::insertBefore(int vDespues, int valor){

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

}


int DoublyLinkList::size(){

}

void DoublyLinkList::reverse(){

}

void DoublyLinkList::clear(){
    while(tail != nullptr && head != nullptr){
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