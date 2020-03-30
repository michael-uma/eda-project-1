#include <iostream>
#include<stdlib.h>
#include<time.h>
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
	if (moedas[0] <= 3 || moedas[1] <= 3 || moedas[2] <= 3 || moedas[3] <= 3 || moedas[4] <= 3 || moedas[5] <= 3) { //Este if para dizer apenas uma vez o ***AVISO***
		cout << "******AVISO******" << endl;
		if (moedas[0] <= 3) {
			cout << "Existem apenas " << moedas[0] << " moedas de 2 euros" << endl;
		}
		else if (moedas[1] <= 3) {
			cout << "Existem apenas " << moedas[1] << " moedas de 1 euros" << endl;
		}
		else if (moedas[2] <= 3) {
			cout << "Existem apenas " << moedas[2] << " moedas de 50 centemos " << endl;
		}
		else if (moedas[3] <= 3) {
			cout << "Existem apenas " << moedas[3] << " moedas de 20 centemos" << endl;
		}
		else if (moedas[4] <= 3) {
			cout << "Existem apenas " << moedas[4] << " moedas de 10 centemos" << endl;
		}
		else if (moedas[5] <= 3) {
			cout << "Existem apenas " << moedas[5] << " moedas de 5 centemos" << endl;
		}
	}
	/*cout << "***Antes***" << endl;
	cout << "2 ->" << moedas[0] << endl;
	cout << "1-> " << moedas[1] << endl;
	cout << "0.5 ->" << moedas[2] << endl;
	cout << "0.2-> " << moedas[3] << endl;
	cout << "0.1-> " << moedas[4] << endl;
	cout << "0.05-> " << moedas[5] << endl; //teste!!!*/
}

	void remover_fundos(int moedas[6])
	{

		int remover;
		cout << "***Remover Fundos***"<<endl;
		for (int i = 0; i < 6; i++) {
			cout << "Quanto moedas euros deseja remover? "<<endl;
			cin >> remover;
			while(moedas[i] - remover < 0){
				//if (moedas[i] - remover < 0) {
				cout << "O numero de moedas sera negativo!!!! por favor digite outra vez o numero de moedas que pretende retirar: ";
				cin >> remover;
				}
			moedas[i] = moedas[i] - remover;
		}

		cout << "***Fundos***" << endl;
		cout << "2 euros ->" << moedas[0] << endl;
		cout << "1 euros-> " << moedas[1] << endl;
		cout << "50 centemos->" << moedas[2] << endl;
		cout << "20 centemos-> " << moedas[3] << endl;
		cout << "10 centemos -> " << moedas[4] << endl;
		cout << "5 centemos-> " << moedas[5] << endl;
		cout << endl;

	}
