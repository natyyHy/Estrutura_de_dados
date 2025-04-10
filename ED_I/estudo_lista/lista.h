
#include <stdio.h>
#include <stdlib.h>

//criar estrutura no

typedef struct no No;
typedef int Item;

typedef struct no {
    Item item;
    No *prox;
}*Lista;            


//criar lista

Lista no(Item x , Lista p) {
    Lista n = (Lista)malloc(sizeof(struct no));
    n->item = x;
    n->prox = p;
    return n;
}

//imprimir

void imprimir_lista(Lista listinha){
    while (listinha != NULL)
    {
        printf("%d", listinha->item);
        listinha = listinha->prox;
    }
    
}

//anexar listas

void anexa(Lista *A , Lista B){
    if(B == NULL) return;
    while (*A != NULL)
    {
        A = &(*A)->prox;
        *A = B;
    }
    
}

//destruir lista

void f(void){
    Lista I = no(4,no(2,no(1,NULL)));
    imprimir_lista(I);

}

//apagar lista dinamica

void destruir(Lista *L){
    while (*L != NULL)
    {
        Lista n = *L;
        *L = n->prox;
        free(n);
    }
    
}

int tamanho(Lista L){
    if(L == NULL) return 0;
    return 1 + tamanho(L->prox);
}


//pertinencia

int pent(int x,Lista p){
    if(p == NULL) return 0;
    if(x == p->item) return 1;
    return pent(x,p->prox);
}

int pent_noAtual(int x,Lista p){
    if(p == NULL) return 0;
    if(x == p->item) return 1;
    return 0;
}

//clonagem

/*Lista clone(Lista l){
    if(l == NULL) return;
    return no(l->item,clone(l->prox));
}
*/

void exibe_inv(Lista l){
    if(l == NULL) return;
    exibe_inv(l->prox);
    printf("%d",l->item); 
}
