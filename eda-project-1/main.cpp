#include<iostream>
#include<locale>
#include<stdlib.h>
#include<time.h>
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

			cout << "\n******* Bem-Vindo Funcionário *******" << endl;
			cout << "1. Limpar slots" << endl;
			cout << "2. Limpar máquina" << endl;
			cout << "3. Adicionar produto" << endl;
			cout << "4. Alterar preço" << endl;
			cout << "5. Adicionar slot" << endl;
			cout << "6. Carregar moedas" << endl;
			cout << "7. Imprimir produtos" << endl;
			cout << "8. Gravar máquina" << endl;
			cout << "9. Carregar máquina" << endl;
			cout << "10. Remover trocos" << endl;
			cout << "0. Voltar" << endl;
			cout << "Digite a sua opção: " << endl;

			funcionario_opcoes(sair);
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