#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da AVL
typedef struct No {
    int valor;
    int altura;
    struct No* esq;
    struct No* dir;
} No;

int altura(No* no) {
    if (no == NULL)
        return 0;
    return no->altura;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Cria novo nó
No* novoNo(int valor) {
    No* no = (No*)malloc(sizeof(No));
    no->valor = valor;
    no->esq = no->dir = NULL;
    no->altura = 1;
    return no;
}

// Rotacao a direita
No* rotacaoDireita(No* y) {
    No* x = y->esq;
    No* T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    y->altura = max(altura(y->esq), altura(y->dir)) + 1;
    x->altura = max(altura(x->esq), altura(x->dir)) + 1;

    return x;
}

// Rotacao a esquerda
No* rotacaoEsquerda(No* x) {
    No* y = x->dir;
    No* T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    x->altura = max(altura(x->esq), altura(x->dir)) + 1;
    y->altura = max(altura(y->esq), altura(y->dir)) + 1;

    return y;
}

// Fator de balanceamento
int fatorBalanceamento(No* no) {
    if (no == NULL)
        return 0;
    return altura(no->esq) - altura(no->dir);
}

// Insercao com balanceamento
No* inserir(No* no, int valor) {
    if (no == NULL)
        return novoNo(valor);

    if (valor < no->valor)
        no->esq = inserir(no->esq, valor);
    else if (valor > no->valor)
        no->dir = inserir(no->dir, valor);
    else
        return no;

    no->altura = 1 + max(altura(no->esq), altura(no->dir));

    int fb = fatorBalanceamento(no);

    // Rotacao simples a direita
    if (fb > 1 && valor < no->esq->valor)
        return rotacaoDireita(no);

    // Rotacao simples a esquerda
    if (fb < -1 && valor > no->dir->valor)
        return rotacaoEsquerda(no);

    return no;
}

// Impressao in-ordem
void imprimirInOrdem(No* raiz) {
    if (raiz != NULL) {
        imprimirInOrdem(raiz->esq);
        printf("%d ", raiz->valor);
        imprimirInOrdem(raiz->dir);
    }
}

// Funcao principal para teste
int main() {
    No* raiz = NULL;

    printf("=== Rotacao simples a direita ===\n");
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 10); // Gera rotacao a direita
    printf("In-ordem: ");
    imprimirInOrdem(raiz);
    printf("\n\n");

    printf("=== Rotacao simples a esquerda ===\n");
    raiz = NULL;
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 30); // Gera rotacao a esquerda
    printf("In-ordem: ");
    imprimirInOrdem(raiz);
    printf("\n");

    return 0;
}

/*

---------------------------------------------------------------------

CASO QUANDO É ROTAÇAO SIMPLES PARA DIREITA:

ARVORE QUANDO INSERIMOS 30,20 e 10

Quando inserimos 30,20:           Quando inserimos 10:
            30                              30
           /                               /
          20                             20
                                        /
                                       10 DESBALANCEADA!

---------------------------------------------------------------------

CASO QUANDO É ROTAÇAO SIMPLES PARA ESQUERDA:

ARVORE QUANDO INSERIMOS 10,20 e 30

        Quando inserimos 10,20:           Quando inserimos 30:
            10                              10
              \                               \
              20                               20
                                                 \
                                                  30 DESBALANCEADA!

*/