
#include <stdio.h>
#include <stdlib.h>

typedef struct no No;

typedef struct no {
    char item;
    No *prox;
}No;

typedef No* Lista;

Lista no(char x,Lista L){
    Lista n = (Lista)malloc(sizeof(struct no));
    n->item = x;
    n->prox = L;
    return n;
}

void imprimir_lista(Lista listinha){
    while (listinha != NULL)
    {
        printf("%c ", listinha->item);
        listinha = listinha->prox;
    }
    
}