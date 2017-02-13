#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct Numero {
    int num;
} Numero;
Numero *_numeros;

void menu();
void armazenaNumeros();
void liberaMemoria();
void listaNumeros();

int qtd_numeros;

int main(void) {
    menu();
    return 0;
}

void menu(void) {
    char escolha = ' ';

    cout << "1. Armazena números" << endl;
    cout << "2. Lista Números" << endl;
    cout << "3. Liberar Memória" << endl;
    cout << "0. SAIR" << endl;
    cout << "Digite uma opção: ";
    cin >> escolha;

    switch (escolha) {
        case '1':
            armazenaNumeros();
            break;
        case '2':
            listaNumeros();
            break;
        case '3':
            liberaMemoria();
            break;
        default:
            cout << "Opção inválida!" << endl;
    }
    menu();
}

void armazenaNumeros() {

    cout << "Digite a Quantidade de números que deseja armazenar: ";
    cin >> qtd_numeros;

    Numero *numeros;
    numeros = (Numero *) calloc(qtd_numeros, sizeof(numeros));

    Numero *numeros_realoc;
    numeros_realoc = (Numero *) realloc(numeros, qtd_numeros * sizeof(numeros_realoc));

    if((numeros || numeros_realoc) == NULL) {
        cout << "Ńão há memória suficiente." << endl;
        exit(1);
    }

    if(numeros_realoc != NULL) {
        numeros = numeros_realoc;
    }

    for (int i = 0; i < qtd_numeros; ++i) {
        cout << "Digite o " << i+1 << "º valor: ";
        cin >> numeros[i].num;
    }

    _numeros = numeros;
}

void listaNumeros() {

    for (int i = 0; i < qtd_numeros; ++i) {
        cout << "Valor da posição " << i << ": " << _numeros[i].num << endl << "---" << endl;
    }

}

void liberaMemoria() {
    free(_numeros);
}

