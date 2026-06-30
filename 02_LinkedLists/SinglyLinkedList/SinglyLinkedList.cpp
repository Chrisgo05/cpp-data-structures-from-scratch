#include <iostream>

struct Nodo {
    int valor;
    Nodo* siguiente = nullptr;
};

void printLinLin(Nodo* hlista){
    Nodo* actual = lista;
    while(actual != nullptr){
        std::cout << actual->valor << " ";
        actual = actual->siguiente;
    }
}

void pushFront(Nodo*& hlista, Nodo*& tlista, int valor){
    if (hlista == nullptr){
        hlista = new Nodo;
        hlista-> valor = valor;
        tlista = hlista;
    }else{
        Nodo* nuevo = new Nodo;
        nuevo -> valor = valor;
        nuevo -> siguiente = hlista;
        hlista = nuevo;
    }
}

bool popFront(Nodo*& hlista, Nodo*& tlista, int& valorpop){
    if(hlista == nullptr && tlista == nullptr){
        return false;
    }
    else if(hlista == tlista){
        valorpop = hlista -> valor;
        delete hlista;
        hlista = nullptr;
        tlista = hlista;
        return true;
    }else{
        Nodo* temp = hlista;
        hlista = hlista -> siguiente;
        valorpop = temp -> valor;
        delete temp;
        return true;
    }
}

void pushBack(Nodo*& hlista, Nodo*& tlista, int valor){
    if (tlista == nullptr){
        tlista = new Nodo;
        tlista -> valor = valor;
        hlista = tlista;
    }else{
        Nodo* nuevo = new Nodo;
        tlista -> siguiente = nuevo;
        tlista = tlista -> siguiente;
        tlista -> valor = valor;
    }
}

bool popBack(Nodo*& hlista, Nodo*& tlista, int& valorpop){
    if(tlista == nullptr){
        return false;
    }else if(tlista == hlista){
        valorpop = tlista -> valor;
        delete tlista;
        tlista = nullptr;
        hlista = tlista;
        return true;
    }else{
        Nodo* actual = hlista;
        valorpop = tlista -> valor;
        while(actual->siguiente != tlista){
            actual = actual->siguiente;
        }
        actual-> siguiente = nullptr;
        delete tlista;
        tlista = actual;
        return true;
    }
}

Nodo* find(Nodo* hlista, int buscando){
    Nodo* actual = hlista;
    while(actual != nullptr){
        if(actual -> valor == buscando){
            return actual;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}

bool insertAfter(Nodo*& hlista, Nodo*& tlista, int vAntes, int valor){
    Nodo* nAntes = find(hlista, vAntes);
    
    if(nAntes != nullptr && nAntes -> siguiente != nullptr){ // por si esta en el medio
        Nodo* nDespues = nAntes -> siguiente;
        Nodo* nIntermedio = new Nodo;
        
        nIntermedio -> valor = valor;
        nIntermedio -> siguiente = nDespues;
        nAntes -> siguiente = nIntermedio;
        
        return true;
        
    }else if(nAntes != nullptr && nAntes -> siguiente == nullptr){ //por si es despues del ultimo nodo valido 
        pushBack(hlista, tlista, valor);
        return true;
        
    }else if(nAntes == nullptr){
        return false;
        
    }
}