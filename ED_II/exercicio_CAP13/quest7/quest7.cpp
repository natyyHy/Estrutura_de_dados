// Duas árvores binárias A e B são iguais se elas têm a mesma forma e os mesmos
// itens. Crie a função igual (A, B), que informa se A é igual a B.

#include "../quest1/arv.hpp"
#include <iostream>

int main(){
    Arvore arvore1 = criar_arvore(
        criar_arvore(
            criar_arvore(NULL, 4, NULL),
            2,
            criar_arvore(NULL, 5, NULL)
        ),
        1,
        criar_arvore(
            criar_arvore(NULL, 6, NULL),
            3,
            criar_arvore(NULL, 7, NULL)
        )
    );

    Arvore arvore2 = criar_arvore(
        criar_arvore(
            criar_arvore(NULL, 4, NULL),
            2,
            criar_arvore(NULL, 5, NULL)
        ),
        1,
        criar_arvore(
            criar_arvore(NULL, 6, NULL),
            3,
            criar_arvore(NULL, 7, NULL)
        )
    );

    int resposta = ehIgual(arvore1,arvore2);
    resposta == 1 ? cout << "As duas arvores sao IGUAIS!" << endl : cout << "As duas arvores NAO SAO IGUAIS!" << endl;

    return 0;
}