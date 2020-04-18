#include "slot.h"
#include <iostream>
#include <fstream>

void lerFicheiroProdutos(string* listaprodutos) {
    ifstream myFile("produtos.txt");
    string line = "";
    int i = 0;
    if (myFile.is_open()) {  //verificar se o ficheiro existe
        while (getline(myFile, line)) {
            listaprodutos[i] = line;
            i++;
        }
    }
    myFile.close();
    /*for (int j = 0; j < NUM_PRODUTOS; j++) {
        cout << listaprodutos[j] << endl;
    }*/
}

void lerFicheiroPrecos(float* listaprecos) {
    ifstream myFile("precos.txt");
    string line = "";
    int i = 0;
    if (myFile.is_open()) {  //verificar se o ficheiro existe
        while (getline(myFile, line)) {
            listaprecos[i] = stof(line);
            i++;
        }
    }
    myFile.close();
    /*for (int j = 0; j < NUM_PRECOS; j++) {
        cout << listaprecos[j] << endl;
    }*/
}

bool slotVazio(slot slot) 
{
    return (slot.quantidade == 0);
}

void VerificarVazio(slot* maquina, int numSlots) {
    for (int i = 0; i < numSlots; i++) {
        if (slotVazio(maquina[i])) {
            maquina[i].p.name = "Vazio";
            maquina[i].p.preco = 0.00;
        }
    }
}

char buscaCodigo(int i)
{
    char c;
    switch (i) {
    case 0:
        c = 'A';
        break;
    case 1:
        c = 'B';
        break;
    case 2:
        c = 'C';
        break;
    case 3:
        c = 'D';
        break;
    case 4:
        c = 'E';
        break;
    case 5:
        c = 'F';
        break;
    case 6:
        c = 'G';
        break;
    case 7:
        c = 'H';
        break;
    case 8:
        c = 'I';
        break;
    case 9:
        c = 'J';
        break;
    case 10:
        c = 'K';
        break;
    case 11:
        c = 'L';
        break;
    default:
        c = 'X';
        break;
    }
    return c;
}

int buscaPos(char c)
{
    int i;
    switch (c) {
    case 'A':
        i = 0;
        break;
    case 'B':
        i = 1;
        break;
    case 'C':
        i = 2;
        break;
    case 'D':
        i = 3;
        break;
    case 'E':
        i = 4;
        break;
    case 'F':
        i = 5;
        break;
    case 'G':
        i = 6;
        break;
    case 'H':
        i = 7;
        break;
    case 'I':
        i = 8;
        break;
    case 'J':
        i = 9;
        break;
    case 'K':
        i = 10;
        break;
    case 'L':
        i = 11;
        break;
    default:
        i = 100;
        break;
    }
    return i;
}

void createVendingMachine(string* produtos, float* precos, slot* maquina, int numSlots)
{
    int qProdutosMax, posProduto, posPreco;

    for (int i = 0; i < numSlots; i++) {

        qProdutosMax = rand() % 6 + 5;
        posPreco = rand() % NUM_PRECOS;
        posProduto = rand() % NUM_PRODUTOS;

        // Verificar se o produto escolhido já está noutro slot da máquina:

        bool unico = true;
        while (unico) {
            for (int j = 0; j < i; j++)
            {
                if (maquina[j].p.name == produtos[posProduto]) {
                    unico = false;
                }
            }

            if (unico) {
                break;
            }

            if (!unico) {
                // cout << "### produto alterado de " << produtos[posProduto] << " ###" << endl; // para testar
                posProduto = rand() % NUM_PRODUTOS;
                // cout << "### produto alterado para " << produtos[posProduto] << " ###" << endl; // para testar
                unico = true;
            }
        }

        maquina[i].p.name = produtos[posProduto];
        maquina[i].p.preco = precos[posPreco];
        maquina[i].code = buscaCodigo(i);
        maquina[i].quantidadeMax = qProdutosMax;
        maquina[i].quantidade = maquina[i].quantidadeMax;
    }

    cout << "-------- Máquina de Vending: --------\n" << endl;
    // Output da máquina:
    for (int i = 0; i < numSlots; i++) {
        cout << "Slot : " << maquina[i].code << endl;
        cout << "Produto : " << maquina[i].p.name << endl;
        cout << "Preço : " << maquina[i].p.preco << " " << EURO << endl;
        cout << "Quantidade : " << maquina[i].quantidade << "   | Capacidade : " << maquina[i].quantidadeMax << endl;
        cout << "------------------------------\n" << endl;
    }
}
