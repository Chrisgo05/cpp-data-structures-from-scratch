#pragma once
#include "Nodo.h"

class SinglyCircularLinkList{
    private:
        Nodo* head;
        Nodo* tail;
    
    public:
        SinglyCircularLinkList();
        ~SinglyCircularLinkList();

        void pushFront(int valor);
        bool popFront(int& valorpop);
        void pushBack(int valor);
        bool popBack(int& valorpop);

        bool insertAfter(int vAntes ,int valor);
        bool insertBefore(int vDespues, int valor);
        
        Nodo* find(int buscando);
        Nodo* findBefore(int vDespues);
        
        bool erase(int valor);
        void clear();
        int size();
        void print();
        void reverse();
};