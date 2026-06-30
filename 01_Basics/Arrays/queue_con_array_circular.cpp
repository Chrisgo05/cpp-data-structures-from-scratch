la implementacion de todo excepto ese ultom for esta igual perome da que me salgo de la memoria del array pero no entindo porque y me da esto
#include <iostream>

bool enqueue(int pila[], int cabeza, int& cola, int valor, int tam){
    if((cola + 1) % tam != cabeza){
        pila[cola] = valor;
        cola = (cola + 1) % tam;
        return true;
    }else{
        return false;
    }
}

bool dequeue(int pila[], int& cabeza, int cola, int& valorsacado, int tam){
    if(cabeza != cola){
        valorsacado = pila[cabeza];
        cabeza = (cabeza + 1) % tam;
        return true;
    }else{
        return false;
    }
}

int main(){
    int n = 6;
    int arraypila[n];
    
    int cabeza = 0;
    int cola = 0;
    int valordequeado;
    
    enqueue(arraypila, cabeza, cola, 10, n);
    enqueue(arraypila, cabeza, cola, 20, n);
    enqueue(arraypila, cabeza, cola, 30, n);
    
    dequeue(arraypila, cabeza, cola, valordequeado, n);
    std::cout << valordequeado << std::endl;
    
    enqueue(arraypila, cabeza, cola, 30, n);
    enqueue(arraypila, cabeza, cola, 20, n);
    enqueue(arraypila, cabeza, cola, 10, n);
    
    dequeue(arraypila, cabeza, cola, valordequeado, n);
    std::cout << valordequeado << std::endl;
    dequeue(arraypila, cabeza, cola, valordequeado, n);
    std::cout << valordequeado << std::endl;

    
    enqueue(arraypila, cabeza, cola, 40, n);
    enqueue(arraypila, cabeza, cola, 50, n);

    std::cout << cabeza << std::endl;
    for (int i = cabeza; i != cola; i = (i + 1) % n){ 
        std::cout << arraypila[i] << " "; 
    }
    
    return 1;
}