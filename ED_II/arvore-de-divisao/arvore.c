#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arvore {
    char comparacao[20];
    char folha[20];  // Pode ser usado para outras infos, mas aqui não usado.
    char ramo;
    struct arvore* sim;
    struct arvore* nao;
} No;

No* criarArvoreDecisao(char comparacao[20], char folha[20], char ramo) {
    No* novoNo = (No*)malloc(sizeof(No));
    strcpy(novoNo->comparacao, comparacao);
    strcpy(novoNo->folha, folha);
    novoNo->ramo = ramo;
    novoNo->sim = NULL;
    novoNo->nao = NULL;
    return novoNo;
}

void trocar(int *valor1, int *valor2) {
    int temp = *valor1;
    *valor1 = *valor2;
    *valor2 = temp;
}

void bubbleSort(int array[], int tamanho, No** arvoreDecisao) {
    No* atual = NULL;

    for (int step = 0; step < tamanho - 1; ++step) {
        for (int i = 0; i < tamanho - step - 1; ++i) {
            char ramo = 'N';
            char comparacao[20];

            if (array[i] > array[i + 1]) {
                ramo = 'Y';
                trocar(&array[i], &array[i + 1]);
            }

            sprintf(comparacao, "[ %d > %d ]", array[i], array[i + 1]);

            No* novoNo = criarArvoreDecisao(comparacao, "", ramo);

            if (*arvoreDecisao == NULL) {
                *arvoreDecisao = novoNo;
                atual = novoNo;
            } else {
                if (ramo == 'Y') {
                    atual->sim = novoNo;
                } else {
                    atual->nao = novoNo;
                }
                atual = novoNo;
            }
        }
    }
}

void percorrerArvoreDecisao(No* arvore) {
    if (arvore == NULL) return;

    printf("Comparacao: %s | Ramo: %c\n", arvore->comparacao, arvore->ramo);

    percorrerArvoreDecisao(arvore->sim);
    percorrerArvoreDecisao(arvore->nao);
}

void liberarArvore(No* arvore) {
    if (arvore == NULL) return;
    liberarArvore(arvore->sim);
    liberarArvore(arvore->nao);
    free(arvore);
}

int main() {
    No* arvoreDecisao = NULL;

    int vetor[] = {4, 2, 1, 3};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    bubbleSort(vetor, tamanho, &arvoreDecisao);

    printf("Arvore de Decisao:\n");
    percorrerArvoreDecisao(arvoreDecisao);

    liberarArvore(arvoreDecisao);

    return 0;
}
