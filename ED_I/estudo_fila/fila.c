//FILA É FIFO (first - in / first - out)
#include <stdio.h>
#include <stdlib.h>

typedef char itemf;
typedef struct fila {
    int max;
    int total;
    int inicio;
    int final;
    itemf *item;
} *Fila;

Fila criar_fila(int m) {
    Fila f = malloc(sizeof(struct fila));
    f->max = m;
    f->inicio = 0;
    f->final = 0;
    f->total = 0;
    f->item = malloc(m * sizeof(itemf));
    return f;
}


int eh_vazia(Fila f){
    return (f->total == 0);
}

int eh_cheia(Fila f){
    return (f->total == f->max);
}

void avanca_final(Fila f) {
    f->final = (f->final + 1) % f->max; // Incrementa circularmente.
}

void avanca_inicio(Fila f) {
    f->inicio = (f->inicio + 1) % f->max; // Incrementa circularmente.
}


void enfileira(int valor,Fila f){
    if(eh_cheia(f)) {puts("fila cheia"); abort();};

    f->item[f->final] = valor;
    avanca_final(f); //avanca final
    f->total++;
}

itemf desenfileira(Fila f){
    if(eh_vazia(f)) { puts("fila vazia"); abort();};
    itemf x = f->item[f->inicio];
    avanca_inicio(f);
    f->total--;
    return x;
}

void destruir_fila(Fila *f){ /// lembrar de *f faz referencia a um endereço, logo destruir_fila(&f);
    free((*f) -> item);
    free(*f);
    *f = NULL;
}