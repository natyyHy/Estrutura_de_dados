void bubbleSort(int array[], int n){
    int i, j;
    for(i = n - 1; i >= 1;i--){
        int troca = 0;
        for(j = 0; j < i;j++){
            if(array[j] > array[j + 1]){
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                troca = 1;
            }
        }
        if(troca == 0){
            break;
        }
    }

    //retirando esse comentario- isso e um teste
}