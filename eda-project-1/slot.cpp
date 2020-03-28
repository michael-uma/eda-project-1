#include "slot.h"
#include <iostream>
#include <fstream>

string* lerFicheiroProdutos() {
    string listaprodutos[24];
    ifstream myFile("produtos.txt");
    string line = "";
    int i = 0;
    if (myFile.is_open()) { //verificar se o ficheiro existe
        while (getline(myFile, line)) {
            listaprodutos[i] = line;
            i++;
        }
    }
    myFile.close();
    for (int j = 0; j <= 23; j++) {
        cout << listaprodutos[j] << endl;
    }
    return listaprodutos;
}
