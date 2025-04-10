#include <stdio.h>
#include <stdlib.h>

//criar estrutura pro No

typedef struct meuNo No;
struct meuNo {
    int numero;
    No *prox;
};

// criar novo no, a funcao vai retornar um ponteiro, por isso definir No* criar_no
No* criar_no(){
    //*novo é um ponteiro
    No *novo = (No*)malloc(sizeof(No)); //malloc recebe uma quantidade de bytes e retorna um ponteiro do tipo void,nos queremos receber um ponteiro do tipo No , ent convertemos (No*) + malloc(sizeof(No))

    //retornar novo no
    return novo;
}

No* inserir_inicio(int dado,No* lista){
    No* novo_no = criar_no();
    novo_no->numero = dado;

 
    //se lista estiver vazia
    if(lista == NULL){
        //lista aponta pro novo no
        lista = novo_no;
        novo_no->prox = NULL;
    }else{
        novo_no->prox = lista;
        lista = novo_no;
    }

    return lista;
}

void imprimir_lista(No* lista){

    //para nao inteferir nas posiçoes da lista, criar uma copia
    No *aux = lista;
    while (aux != NULL)
    {
        printf("%d",aux->numero);
        aux = aux->prox;
    }
    

}


int main(){

    //a lista deve apontar pra um elemento do tipo no, ent o ponteiro deve ser do mesmo tipo
    No *lista = NULL;
    lista = inserir_inicio(1,lista); //3
    lista = inserir_inicio(3,lista); //2
    lista = inserir_inicio(4,lista); // 1
    imprimir_lista(lista);

}