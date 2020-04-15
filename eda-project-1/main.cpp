#include <iostream>
#include <locale>
#include <stdlib.h>
#include <time.h>
#include <string>

#include "dinheiro.h"
#include "cliente.h"
#include "funcionario.h"
#include "slot.h"

using namespace std;

/* 
NOTA:
TEMOS QUE CORRIGIR OS PROBLEMAS COM O LOCALE
senão as coisas ficam feias e dificeis de ler :p
*/


int main() {
	//inicialização
	// locale pt = pt.global(locale(""));
	// locale pt = pt.global(locale("pt-PT.UTF8")); // <-- isto quase que dá, mas causa com que outros couts não consigam imprimir. não sei
	locale::global(locale(""));
	srand((unsigned)time(NULL));
	int* moedas = new int[6];

	// Para guardar todos os produtos e preços em arrays.
	float listaprecos[NUM_PRECOS];
	string listaprodutos[NUM_PRODUTOS];
	lerFicheiroPrecos(listaprecos);
	lerFicheiroProdutos(listaprodutos);

	//Criar Vending Machine
	int numSlots = rand() % 4 + 9;
	slot* maquina = new slot[numSlots];
	createVendingMachine(listaprodutos, listaprecos, maquina, numSlots);
	fundos(moedas);

	// Menu de opcoes
 	bool sair = false;
	while (!sair) {
		char utilizador;
		cout << "\n******* Bem-Vindo *******" << endl;
		cout << "Por favor introduza c para cliente ou f para o funcionário. \nIntroduza qualquer outro valor para fechar o programa." << endl;
		cin >> utilizador;

		if (utilizador == 'c') {
			menu_cliente(maquina, moedas, numSlots);
		}
		else if (utilizador == 'f') {
			menu_funcionario(maquina, moedas, numSlots);
		}
		else { 
			cout << "\nFechando programa. Adeus!\n";
			sair = true; 
		}
	}

	// Finalização do programa
	delete[](moedas);
	delete[](maquina);
	cin.sync();//manter consola aberta
	cin.get(); //manter consola aberta
	cin.ignore();

	return 0;
}
