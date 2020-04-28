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


int numSlots; // variável global -- utilizada para atualizar o numSlots para qualquer situação
int main(int argc, char* argv[]) {

	// inicialização
	locale pt = pt.global(locale("pt-PT.UTF8"));
	srand((unsigned)time(NULL));
	int* moedas = new int[6];
	slot * maquina = new slot[100];

	// Verifica se foram passados argumentos pela linha de comandos
	if (argc>1) {
		// inicializa a máquina através dos argumentos pela linha de comandos
		string file_numslots, file_slots, file_moedas;
		file_numslots = argv[3];
		file_slots = argv[1];
		file_moedas = argv[2];
		
		numSlots = carregarMaquinanumSlots(file_numslots); // terceiro argumento é a localização de numSlots
		cout << numSlots << endl;

		carregarMaquinaMoedas(maquina, file_moedas, moedas); // segundo argumento é a localização da caixa de moedas
		imprimeFundos(moedas);

		carregarMaquinaSlots(maquina, numSlots, file_slots); // primeiro argumento é a localização do ficheiro com os slots
		imprimeMaquina(maquina, numSlots);

		cout << "** Ficheiros passados pela linha de comandos carregados com sucesso. **" << endl;
	}
	else {
		// Se não houver argumentos, criar uma nova máquina:
		// Passa todos os produtos e preços dos ficheiros para arrays.
		float* listaprecos = new float[NUM_PRECOS];
		string* listaprodutos = new string[NUM_PRODUTOS];
		lerFicheiroPrecos(listaprecos);
		lerFicheiroProdutos(listaprodutos);

		//Criar Vending Machine
		numSlots = rand() % 4 + 9;
		createVendingMachine(listaprodutos, listaprecos, maquina, numSlots);
		delete[](listaprecos);
		delete[](listaprodutos);
		cria_fundos(moedas);
	}


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
