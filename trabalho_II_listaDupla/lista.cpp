#include <iostream>
#include <cstring>
using namespace std;

class No {

    public:
        int mat;
        char nome[23];
        No *prox;
        No *ant;

        No(int m, char n[23]){
            mat = m;
            strcpy(nome,n);
            prox = NULL;
            ant = NULL;
        }
};

class ListaDupla {
    private:
        No* inicio;
        No* final;

        int calcularQuant(){
            int i = 0;
            No* atual = inicio;
            while(atual != NULL){
                i++;
                atual = atual->prox;
            }
            return i;
        };

    public:
        ListaDupla(){
            inicio = NULL;
            final = NULL;
        }

        ////Insercao no final da lista;
        void inserirFinal(int mat, char nome[23]){
            //criar novo dado
            No* novo = new No(mat,nome);
            //se lista for vazia
            if(inicio == NULL){
                inicio = novo;
                final = novo;
            }else{
                final->prox = novo;
                novo->ant = final;
                final = novo;
            }
        }

        //Inserção no inicio da lista;
        void inserirInicio(int mat, char nome[23]){
            No* novo = new No(mat,nome);
            //se lista for vazia
            if(inicio == NULL){
                inicio = novo;
                final = novo;
            }else{
                inicio->ant = novo;
                novo->prox = inicio;
                inicio = novo;
            }
        };

        //Remoção do elemento procurado;
        void removerItemProcurado(int mat){
            //verificar se item existe
            No* atual = inicio;

            while(atual != NULL && atual->mat != mat){
                atual = atual->prox;
            };

            //verificaçao
            if(atual == NULL){
                cout << "matricula " << mat << " nao encontrada na lista!" << endl;
                return;
            }

            //se houver valor anterior do valor encontrado
            if(atual->ant != NULL){
                //substituir o valor anterior para proximo pelo valor proximo do valor atual
                atual->ant->prox = atual->prox;
            }else{
                inicio = atual->prox;
            }

            //se houver valor proximo do valor encontrado
            if(atual->prox != NULL){
                atual->prox->ant = atual->ant;
            }else{
                final = atual->ant;
            }

            //desalocar a memoria
            delete atual;
            
            cout << "matricula " << mat << " deletada com sucesso!" << endl;
        };

        //Mostrar a lista do inicio até o final;
        void imprimirListaInicio(){
            if(inicio == NULL){
                cout << "nao ha elementos na lista" << endl;
                return;
            }

            No* atual = inicio;
            int i = 1;
            while(atual != NULL){
                cout << i << " - matricula: " << atual->mat << " | nome: " << atual->nome << endl;
                i++;
                atual = atual->prox;
            }
        }

        //Mostrar a lista do final até o inicio;

        void imprimirListaFim(){
            if(final == NULL){
                cout << "nao ha elementos na lista" << endl;
                return;
            }

            No* atual = final;
            int i = calcularQuant();
            while(atual != NULL){
                cout << i << " - matricula: " << atual->mat << " | nome: " << atual->nome << endl;
                i--;
                atual = atual->ant;
            }
        }
};