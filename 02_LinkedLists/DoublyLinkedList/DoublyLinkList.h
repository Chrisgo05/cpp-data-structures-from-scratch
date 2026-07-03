#pragma once
#include "Nodo.h"

class DoublyLinkList{
    private:
        Nodo* head;
        Nodo* tail;

    public:
        DoublyLinkList();
        ~DoublyLinkList();

        void pushFront(int valor);
        bool popFront(int& valorpop);
        void pushBack(int valor);
        bool popBack(int& valorpop);

        bool insertAfter(int vAntes, int valor);
        bool insertBefore(int vDespues, int valor);

        Nodo* find(int valor);
        bool erase(int valor);

        int size();
        void reverse();
        void clear();
        void print();
};