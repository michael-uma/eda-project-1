#include "slot.h"
#include <iostream>
#include <fstream>

string* lerFicheiroProdutos() {
    string listaprodutos[NUM_PRODUTOS];
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
    for (int j = 0; j < NUM_PRODUTOS; j++) {
        cout << listaprodutos[j] << endl;
    }
    return listaprodutos;
}

float* lerFicheiroPrecos() {
    float listaprecos[NUM_PRECOS];
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
    for (int j = 0; j < NUM_PRECOS; j++) {
        cout << listaprecos[j] << endl;
    }
    return listaprecos;
}
