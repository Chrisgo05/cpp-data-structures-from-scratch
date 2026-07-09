#pragma once
#include "Nodo.h"

class DoublyCircularLinkList{
    private:
        Nodo* head;
        Nodo* tail;

        void swapLinks(Nodo*& nodo1, Nodo*& nodo2);

    public:
        DoublyCircularLinkList();
        ~DoublyCircularLinkList();

        void pushFront(int valor);
        bool popFront(int& valorpop);
        void pushBack(int valor);
        bool popBack(int& valorpop);

        bool insertAfter(int vAntes, int valor);
        bool insertBefore(int vDespues, int valor);

        Nodo* find(int valor);
        bool erase(int valor);

        int size();
        void clear();
        void print();
        void reverse();
        void reverseCircular();

    };