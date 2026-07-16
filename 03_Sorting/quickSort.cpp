#include "sorting.h"

int partition(int arr[], int inicio, int fin){
    int pivote = arr[fin];
    int lector = inicio;
    int menores = inicio;
    int temp;

    for(; lector < fin; lector++){
        if(arr[lector] < pivote){
            if(lector != menores){
                temp = arr[menores];
                arr[menores] = arr[lector];
                arr[lector] = temp;
            }

            menores++;
        }
    }

    temp = pivote;
    arr[fin] = arr[menores];
    arr[menores] = temp;

    return menores;
}

void quickSort(int arr[], int inicio, int fin){
    if(inicio < fin){
        int pivote = partition(arr, inicio, fin);

        quickSort(arr, inicio, pivote - 1);
        quickSort(arr, pivote + 1, fin);

    }
}