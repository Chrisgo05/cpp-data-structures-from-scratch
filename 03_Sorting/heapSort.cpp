#include "sorting.h"

void swap(int& valor1, int& valor2){
    int temp = valor1;
    valor1 = valor2;
    valor2 = temp;

}

void heapify(int arr[], int raiz, int n){
    int mayor = raiz;

    int izquierdo = 2 * raiz + 1;
    int derecho = 2 * raiz + 2;

    if(izquierdo < n && arr[izquierdo] > arr[mayor]){
        mayor = izquierdo;
    }

    if(derecho < n && arr[derecho] > arr[mayor]){
        mayor = derecho;
    }

    if(raiz != mayor){
        swap(arr[raiz], arr[mayor]);
        heapify(arr, mayor, n);
    }


}

void buildHeap(int arr[], int n){
    for(int i = n / 2 - 1; i >= 0; i--){
        heapify(arr, i, n);
    }
}

void heapSort(int arr[], int n){
    buildHeap(arr, n);

    for(int i = n-1; i > 0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, 0, i);
    }
}