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

float precoDesteProduto(slot* maquina, int numSlots, string produto);

bool slotVazio(slot slot);
void VerificarVazio(slot* maquina, int numSlots);
bool temVazio(slot* maquina, int numSlots);

char inicializaCodigo(int i);

char buscaCodigo(slot* maquina, int i);
int buscaPos(slot* maquina, int numSlots, char c);

void createVendingMachine(string* produtos, float* precos, slot* maquina, int numSlots);


