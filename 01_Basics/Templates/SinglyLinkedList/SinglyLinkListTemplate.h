#pragma once
#include <iostream>
#include "NodoTemplate.h"

template <typename T>
class SinglyLinkListTemplate{
    private:
        Nodo<T>* head;
        Nodo<T>* tail;

        Nodo<T>* findBefore(T buscando);

    public:
        SinglyLinkListTemplate();
        ~SinglyLinkListTemplate();

        void pushFront(T valor);
        bool popFront(T& valorpop);
        void pushBack(T valor);
        bool popBack(T& valorpop);

        bool front(T& valor);
        bool back(T& valor);

        Nodo<T>* find(T valor);

        bool insertAfter(T vAntes, T valor);
        bool insertBefore(T vDespues, T valor);

        bool erase(T valor);

        void clear();
        int size();
        void print();
        void reverse();
};


template <typename T>
SinglyLinkListTemplate<T>::SinglyLinkListTemplate(){
    head = nullptr;
    tail = nullptr;
}

template <typename T>
SinglyLinkListTemplate<T>::~SinglyLinkListTemplate(){
    clear();
}

template <typename T>
Nodo<T>* SinglyLinkListTemplate<T>::findBefore(T buscando){
    Nodo<T>* actual = head;
    while(actual != nullptr && actual->siguiente != nullptr){
        if(actual->siguiente->valor == buscando){
            return actual;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}

template <typename T>
void SinglyLinkListTemplate<T>::pushFront(T valor){
    if (head == nullptr){
        head = new Nodo<T>;
        head-> valor = valor;
        tail = head;
    }else{
        Nodo<T>* nuevo = new Nodo<T>;
        nuevo -> valor = valor;
        nuevo -> siguiente = head;
        head = nuevo;
    }
}

template <typename T>
bool SinglyLinkListTemplate<T>::popFront(T& valor){
    if(head == nullptr && tail == nullptr){
        return false;
    }
    else if(head == tail){
        valor = head -> valor;
        delete head;
        head = nullptr;
        tail = head;
        return true;
    }else{
        Nodo<T>* temp = head;
        head = head -> siguiente;
        valor = temp -> valor;
        delete temp;
        return true;
    }
}

template <typename T>
void SinglyLinkListTemplate<T>::pushBack(T valor){
    if (tail == nullptr){
        tail = new Nodo<T>;
        tail -> valor = valor;
        head = tail;
    }else{
        Nodo<T>* nuevo = new Nodo<T>;
        tail -> siguiente = nuevo;
        tail = tail -> siguiente;
        tail -> valor = valor;
    }
}

template <typename T>
bool SinglyLinkListTemplate<T>::popBack(T& valor){
    if(tail == nullptr){
        return false;
    }else if(tail == head){
        valor = tail -> valor;
        delete tail;
        tail = nullptr;
        head = tail;
        return true;
    }else{
        Nodo<T>* actual = head;
        valor = tail -> valor;
        while(actual->siguiente != tail){
            actual = actual->siguiente;
        }
        actual-> siguiente = nullptr;
        delete tail;
        tail = actual;
        return true;
    }
}

template <typename T>
bool SinglyLinkListTemplate<T>::front(T& valor){
    if(head != nullptr){
        valor = head -> valor;
        return true;
    }
    return false;
}

template <typename T>
bool SinglyLinkListTemplate<T>::back(T& valor){
    if(head != nullptr){
        valor = tail -> valor;
        return true;
    }
    return false;
}

template <typename T>
Nodo<T>* SinglyLinkListTemplate<T>::find(T buscando){
    Nodo<T>* actual = head;
    while(actual != nullptr){
        if(actual -> valor == buscando){
            return actual;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}

template <typename T>
bool SinglyLinkListTemplate<T>::insertAfter(T vAntes, T valor){
    Nodo<T>* nAntes = find(vAntes);
    
    if(nAntes != nullptr && nAntes -> siguiente != nullptr){ // por si esta en el medio
        Nodo<T>* nDespues = nAntes -> siguiente;
        Nodo<T>* nIntermedio = new Nodo<T>;
        
        nIntermedio -> valor = valor;
        nIntermedio -> siguiente = nDespues;
        nAntes -> siguiente = nIntermedio;
        
        return true;
        
    }else if(nAntes != nullptr && nAntes -> siguiente == nullptr){ //por si es despues del ultimo nodo valido 
        pushBack(valor);
        return true;
        
    }else if(nAntes == nullptr){
        return false;
        
    }
    return false;
}

template <typename T>
bool SinglyLinkListTemplate<T>::insertBefore(T vDespues, T valor){
    Nodo<T>* nAntes = findBefore(vDespues);

    if(head != nullptr && head->valor == vDespues){ //por si el valor es la cabeza actual
        pushFront(valor);
        return true;
        
    }else if(head != nullptr && nAntes != nullptr){ //si esta en medio
        Nodo<T>* nDespues = nAntes->siguiente;
        Nodo<T>* nIntermedio = new Nodo<T>;

        nIntermedio -> valor = valor;
        nAntes -> siguiente = nIntermedio;
        nIntermedio -> siguiente = nDespues;

        return true;

    }else{
        return false;

    }
    return false;
}


template <typename T>
bool SinglyLinkListTemplate<T>::erase(T valor){
    T valorEliminado;
    Nodo<T>* nAntes = findBefore(valor);

    if(head != nullptr && head -> valor == valor){
        popFront(valorEliminado);
        return true;

    }else if(tail != nullptr && tail -> valor == valor){
        popBack(valorEliminado);
        return true;

    }else if(nAntes != nullptr && head != nullptr){
        Nodo<T>* nBorrar = nAntes -> siguiente;

        nAntes -> siguiente = nBorrar -> siguiente;
        delete nBorrar;

        return true;

    }else{
        return false;

    }
}

template <typename T>
void SinglyLinkListTemplate<T>::clear(){
    while(head != nullptr && tail != nullptr){
        if(head == tail){
            delete head;
            head = nullptr;
            tail = head;
            break;
        }

        Nodo<T>* temp = head;
        head = head -> siguiente;

        delete temp;
    }
}

template <typename T>
int SinglyLinkListTemplate<T>::size(){
    Nodo<T>* actual = head;
    int tam = 0;

    if(head == nullptr){
        return tam;
    }
    
    while(actual != tail){
        tam++;
        actual = actual -> siguiente;
    }
    tam++;
    return tam;
}

template <typename T>
void SinglyLinkListTemplate<T>::print(){
    Nodo<T>* actual = head;
    while(actual != nullptr){
        std::cout << actual->valor << " ";
        actual = actual->siguiente;
    }
    std::cout << "\n";
}

template <typename T>
void SinglyLinkListTemplate<T>::reverse(){
    if(head == tail || head == nullptr){
        return;
    }
    Nodo<T>* temph = head; //guarda direccion del primer elemento

    Nodo<T>* inverlista = head;  //empieza la lista invertida
    Nodo<T>* temp; // prepara la temporal

    head = head-> siguiente; //avanza uno en la lista normal
    inverlista -> siguiente = nullptr; // desvincula la lista invertida de la normal

    while(head != tail){ 
        temp = head -> siguiente; //guarda el siguiente nodo del nodo actual
        head -> siguiente = inverlista; //conceta el nodo actual a la lista invertida
        inverlista = head; // mueve la variable de inicio de la lista invertida
        head = temp; //cambia al nodo guardado anteriormente
        
    }

    tail ->siguiente = inverlista; //conecta la antigua cola con la lista invertida
    head = tail; //cambia la variable que identifica la cabeza (ya no es la variable tail ahora es la de head)
    tail = temph; //asigna el final de la lista a la variable que es(o sea la tail)
}