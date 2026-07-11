void selectionSort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        int indiMin = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[indiMin]){
                indiMin = j;
            }
        }

        if(indiMin != i){
            int temp = arr[i];
            arr[i] = arr[indiMin];
            arr[indiMin] = temp;
        }
    }
}