#include <iostream>
#include <locale>
#include <stdlib.h>
#include <time.h>
#include "dinheiro.h"
#include "funcionario.h"
using namespace std;



void fundos(int moedas[6])
{
	moedas[0] = rand() % 11 + 10; //de 10 a 20
	moedas[1] = rand() % 11 + 10; //de 10 a 20
	moedas[2] = rand() % 11 + 10; //de 10 a 20
	moedas[3] = rand() % 11 + 10; //de 10 a 20
	moedas[4] = rand() % 11 + 10; //de 10 a 20
	moedas[5] = rand() % 11 + 10; //de 10 a 20

	verificarFundos(moedas);

	/*cout << "***Antes***" << endl;
	cout << "2 ->" << moedas[0] << endl;
	cout << "1-> " << moedas[1] << endl;
	cout << "0.5 ->" << moedas[2] << endl;
	cout << "0.2-> " << moedas[3] << endl;
	cout << "0.1-> " << moedas[4] << endl;
	cout << "0.05-> " << moedas[5] << endl; //teste!!!*/
}

void verificarFundos(int moedas[6])
{
	if (moedas[0] <= 3 || moedas[1] <= 3 || moedas[2] <= 3 || moedas[3] <= 3 || moedas[4] <= 3 || moedas[5] <= 3) { //Este if para dizer apenas uma vez o ***AVISO***
		cout << "******AVISO******\nExistem apenas:" << endl;
		if (moedas[0] <= 3) {
			cout << moedas[0] << " moedas de 2 euros." << endl;
		}
		if (moedas[1] <= 3) {
			cout << moedas[1] << " moedas de 1 euros." << endl;
		}
		if (moedas[2] <= 3) {
			cout << moedas[2] << " moedas de 50 cêntimos." << endl;
		}
		if (moedas[3] <= 3) {
			cout << moedas[3] << " moedas de 20 cêntimos." << endl;
		}
		if (moedas[4] <= 3) {
			cout << moedas[4] << " moedas de 10 cêntimos." << endl;
		}
		if (moedas[5] <= 3) {
			cout << moedas[5] << " moedas de 5 cêntimos." << endl;
		}
	}
}

	void remover_fundos(int moedas[6])
	{
		int remover;
		cout << "***Remover Fundos***"<<endl;
		for (int i = 0; i < 6; i++) {
			cout << "Quantas moedas de ";
			switch (i) {
			case 0:
				cout << "2 euros";
				break;
			case 1:
				cout << "1 euro";
				break;
			case 2:
				cout << "50 cêntimos";
				break;
			case 3:
				cout << "20 cêntimos";
				break;
			case 4:
				cout << "10 cêntimos";
				break;
			case 5:
				cout << "5 cêntimos";
				break;
			default:
				break;
			}
			cout << " deseja remover?"<< endl;
			cin >> remover;
			
			while(moedas[i] - remover < 0)
			{
				cout << "O numero de moedas sera negativo/inválido! Por favor digite outra vez o numero de moedas que pretende retirar: ";
				cin >> remover;
			}
			moedas[i] = moedas[i] - remover;
		}

		cout << "*** Fundos ***" << endl;
		cout << "2 euros ->" << moedas[0] << endl;
		cout << "1 euros-> " << moedas[1] << endl;
		cout << "50 cêntimos->" << moedas[2] << endl;
		cout << "20 cêntimos-> " << moedas[3] << endl;
		cout << "10 cêntimos -> " << moedas[4] << endl;
		cout << "5 cêntimos-> " << moedas[5] << endl;
		cout << endl;

	}


	void carregar_moedas(int moedas[6]) {
		int adicionar = -1;
		cout << "*** Carregar moedas ***" << endl;
		for (int j = 0; j < 6; j++) {
			if (j == 0) {
				cout << "Quantas moedas de 2 euros deseja adicionar: " << endl;
				cin >> adicionar;
				moedas[0] = moedas[0] + adicionar;
			}
			else if (j == 1) {
				cout << "Quantas moedas de 1 euro deseja adicionar: " << endl;
				cin >> adicionar;
				moedas[1] = moedas[1] + adicionar;
			}
			else if (j == 2) {
				cout << "Quantas moedas de 50 cêntimos deseja adicionar: " << endl;
				cin >> adicionar;
				moedas[2] = moedas[2] + adicionar;
			}
			else if (j == 3) {
				cout << "Quantas moedas de 20 cêntimos deseja adicionar: " << endl;
				cin >> adicionar;
				moedas[3] = moedas[3] + adicionar;
			}
			else if (j == 4) {
				cout << "Quantas moedas de 10 cêntimos deseja adicionar: " << endl;
				cin >> adicionar;
				moedas[4] = moedas[4] + adicionar;
			}
			else if (j == 5) {
				cout << "Quantas moedas de 5 cêntimos deseja adicionar: " << endl;
				cin >> adicionar;
				moedas[5] = moedas[5] + adicionar;
			}
			// verificar se o valor inserido foi positivo
			if (adicionar < 0) {
				cout << "Insira um valor positivo valor positivo!: " << endl;
				j--;
			}
		}
		cout << "** Moedas carregadas com sucesso **";
		verificarFundos(moedas);
	}
