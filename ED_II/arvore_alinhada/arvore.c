#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct arv {
    struct arv *esquerda;
    Item item;
    Item sucessor;
    struct arv *direita;
} *Arvore;

Arvore criar_arvore(Arvore esquerda, Item valor, Item sucessor, Arvore direita) {
    Arvore no = (Arvore)malloc(sizeof(struct arv));
    no->esquerda = esquerda;
    no->item = valor;
    no->sucessor = sucessor;
    no->direita = direita;
    return no;
}

void inserirArvore(Arvore *arv, Item item) {
    Arvore novo_no = criar_arvore(NULL, item, 0, NULL);
    Arvore prev = NULL;
    Arvore p = *arv;

    if (*arv == NULL) {
        *arv = novo_no;
        return;
    }

    while (p != NULL) {
        prev = p;
        if (item < p->item) {
            p = p->esquerda;
        } else if (p->sucessor == 0) {
            p = p->direita;
        } else {
            break;
        }
    }

    if (item < prev->item) {
        prev->esquerda = novo_no;
        novo_no->sucessor = 1;
        novo_no->direita = prev;
    } else if (prev->sucessor == 1) {
        novo_no->sucessor = 1;
        prev->sucessor = 0;
        novo_no->direita = prev->direita;
        prev->direita = novo_no;
    } else {
        prev->direita = novo_no;
    }
}

void em_ordem(Arvore arv) {
    Arvore prev = NULL;
    Arvore p = arv;

    if (p != NULL) {
        while (p->esquerda != NULL) {
            p = p->esquerda;
        }
        while (p != NULL) {
            printf("%d ", p->item);
            prev = p;
            p = p->direita;
            if (p != NULL && prev->sucessor == 0) {
                while (p->esquerda != NULL) {
                    p = p->esquerda;
                }
            }
        }
    }
}

int main() {
    Arvore arv = NULL;
    inserirArvore(&arv, 15);
    inserirArvore(&arv, 4);
    inserirArvore(&arv, 20);
    inserirArvore(&arv, 17);
    inserirArvore(&arv, 19);

    printf("Em ordem: ");
    em_ordem(arv);
    printf("\n");

    return 0;
}
