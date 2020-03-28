#include "funcionario.h"
#include<iostream>
using namespace std;

void funcionario_opcoes(bool sair)
{
	if (!sair) {
		int escolha_funcionario;
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
			//Qualquer coisa para carregar moedas;
		}
		else if (escolha_funcionario == 7) {
			cout << "Escolheu imprimir produtos! " << endl;
			//Qualquer coisa para imprimir produtos;
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
			//Qualquer coisa para remover trocos;
		}
		else if (escolha_funcionario == 0) {
			cout << "Escolheu Voltar! " << endl;
			sair = true;
		}
		else
			cout << "Por favor digite uma opção válida!";
			funcionario_opcoes(sair);
	}
}