#pragma once
#include "NodoTemplate.h"

template<typename T>
class DoublyLinkList{
    private:
        Nodo<T>* head;
        Nodo<T>* tail;

    public:
        DoublyLinkList();
        ~DoublyLinkList();

        void pushFront(T valor);
        bool popFront(T& valorpop);
        void pushBack(T valor);
        bool popBack(T& valorpop);

        bool insertAfter(T vAntes, T valor);
        bool insertBefore(T vDespues, T valor);

        Nodo<T>* find(T valor);
        bool erase(T valor);

        int size();
        void reverse();
        void clear();
        void print();
};

#include "DoublyLinkList.tpp"