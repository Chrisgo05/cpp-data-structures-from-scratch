void merge(int arr[], int inicio, int medio, int fin){
    int aux[fin - inicio + 1];
    int f_arr_i = inicio;
    int s_arr_i = medio + 1;
    int aux_i = 0;

    while(f_arr_i <= medio && s_arr_i <= fin){
        if(arr[f_arr_i] <= arr[s_arr_i]){
            aux[aux_i] = arr[f_arr_i];
            f_arr_i++;

        }else if(arr[f_arr_i] >= arr[s_arr_i]){
            aux[aux_i] = arr[s_arr_i];
            s_arr_i++;

        }
        aux_i++;
    }

    if(f_arr_i <= medio){
        for(f_arr_i; f_arr_i <= medio; f_arr_i++){
            aux[aux_i] = arr[f_arr_i];
            aux_i++;
        }
    }else if(s_arr_i <= fin){
        for(s_arr_i; s_arr_i <= fin; s_arr_i++){
            aux[aux_i] = arr[s_arr_i];
            aux_i++;
        }
    }

    for(int i = 0; i < aux_i; i++){
        arr[inicio + i] = aux[i];
    }
}

void mergeSort(int arr[], int inicio, int fin){
    if(inicio < fin){
        int medio = ((fin - inicio) / 2) + inicio; 
        mergeSort(arr, inicio, medio);
        mergeSort(arr, medio + 1, fin);
        merge(arr, inicio, medio, fin);
    }
}