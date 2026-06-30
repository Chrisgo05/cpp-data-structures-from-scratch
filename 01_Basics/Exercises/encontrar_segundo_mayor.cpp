#include <iostream>

int main()
{
    int n = 5;
    
    int arr[n];
    int mayor;
    int segundo = n;
    
    for (int i = 0; i<n; i++){
        int numero;
        std::cout << "Dame un numero: ";
        std::cin >> numero;
        
        if (i == 0){
            mayor = i;
        }
        
        if (n == segundo and i != 0){
            if (numero < arr[mayor]){
                segundo = i;
            }else if (numero > arr[mayor]){
                segundo = mayor;
                mayor = i;
            }
        }else if (n > segundo and i != 0){
            if (numero < arr[mayor] && numero > arr[segundo]){
                segundo = i;
            }else if (numero > arr[mayor]){
                segundo = mayor;
                mayor = i;
            }
        }       
        
        arr[i] = numero;
        
    }
    
    std::cout << "mayor: " << arr[mayor] << std::endl;
    if (segundo < n){
        std::cout << "segundo mayor: " << arr[segundo];
    }
    
}