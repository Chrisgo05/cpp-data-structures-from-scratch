#pragma once
#include "Nodo.h"

class SinglyLinkList{
    private:
        Nodo* head;
        Nodo* tail;

        Nodo* findBefore(int buscando);

    public:
        SinglyLinkList();
        ~SinglyLinkList();

        void pushFront(int valor);
        bool popFront(int& valorpop);
        void pushBack(int valor);
        bool popBack(int& valorpop);

        Nodo* find(int valor);

        bool insertAfter(int vAntes, int valor);
        bool insertBefore(int vDespues, int valor);

        bool erase(int valor);

        void clear();
        int size();
        void print();
        void reverse();
};