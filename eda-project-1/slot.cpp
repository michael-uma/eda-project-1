#include "slot.h"
#include <iostream>
#include <fstream>

void leProduto(string caminhoProdutos, string caminhoPrecos, int tamanho)
{
	produto* p = new produto;
	string* produtos = new string[tamanho];
	float* precos = new float[tamanho];

	ifstream file_produtos(caminhoProdutos);
	ifstream file_precos(caminhoPrecos);

	while (file_produtos.good())
	{
		cout << getline(file_produtos);
	}

	while (file_precos.good())
	{

	}

	

	file_produtos.close();
	file_precos.close();
}
