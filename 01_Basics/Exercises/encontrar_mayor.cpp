#include <iostream>

int main()
{
    int n = 2;
    
    int arr[n];
    int mayor;
    
    for (int i = 0; i<n; i++){
        int numero;
        std::cout << "Dame un numero: ";
        std::cin >> numero;
        if (i == 0){mayor = numero;}
        arr[i] = numero;
        if (numero > mayor) {mayor = numero;}
    }
    
    std::cout << mayor;
    
}