#include "./lista.cpp"
#include "./menu.cpp"
using namespace std;

int main() {
    int opcao = -1;
    ListaDupla listaDupla;
    while (opcao != 0){
        menu();
        cout << "\n\topcao:" << endl;
        cin >> opcao;

        int mat;
        char nome[23];
        switch (opcao)
        {
        case 1:

            cout << "\n\tmatricula: " << endl;
            cin >> mat;
            cin.ignore(); // limpa o buffer de entrada
            cout << "\n\tnome: " << endl;
            cin.getline(nome, 23); //espera um array de caracteres (char[]) e seu tamanho máximo
            listaDupla.inserirInicio(mat,nome);
            cout << "\n\tinserido..." << endl;
            break;
        
        case 2:
            cout << "\n\tmatricula: " << endl;
            cin >> mat;
            cin.ignore();
            cout << "\n\tnome: " << endl;
            cin.getline(nome, 23); 
            listaDupla.inserirFinal(mat,nome);
            cout << "\n\tinserido..." << endl;
            break;

        case 3:
            cout << "\n\tmatricula: " << endl;
            cin >> mat;
            listaDupla.removerItemProcurado(mat);
            cout << "\n\tapagado com sucesso..." << endl;
            break;

        case 4:
            cout << "\n\t>>> mostrar inicio ate fim <<<" << endl;
            listaDupla.imprimirListaInicio();
            break;

        case 5:
            cout << "\n\t >>> mostrar fim ate inicio <<<" << endl;
            listaDupla.imprimirListaFim();
            break;
        default:
            cout << "\n\tencerrando..." << endl;
            break;
        }
    }

    return 0;

}