int main()
{
    int arr[10];
    
    for (int i = 0; i<10; i++){
        int numero;
        std::cout << "Dame un numero: ";
        std::cin >> numero;
        arr[i] = numero;
    }
    
    for (int i = 0; i<10; i++){
        std::cout << arr[i] << " ";
    }
}