#include <iostream>

int main()
{
    int n = 5;
    
    int arr[n];
    int objetivo;
    int indice;
    bool encontrado = false;
    
    
    for (int i = 0; i<n; i++){
        int numero;
        std::cout << "Dame un numero: ";
        std::cin >> numero;
        arr[i] = numero;
    }
    
    std::cout << "dame el numero objetivo a encontrar: ";
    std::cin >> objetivo;
    
    for (int i = 0; i<n; i++){
        if(arr[i] == objetivo){
            indice = i;
            encontrado = true;
            break;
        }
    }
    
    if (encontrado){
        std::cout << indice;
    }else{
        std::cout << "No encontrado";
    }
    
}