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

UPDATE:
possivelmente corrigido? teremos que testar um pouco mais só para ter certeza
*/

int numSlots; // variável global -- utilizada para atualizar o numSlots para qualquer situação
int main() {
	// inicialização
	locale pt = pt.global(locale("pt-PT.UTF8"));
	srand((unsigned)time(NULL));
	int* moedas = new int[6];

	// Para guardar todos os produtos e preços em arrays.
	float listaprecos[NUM_PRECOS];
	string listaprodutos[NUM_PRODUTOS];
	lerFicheiroPrecos(listaprecos);
	lerFicheiroProdutos(listaprodutos);

	//Criar Vending Machine
	numSlots = rand() % 4 + 9;
	slot* maquina = new slot[100];
	createVendingMachine(listaprodutos, listaprecos, maquina, numSlots);
	cria_fundos(moedas);

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
