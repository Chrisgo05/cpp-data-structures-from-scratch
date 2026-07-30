#pragma once
#include "../../01_Basics/Templates/SinglyLinkedList/SinglyLinkListTemplate.h"

template<typename T>
class StackTemplate{
    private:
        SinglyLinkListTemplate<T> lista;

    public:
        StackTemplate();

        void push(T valor);
        bool pop(T& valor);

        bool top(T& valor);

        int size();
        bool empty();

};

#include "StackTemplate.tpp"