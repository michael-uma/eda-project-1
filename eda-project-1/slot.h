#pragma once
#include <string>
#define EURO "euros"
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

void imprimeMaquina(slot* maquina, int numSlots);

bool slotVazio(slot slot);


void VerificarVazio(slot* maquina, int numSlots);


char buscaCodigo(int i);

int buscaPos(char c);

void createVendingMachine(string* produtos, float* precos, slot* maquina, int numSlots);


