#include "cliente.h"
#include "slot.h"
#include "dinheiro.h"
#include <iostream>
using namespace std;


void menu_cliente(slot* maquina, int moedas[6]) {

	verificarFundos(moedas);

	char escolha_utilizador;
	cout << "\n******* Bem-Vindo Cliente *******" << endl;
	cout << "Introduza o código do produto: ";
	cin >> escolha_utilizador;
	int pos_escolha = buscaPos(escolha_utilizador);

	cout << "Escolheu : " << maquina[pos_escolha].p.name << endl;

	string tiposMoedas[6] = {"2 euros", "1 euro", "50 centimos", "20 centimos", "10 centimos", "5 centimos" };
	int* quantMoedas = new int[6];

	for (int i = 0; i < 6; i++) {
		cout << "Introduza a quantidade de moedas de " << tiposMoedas[i] << ":";
		cin >> quantMoedas[i];
	}
}