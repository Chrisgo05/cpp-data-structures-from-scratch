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

bool SinglyCircularLinkList::popFront(int& valorpop){}

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

bool SinglyCircularLinkList::popBack(int& valorpop){}


bool SinglyCircularLinkList::insertAfter(int vAntes ,int valor){}

bool SinglyCircularLinkList::insertBefore(int vDespues, int valor){}


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

Nodo* SinglyCircularLinkList::findBefore(int vDespues){}

bool SinglyCircularLinkList::erase(int valor){}

void SinglyCircularLinkList::clear(){
    if(head == nullptr){
        std::cout << "La lista ya esta vacia" << std::endl;

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

void SinglyCircularLinkList::reverse(){}
