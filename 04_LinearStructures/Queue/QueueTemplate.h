#pragma once
#include "../../01_Basics/Templates/SinglyLinkedList/SinglyLinkListTemplate.h"

template<typename T>
class QueueTemplate{
    private:
        SinglyLinkListTemplate<T> lista;
    
    public:
        QueueTemplate();

        void enqueue(T valor);
        bool dequeue(T& valor);

        bool front(T& valor);
        bool bakc(T& valor);

        int size();
        bool empty();
};

#include "QueueTemplate.tpp"