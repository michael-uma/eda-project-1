#pragma once
#include <string>
using namespace std;

#define NUM_PRODUTOS 24
#define NUM_PRECOS 10

struct produto {
	string name;
	float price;
};

struct slot {
	produto p;
	int quantity;
	char code;
};

string* lerFicheiroProdutos();

float* lerFicheiroPrecos();

slot createSlot(string* produtos, float* precos, int numSlots);