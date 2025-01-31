
//isso e um teste
//isso e um teste
void busca_linar(int v[],int a,int n){
    for(int i = 0; i < n; i++){
        if(v[i] == a){
            return i; //posicao
        }
    }
    return -1; //posicao inesxistente
}