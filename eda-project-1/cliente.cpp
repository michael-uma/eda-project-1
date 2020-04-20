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
	while (!sair || (0 <= buscaPos(maquina, numSlots, escolha_utilizador) && buscaPos(maquina, numSlots, escolha_utilizador) < numSlots) ) {
		int pos_escolha = buscaPos(maquina, numSlots, escolha_utilizador);
		if (pos_escolha > numSlots-1 || pos_escolha < 0) {
			cout << "Por favor digite o código válido!" << endl;
			//cout << numSlots << endl;
			cin >> escolha_utilizador;
		}
		else {
			cout << "Escolheu : " << maquina[pos_escolha].p.name << endl;
			//cout << numSlots << endl;
			string tiposMoedas[6] = { "2 euros", "1 euro", "50 cêntimos", "20 cêntimos", "10 cêntimos", "5 cêntimos" };
			int* quantMoedas = new int[6];

			for (int i = 0; i < 6; i++) {
				cout << "Introduza a quantidade de moedas de " << tiposMoedas[i] << ":";
				cin >> quantMoedas[i];
			}
			double custocliente = (double) quantMoedas[0] * 2 + quantMoedas[1] * 1 + quantMoedas[2] * 0.50 + quantMoedas[3] * 0.20 + quantMoedas[4] * 0.10 + quantMoedas[5] * 0.05;
			if (custocliente < maquina[pos_escolha].p.preco) {
				cout << "\nProduto não devolvido! Troco devolvido!" << endl;
			}
			else if (maquina[pos_escolha].quantidade == 0) {
				cout << "Slot Vazio! Troco devolvido!" << endl;
			}
			else if (VerificarAviso(moedas)) {
				cout << "De momento a máquina tem poucas moedas! Produto não devolvido! Troco devolvido!" << endl;
			}
			else
			{
				maquina[pos_escolha].quantidade -= 1;
				cout << "\nProduto devolvido! Obrigado!" << endl;
				double restomoedas = custocliente - maquina[pos_escolha].p.preco;
				//cout << "TROCO: " << restomoedas << endl;
				moedas[0] = moedas[0] + quantMoedas[0];
				moedas[1] = moedas[1] + quantMoedas[1];
				moedas[2] = moedas[2] + quantMoedas[2];
				moedas[3] = moedas[3] + quantMoedas[3];
				moedas[4] = moedas[4] + quantMoedas[4];
				moedas[5] = moedas[5] + quantMoedas[5];
				int a = moedas[0];
				int b = moedas[1];
				int c = moedas[2];
				int d = moedas[3];
				int e = moedas[4];
				int f = moedas[5];
				if (restomoedas > 0.00) {
					while (restomoedas >= 2.00) {
						moedas[0] = moedas[0] - 1;
						restomoedas -= 2.00;
					}
					while (restomoedas >= 1.00) {
						moedas[1] = moedas[1] - 1;
						restomoedas -= 1.00;
					}
					while (restomoedas >= 0.5) {
						moedas[2] = moedas[2] - 1;
						restomoedas -= 0.50;
					}
					while (restomoedas >= 0.2) {
						moedas[3] = moedas[3] - 1;
						restomoedas -= 0.2;
					}
					while (restomoedas >= 0.1) {
						moedas[4] = moedas[4] - 1;
						restomoedas -= 0.1;
					}
					while (restomoedas >= 0.05) {
						moedas[5] = moedas[5] - 1;
						restomoedas -= 0.05;
					}
				}
				cout << "\n**TROCO**" << endl;
				cout << "2 euros: " << a - moedas[0] << " | ";
				cout << "1 euro: " << b - moedas[1] << " | ";
				cout << "50 cêntimos: " << c - moedas[2] << " | ";
				cout << "20 cêntimos: " << d - moedas[3] << " | ";
				cout << "10 cêntimos: " << e - moedas[4] << " | ";
				cout << "5 cêntimos: " << f - moedas[5] << endl;
				imprimeFundos(moedas);
				verificarFundos(moedas);
			}
			cout << "Pressione qualquer tecla para continuar.\n";
			cin.get();
			VerificarVazio(maquina, numSlots);
			imprimeMaquina(maquina, numSlots);
			break;
		}
	}
}
