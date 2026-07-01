#include <iostream>

struct Nodo {
    int valor;
    Nodo* siguiente = nullptr;
};

void printLinLin(Nodo* hlista){
    Nodo* actual = hlista;
    while(actual != nullptr){
        std::cout << actual->valor << " ";
        actual = actual->siguiente;
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

Nodo* findBefore(Nodo* hlista, int buscando){
    Nodo* actual = hlista;
    while(actual != nullptr && actual->siguiente != nullptr){
        if(actual->siguiente->valor == buscando){
            return actual;
        }
        actual = actual->siguiente;
    }
    return nullptr;
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

bool insertBefore(Nodo*& hlista, Nodo*& tlista, int vDespues, int valor){
    Nodo* nAntes = findBefore(hlista, vDespues);

    if(hlista != nullptr && hlista->valor == vDespues){ //por si el valor es la cabeza actual
        pushFront(hlista, tlista, valor);
        return true;
        
    }else if(hlista != nullptr && nAntes != nullptr){ //si esta en medio
        Nodo* nDespues = nAntes->siguiente;
        Nodo* nIntermedio = new Nodo;

        nIntermedio -> valor = valor;
        nAntes -> siguiente = nIntermedio;
        nIntermedio -> siguiente = nDespues;

        return true;

    }else{
        return false;

    }
}

bool erase(Nodo*& hlista, Nodo*& tlista, int valor){
    int valorEliminado;
    Nodo* nAntes = findBefore(hlista, valor);

    if(hlista != nullptr && hlista -> valor == valor){
        popFront(hlista, tlista, valorEliminado);
        return true;

    }else if(tlista != nullptr && tlista -> valor == valor){
        popBack(hlista, tlista, valorEliminado);
        return true;

    }else if(nAntes != nullptr && hlista != nullptr){
        Nodo* nBorrar = nAntes -> siguiente;

        nAntes -> siguiente = nBorrar -> siguiente;
        delete nBorrar;

        return true;

    }else{
        return false;

    }
}

void clear(Nodo*& hlista, Nodo*& tlista){
    while(hlista != nullptr && tlista != nullptr){
        if(hlista == tlista){
            delete hlista;
            hlista = nullptr;
            tlista = hlista;
            break;
        }

        Nodo* temp = hlista;
        hlista = hlista -> siguiente;

        delete temp;
    }

}

int size(Nodo* hlista, Nodo* tlista){
    Nodo* actual = hlista;
    int tam = 0;

    if(hlista == nullptr){
        return tam;
    }
    
    while(actual != tlista){
        tam++;
        actual = actual -> siguiente;
    }
    tam++;
    return tam;
}

void delReves(Nodo*& hlista, Nodo*& tlista){
    if(hlista == tlista || hlista == nullptr){
        return;
    }
    Nodo* temph = hlista; //guarda direccion del primer elemento

    Nodo* inverlista = hlista;  //empieza la lista invertida
    Nodo* temp; // prepara la temporal

    hlista = hlista-> siguiente; //avanza uno en la lista normal
    inverlista -> siguiente = nullptr; // desvincula la lista invertida de la normal

    while(hlista != tlista){ 
        temp = hlista -> siguiente; //guarda el siguiente nodo del nodo actual
        hlista -> siguiente = inverlista; //conceta el nodo actual a la lista invertida
        inverlista = hlista; // mueve la variable de inicio de la lista invertida
        hlista = temp; //cambia al nodo guardado anteriormente
        
    }

    tlista ->siguiente = inverlista; //conecta la antigua cola con la lista invertida
    hlista = tlista; //cambia la variable que identifica la cabeza (ya no es la variable tlista ahora es la de hlista)
    tlista = temph; //asigna el final de la lista a la variable que es(o sea la tlista)

}