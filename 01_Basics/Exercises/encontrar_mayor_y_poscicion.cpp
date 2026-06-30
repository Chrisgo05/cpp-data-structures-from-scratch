#include <iostream>

int main()
{
    int n = 10;
    
    int arr[n];
    int mayor;
    int pos;
    
    for (int i = 0; i<n; i++){
        int numero;
        std::cout << "Dame un numero: ";
        std::cin >> numero;
        if (i == 0){
            mayor = numero;
            pos = i;
        }
        arr[i] = numero;
        if (numero > mayor) {
            mayor = numero;
            pos = i;
        }
    }
    
    std::cout << mayor << endl;
    std::cout << pos;
    
}