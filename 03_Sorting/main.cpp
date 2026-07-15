#include <iostream>
#include "sorting.h"

using namespace std;

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void copyArray(int origen[], int destino[], int n){
    for(int i = 0; i < n; i++){
        destino[i] = origen[i];
    }
}

int main(){

    int original[] = {8,3,6,2,7,1,5,4};
    int n = sizeof(original) / sizeof(original[0]);

    int bubble[n];
    int selection[n];
    int insertion[n];
    int merge[n];

    copyArray(original, bubble, n);
    copyArray(original, selection, n);
    copyArray(original, insertion, n);
    copyArray(original, merge, n);

    cout << "===== ARREGLO ORIGINAL =====" << endl;
    printArray(original, n);


    cout << "\n===== BUBBLE SORT =====" << endl;
    bubbleSort(bubble, n);
    printArray(bubble, n);


    cout << "\n===== SELECTION SORT =====" << endl;
    selectionSort(selection, n);
    printArray(selection, n);


    cout << "\n===== INSERTION SORT =====" << endl;
    insertionSort(insertion, n);
    printArray(insertion, n);

    cout << "\n===== Merge SORT =====" << endl;
    mergeSort(merge, 0, n-1);
    printArray(merge, n);


    return 0;
}