#include <iostream>

bool push(int pila[], int& top, int valor, int tam){
    if(top < tam - 1){
        top++;
        pila[top] = valor;
        return true;
    }else{
        return false;
    }
}

bool pop(int pila[], int& top, int& valorsacado){
    if(top >= 0){
        valorsacado = pila[top];
        top--;
        return true;
    }else{
        return false;
    }

}

bool peek(int pila[], int top, int& peekeado){
    if(top >= 0){
        peekeado = pila[top];
        return true;
    }else{
        return false;
    }
}

int main()
{
    int n = 5;
    int pila[n];
    int top = -1;
    int resp = 0;
    int valorpop;
    int valorpeek;
    
    while(resp == 0){
        int num;
        int accion;
        std::cout << "que quiers hacer?(1 push, 2 pop, 3 peek): ";
        std::cin >> accion;
        
        if(accion == 1){//push
            std::cout << "agrega un numero a la pila: ";
            std::cin >> num;
            if (push(pila, top, num, n)){
                std::cout << "valor agregado" << std::endl;
            }else{
                std::cout << "pila llena"  << std::endl;
            }    
        }else if(accion == 2){//pop
            if (pop(pila, top, valorpop)){
                std::cout << "valor eliminado" << std::endl;
                std::cout << "valorpop actual: " << valorpop << std::endl;
            }else{
                std::cout << "pila vacia"  << std::endl;
            }
        }else if(accion == 3){//peek
            if(peek(pila, top, valorpeek)){
                std::cout << "valor hasta arriba de la pila actulamente: " << valorpeek << std::endl;
            }else{
                std::cout << "pila vacia" << std::endl;
            }
        }
        
        
        std::cout << "hacer otra cosa? ";
        std::cin >> resp;
    }
    
    std::cout << "arriba" << std::endl;
    for (int i = top; i >= 0; i--){
        std::cout << pila[i] << std::endl;
    }
    std::cout << "abajo" << std::endl;
    
    std::cout << "top: " << top << std::endl;
    std::cout << "ultimo valorpop: " << valorpop;
}