#include <stdio.h>
#include <stdlib.h>

//definir pinha
typedef char Itemp;

typedef struct pinha{
    int max;
    int topo;
    Itemp *item;
}*Pinha;


//criar pinha 

Pinha criar_pinha(int n){
    Pinha P = (Pinha)malloc(sizeof(struct pinha));

    P->max = n;
    P->topo = -1; //indica que nao ha nenhum item no topo, pinha vazia
    P->item = (Itemp*)malloc(n*sizeof(Itemp));
    return P;
};

//pinha vazia

int vazia(Pinha p){
    if(p->topo == -1) return 1;
    return 0;
}

///pinha cheia

int cheia(Pinha p){
    if(p->topo == p->max-1) return 1;
    return 0;
}

//inserir em pinha

void empilha(Itemp x, Pinha p){
    if(cheia(p)){
        puts("pilha esta cheia");
        abort(); //abotar exercuçao
    }

    p->topo++;
    p->item[p->topo] = x;
}

//remover em pinha

Itemp desempinha(Pinha p){
    if(vazia(p)) { puts("pinha esta vazia"); abort(); }
    Itemp x = p->item[p->topo];
    p->topo--;
    return x;
}

//acessar pinha

Itemp topo(Pinha p){
    if(vazia(p)) { puts("pinha esta vazia "); abort();}
    return p->item[p->topo];
}

//destruir a pinha

void destruirP(Pinha *pinha_copia){
    free((*pinha_copia)->item);
    free(*pinha_copia);
    *pinha_copia = NULL;
}



