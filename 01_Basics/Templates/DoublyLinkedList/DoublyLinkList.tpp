#include <iostream>

template<typename T>
DoublyLinkList<T>::DoublyLinkList(){
    head = nullptr;
    tail = nullptr;
}

template<typename T>
DoublyLinkList<T>::~DoublyLinkList(){
    clear();
}

template<typename T>
void DoublyLinkList<T>::pushFront(T valor){
    if(head == nullptr){
        head = new Nodo<T>;
        head -> valor = valor;
        tail = head;
    }else{
        Nodo<T>* headAnterior = head;
        head -> anterior = new Nodo<T>;
        head = head -> anterior;
        head -> valor = valor;
        head -> siguiente = headAnterior;
    }
}

template<typename T>
bool DoublyLinkList<T>::popFront(T& valorpop){
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

template<typename T>
void DoublyLinkList<T>::pushBack(T valor){
    if(tail == nullptr){
        tail = new Nodo<T>;
        tail -> valor = valor;
        head = tail;
    }else{
        Nodo<T>* tailAnterior = tail;
        tail -> siguiente = new Nodo<T>;
        tail = tail -> siguiente;
        tail -> valor = valor;
        tail -> anterior = tailAnterior;
    }
}

template<typename T>
bool DoublyLinkList<T>::popBack(T& valorpop){
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


template<typename T>
bool DoublyLinkList<T>::insertAfter(T vAntes, T valor){
    Nodo<T>* nAntes = find(vAntes);

    if(nAntes != nullptr && nAntes -> siguiente != nullptr){
        Nodo<T>* nDespues = nAntes ->siguiente;
        Nodo<T>* nIntermedio = new Nodo<T>;
        
        nIntermedio -> valor = valor;
        nIntermedio -> anterior = nAntes;
        nIntermedio -> siguiente = nDespues;
    
        nAntes -> siguiente = nIntermedio;
        nDespues -> anterior = nIntermedio;

        return true;
    }else if(nAntes != nullptr && nAntes ->siguiente == nullptr){
        pushBack(valor);
        return true;
    }
    
    return false;

}

template<typename T>
bool DoublyLinkList<T>::insertBefore(T vDespues, T valor){
    Nodo<T>* nDespues = find(vDespues);

    if(nDespues != nullptr && nDespues -> anterior != nullptr){
        Nodo<T>* nAntes = nDespues ->anterior;
        Nodo<T>* nIntermedio = new Nodo<T>;
        
        nIntermedio -> valor = valor;
        nIntermedio -> siguiente = nDespues;
        nIntermedio -> anterior = nAntes;
    
        nDespues -> anterior = nIntermedio;
        nAntes -> siguiente = nIntermedio;

        return true;
    }else if(nDespues != nullptr && nDespues ->anterior == nullptr){
        pushFront(valor);
        return true;
    }
    
    return false;
}


template<typename T>
Nodo<T>* DoublyLinkList<T>::find(T valor){
    Nodo<T>* actual = head;
    while (actual != nullptr){
        if(actual -> valor == valor){
            return actual;
        }
        actual = actual -> siguiente;
    }
    return nullptr;
}

template<typename T>
bool DoublyLinkList<T>::erase(T valor){
    Nodo<T>* borrar = find(valor);
    T valorborrado;

    if(borrar == nullptr){
        return false;
        
    }else if(head == borrar){
        popFront(valorborrado);
        return true;
        
    }else if(tail == borrar){
        popBack(valorborrado);
        return true;
        
    }

    Nodo<T>* nAntes = borrar -> anterior;
    Nodo<T>* nDespues = borrar -> siguiente;

    nAntes -> siguiente = nDespues;
    nDespues -> anterior = nAntes;

    delete borrar;
    return true;

}


template<typename T>
int DoublyLinkList<T>::size(){
    int tam = 0;
    Nodo<T>* actual = head;
    
    while(actual != nullptr){
        tam++;
        actual = actual -> siguiente;
    }

    return tam;
}

template<typename T>
void DoublyLinkList<T>::reverse(){
    if(head == nullptr || head == tail){
        return;
    }

    Nodo<T>* ntemp = head;
    head = tail;
    tail = ntemp;
    Nodo<T>* actual = head;

    while(actual != nullptr){
        ntemp = actual -> anterior;
        actual -> anterior = actual -> siguiente;
        actual -> siguiente = ntemp;

        actual = actual -> siguiente;
    }

}

template<typename T>
void DoublyLinkList<T>::clear(){
    while(head != nullptr){
        if(tail == head){
            delete tail;
            tail = nullptr;
            head = tail;
            break;
        }
        Nodo<T>* borrar = head;
        head = head -> siguiente;
        head -> anterior = nullptr;
        delete borrar;
    }
}

template<typename T>
void DoublyLinkList<T>::print(){
    Nodo<T>* actual = head;
    while(actual != nullptr){
        std::cout << actual -> valor << " ";
        actual = actual -> siguiente;
    }
    std::cout << "\n";
}