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

void imprimeMaquina(slot* maquina, int numSlots) {
    cout << "-------- Máquina de Vending: --------\n" << endl;
    for (int i = 0; i < numSlots; i++) {
        cout << "Slot : " << maquina[i].code << endl;
        cout << "Produto : " << maquina[i].p.name << endl;
        cout << "Preço : " << maquina[i].p.preco << " " << EURO << endl;
        cout << "Quantidade : " << maquina[i].quantidade << "   | Capacidade : " << maquina[i].quantidadeMax << endl;
        cout << "---------------------------------\n" << endl;
    }
}

float precoDesteProduto(slot* maquina, int numSlots, string produto)
{
    bool jaExiste = false;
    int posExiste = -1;
    for (int i = 0; i < numSlots; i++) {
        if (maquina[i].p.name == produto) {
            jaExiste = true;
            posExiste = i;
            break;
        }
    }

    if (jaExiste) {
        return maquina[posExiste].p.preco;
    }
    else {
        float* listaprecos = new float[NUM_PRECOS];
        lerFicheiroPrecos(listaprecos);
        int posPreco = rand() % NUM_PRECOS;
        float res = listaprecos[posPreco];
        delete[](listaprecos);
        return res;
    }
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

bool temVazio(slot* maquina, int numSlots) {
    bool eVazio = false;
    for (int i = 0; i < numSlots; i++) {
        if (maquina[i].p.name == "Vazio")
            eVazio = true;
    }
    return eVazio;
}

// esta função é usada para criar uma nova máquina apenas
char inicializaCodigo(int i)
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
        break;
    }
    return c;
}

char buscaCodigo(slot* maquina, int i) {
    return maquina[i].code;
}

int buscaPos(slot* maquina, int numSlots, char c) {
    for (int i = 0; i < numSlots; i++) {
        if (maquina[i].code == c) {
            return i;
        }
    }
    return -1;
}

/* isto é o antigo buscaPos, comentado para caso de ser necessário referenciar para corrigir bugs no futuro */
//int OLD_buscaPos(char c)
//{
//    int i;
//    switch (c) {
//    case 'A':
//        i = 0;
//        break;
//    case 'B':
//        i = 1;
//        break;
//    case 'C':
//        i = 2;
//        break;
//    case 'D':
//        i = 3;
//        break;
//    case 'E':
//        i = 4;
//        break;
//    case 'F':
//        i = 5;
//        break;
//    case 'G':
//        i = 6;
//        break;
//    case 'H':
//        i = 7;
//        break;
//    case 'I':
//        i = 8;
//        break;
//    case 'J':
//        i = 9;
//        break;
//    case 'K':
//        i = 10;
//        break;
//    case 'L':
//        i = 11;
//        break;
//    default:
//        i = -1;
//        break;
//    }
//    return i;
//}

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
                posProduto = rand() % NUM_PRODUTOS;
                unico = true;
            }
        }
        maquina[i].p.name = produtos[posProduto];
        maquina[i].p.preco = precos[posPreco];
        maquina[i].code = inicializaCodigo(i);
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
