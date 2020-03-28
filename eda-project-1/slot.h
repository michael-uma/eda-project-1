#pragma once
#include <string>
using namespace std;

#define NUM_PRODUTOS 24
#define NUM_PRECOS 10

struct produto {
	string name;
	float preco;
};

struct slot {
	produto p;
	int quantidade;
	int quantidadeMax;
	char code;
};

void lerFicheiroProdutos(string* listaprodutos);

void lerFicheiroPrecos(float* listaprecos);

char buscaCodigo(int i);

void createVendingMachine(string* produtos, float* precos);