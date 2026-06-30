#include <iostream>

void modificar(int& arrF){
   arrF =arrF + 10;
}


int main()
{
    int n = 3;
    int arr[n];
    bool encontrado = false;
    
    for (int i=0; i<n; i++){
        int num;
        std::cout << "dame un numero: ";
        std::cin >> num;
        arr[i] = num;
    }
    
    int obj;
    std::cout << "dame un numero a buscar: ";
    std::cin >> obj;
    
    for (int i = 0; i<n; i++){
        if(arr[i] == obj){
            encontrado = true;
            modificar(arr[i]);
            break;
        }
    }
    if (!encontrado){
        std::cout << "no encontrado";
    }else{
        for (int i=0; i<n; i++){
            std::cout << arr[i] << " ";
        }
    }
    

    return 0;
}