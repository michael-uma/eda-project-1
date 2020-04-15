#include "cliente.h"
#include "slot.h"
#include "dinheiro.h"
#include "funcionario.h"
#include <iostream>
using namespace std;

void menu_cliente(slot* maquina, int moedas[6], int numSlots) {

	verificarFundos(moedas);
	char escolha_utilizador;
	cout << "\n******* Bem-Vindo Cliente *******" << endl;
	cout << "Introduza o código do produto: ";
	cin >> escolha_utilizador;
	bool sair = false;
	while (!sair ||  (0 <= buscaPos(escolha_utilizador) && buscaPos(escolha_utilizador) < numSlots)) {
		int pos_escolha = buscaPos(escolha_utilizador);
		if (pos_escolha > numSlots-1) {
			cout << "Por favor digite o código válido!";
			//cout << numSlots << endl;
			cin >> escolha_utilizador;
		}
		else {
			cout << "Escolheu : " << maquina[pos_escolha].p.name << endl;
			//cout << numSlots << endl;
			string tiposMoedas[6] = { "2 euros", "1 euro", "50 centimos", "20 centimos", "10 centimos", "5 centimos" };
			int* quantMoedas = new int[6];

			for (int i = 0; i < 6; i++) {
				cout << "Introduza a quantidade de moedas de " << tiposMoedas[i] << ":";
				cin >> quantMoedas[i];
			}
			int custocliente = quantMoedas[0] * 2 + quantMoedas[1] * 1 + quantMoedas[2] * 0.50 + quantMoedas[3] * 0.20 + quantMoedas[4] * 0.10 + quantMoedas[5] * 0.05;
			if (custocliente < maquina[pos_escolha].p.preco) {
				cout << "Produto nao devolvido! Troco devolvido!" << endl;
			}
			else
			{
				cout << "Produto devolvido! Obrigado!" << endl;
				float restomoedas = custocliente - maquina[pos_escolha].p.preco;
				cout << "TROCO: " << restomoedas << endl;

			}
			break;
		}
	}
}
