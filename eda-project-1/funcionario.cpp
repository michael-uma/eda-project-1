#include "funcionario.h"
#include "dinheiro.h"
#include "slot.h"
#include <algorithm>
#include <locale>
#include<iostream>
using namespace std;


void imprimir_produtos(slot* maquina, int numSlots)
{
	cout << "	1.  Por ordem alfabética" << endl;
	cout << "	2.  Por preço" << endl;
	cout << "	3.  Por quantidade disponível" << endl;
	cout << "Escolha a sua opção: ";
	int opcao;
	cin >> opcao;
	cout << endl;

	// variáveis e arrays usados no sort
	float* precos = new float[numSlots];
	string* produtos = new string[numSlots];
	int* quantidades = new int[numSlots];
	float a1, b1; 
	string a2, b2;
	int a3, b3;

	for (int i = 0; i < numSlots; i++) {
		precos[i] = maquina[i].p.preco;
		produtos[i] = maquina[i].p.name;
		quantidades[i] = maquina[i].quantidade;
	}

	switch (opcao) {
	case 1:
		sort(produtos, produtos + numSlots);
		break;
	case 2:
		for (int i = 1; i < numSlots; i++) {
			for (int j = 0; j < i; j++) {
				if (precos[i] < precos[j]) {
					a1 = precos[j];
					a2 = produtos[j];
					b1 = precos[i];
					b2 = produtos[i];
					precos[j] = b1;
					produtos[j] = b2;
					precos[i] = a1;
					produtos[i] = a2;
				}
			}
		}
		break;
	case 3:
		for (int i = 1; i < numSlots; i++) {
			for (int j = 0; j < i; j++) {
				if (quantidades[i] < quantidades[j]) {
					a3 = quantidades[j];
					a2 = produtos[j];
					b3 = quantidades[i];
					b2 = produtos[i];
					quantidades[j] = b3;
					produtos[j] = b2;
					quantidades[i] = a3;
					produtos[i] = a2;
				}
			}
		}
		break;
	default:
		cout << "Escolheu uma opção inválida. Voltando para o menu anterior." << endl;
		break;
	}

	// Print da lista ordenada
	if (opcao == 1 || opcao == 2 || opcao == 3) {
		for (int i = 0; i < numSlots; i++) {
			cout << produtos[i] << endl;
			// cout << precos[i] << endl;
			// cout << quantidades[i] << endl;
		}
	}

	delete[](produtos);
	delete[](precos);
	delete[](quantidades);
	cout << endl;
}


void menu_funcionario(slot* maquina,int moedas[6], int numSlots) //Por favor vejam se altera alguns codigos!!! PQ ADICIONEI OUTRO ARGUMENTO!!!!
{
	bool sair = false;
	while (!sair) {
		int escolha_funcionario;
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

		cin >> escolha_funcionario;

		if (escolha_funcionario == 1) {
			cout << "Escolheu limpar os slots! " << endl;
			//Qualquer coisa para limpar stock;
		}
		else if (escolha_funcionario == 2) {
			cout << "Escolheu limpar a máquina! " << endl;
			//Qualquer coisa para limpar máquina;
		}
		else if (escolha_funcionario == 3) {
			cout << "Escolheu adicionar produto! " << endl;
			//Qualquer coisa para adicionar produto;
		}
		else if (escolha_funcionario == 4) {
			cout << "Escolheu alterar preço(s)! " << endl;
			//Qualquer coisa para alterar preço(s);
		}
		else if (escolha_funcionario == 5) {
			cout << "Escolheu adicionar slots! " << endl;
			//Qualquer coisa para adicionar slots;
		}
		else if (escolha_funcionario == 6) {
			cout << "Escolheu carregar moedas! " << endl;
			carregar_moedas(moedas);
		}
		else if (escolha_funcionario == 7) {
			cout << "Escolheu imprimir produtos! " << endl;
			imprimir_produtos(maquina, numSlots);
		}
		else if (escolha_funcionario == 8) {
			cout << "Escolheu gravar máquina" << endl;
			//Qualquer coisa para gravar máquina;
		}
		else if (escolha_funcionario == 9) {
			cout << "Escolheu carregar máquina! " << endl;
			//Qualquer coisa para carregar máquina;
		}
		else if (escolha_funcionario == 10) {
			cout << "Escolheu remover os trocos! " << endl;
			remover_fundos(moedas);
		}
		else if (escolha_funcionario == 0) {
			cout << "Escolheu Voltar! " << endl;
			sair = true;
		}
		else
			cout << "Por favor digite uma opção válida!";
	}
}
