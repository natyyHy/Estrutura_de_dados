void buscarLinear(int vetor[],int a,int n){
    for(int i = 0; i < n ; i++){
        if(vetor[i] == a){
            return i;
        }
    }
    return -1;
}