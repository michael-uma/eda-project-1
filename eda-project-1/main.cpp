#include <iostream>
#include <locale>
#include <stdlib.h>
#include <time.h>
#include <string>

#include "cliente.h"
#include "funcionario.h"
#include "slot.h"

using namespace std;

int main() {
	//inicialização
	locale pt = pt.global(locale(""));
	srand((unsigned)time(NULL));

	// Para guardar todos os produtos e preços em arrays.
	float listaprecos[NUM_PRECOS];
	string listaprodutos[NUM_PRODUTOS];
	lerFicheiroPrecos(listaprecos);
	lerFicheiroProdutos(listaprodutos);

	//Criar Vending Machine
	int numSlots = rand() % 4 + 9;
	slot* maquina = new slot[numSlots];
	createVendingMachine(listaprodutos, listaprecos, maquina, numSlots);

	// Menu de opcoes
 	bool sair = false;
	while (!sair) {

		char utilizador;
		cout << "\n******* Bem-Vindo *******" << endl;
		cout << "Por favor introduza c para cliente ou f para o funcionário. Introduza qualquer outro valor para fechar o programa." << endl;
		cin >> utilizador;

		if (utilizador == 'c') {
			menu_cliente(maquina);
		}
		else if (utilizador == 'f') {
			menu_funcionario(sair);
		}
		else { 
			cout << "\nFechando programa. Adeus!\n";
			sair = true; 
		}
	}

	cin.sync();//manter consola aberta
	cin.get(); //manter consola aberta
	cin.ignore();

	return 0;
}